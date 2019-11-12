// treesort.h  SKELETON
// Glenn G. Chappell
// 2019-11-10
//
// For CS 311 Fall 2019
// Header for function template treesort
// There is no associated source file.

#ifndef FILE_TREESORT_H_INCLUDED
#define FILE_TREESORT_H_INCLUDED

#include <iterator>
// For std::iterator_traits
#include <algorithm>
// For std::stable_sort, std::move
#include <vector>
// For std::vector
#include <iterator>
// For std::distance
#include <memory>
// For std::unique_ptr

template<typename ValType>
struct Node 
{ 
    ValType _key; 
    std::unique_ptr<Node> _left;
    std::unique_ptr<Node> _right; 

    explicit Node(const ValType & key,
                std::unique_ptr<Node> & left = nullptr,
                std::unique_ptr<Node> & right = nullptr)
        :_key(key),
        _left(std::move(left)),
        _right(std::move(right))
    {}

    ~Node() = default;
}; 



// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // ValType is the type that FDIter points to
    using ValType = typename std::iterator_traits<FDIter>::value_type;
    std::vector<ValType> buff(std::distance(first, last));
    std::vector<ValType> buffer;
    std::move(first, last, buff.begin());
    std::unique_ptr<Node<ValType>> root = nullptr;
    root = std::move(insert(root,buff[0]));
    for(auto i = 1; i < buff.size(); i++)
    {
        insert(root,buff[i]);
    }
    traverse(root,buffer);
    std::move(buffer.begin(), buffer.end(), first);
}


template<typename ValType>
 std::unique_ptr<Node<ValType>> & insert(std::unique_ptr<Node<ValType>> & node, ValType & key)
{
    if (node == nullptr)
    {
        node->_key = key;
        return node;
    } 
  
    /* Otherwise, recur down the tree */
    if (key < node->_key) 
    {
        node->_left = std::move(insert(node->_left, key)); 
    }
    else 
    {
        node->_right = std::move(insert(node->_right, key)); 
  
    }
    return node; 
}

template<typename ValType>
void traverse(std::unique_ptr<Node<ValType>> & root, std::vector<ValType> & buffer)
{
    if (root != NULL) 
    { 
        traverse(root->_left, buffer); 
        buffer.push_back(root->_key); 
        traverse(root->_right, buffer); 
    } 
}



#endif //#ifndef FILE_TREESORT_H_INCLUDED


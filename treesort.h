// treesort.h  SKELETON
// Matt Perry
// Tailon Russell
// Started: 11-10-2019
// Finished:
//
// Template supplied by Glenn G. Chappell 
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
    std::unique_ptr<Node<ValType>> _left;
    std::unique_ptr<Node<ValType>> _right; 

    explicit Node(const ValType & key): _key(key)
    {}

    ~Node() = default;
}; 

template<typename ValType>
std::unique_ptr<Node<ValType>> newNode(const ValType & key)
{
	auto newN = std::make_unique<Node<ValType>>(key);
	return newN;
}


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
    std::vector<ValType> endResult;
    std::unique_ptr<Node<ValType>> root;
    for (auto i = first; i != last; i++)
    {
        insert(root, *i);
    }
    traverse(root, endResult);
    std::move(endResult.begin(), endResult.end(), first);
}


template<typename ValType>
 void insert(std::unique_ptr<Node<ValType>> & node, ValType & key)
{
    if (node == nullptr)
    {
        node = newNode(key);
    }   
    /* Otherwise, recur down the tree */
    else if (key < node->_key) 
    {
        insert(node->_left, key); 
    }
    else
    {
        insert(node->_right, key); 
    }

}

template<typename ValType>
void traverse(std::unique_ptr<Node<ValType>> & root, std::vector<ValType> & endResult)
{
    if (root != nullptr) 
    { 
        traverse(root->_left, endResult); 
        endResult.push_back(root->_key); 
        traverse(root->_right, endResult); 
    } 
}



#endif //#ifndef FILE_TREESORT_H_INCLUDED


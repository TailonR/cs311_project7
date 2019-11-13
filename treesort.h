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


//Struct for a basic Binary Search Tree
// 
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

// treesort
// DESC: Sort a given range using Treesort.
// PRE:
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
    std::unique_ptr<Node<ValType>> root;
    for (auto i = first; i != last; i++)
    {
        insert(root, *i);
    }
    traverse(root,first);
}

// Insert
// DESC: Inserts a key into a binary search tree
// PRE:
// ERROR:
template<typename ValType>
 void insert(std::unique_ptr<Node<ValType>> & node, const ValType & key)
{
    if (node == nullptr)
    {
        node = std::make_unique<Node<ValType>>(key);
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

// Taverse
// DESC: Does an inorder traverse of a binary search tree. 
// PRE: Root must be the root of a valid binary search tree. First must be a valid forward iterator
// ERROR: 

template<typename ValType,typename FDIter>
void traverse(std::unique_ptr<Node<ValType>> & root, FDIter & first)
{
    if (root != nullptr) 
    { 
        traverse(root->_left, first); 
        *first++ = root->_key;
        traverse(root->_right, first); 
    } 
}



#endif //#ifndef FILE_TREESORT_H_INCLUDED


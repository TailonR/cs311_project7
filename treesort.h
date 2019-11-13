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

#include <iostream>

template<typename ValType>
struct Node 
{ 
    ValType _key; 
    std::unique_ptr<Node<ValType>> _left;
    std::unique_ptr<Node<ValType>> _right; 

    explicit Node(const ValType & key): _key(key) //,
                //std::unique_ptr<Node<ValType>> & left = nullptr,
                //std::unique_ptr<Node<ValType>> & right = nullptr)
        //:_key(key),
        //_left(std::move(left)),
       // _right(std::move(right))
    {}

    ~Node() = default;
}; 

template<typename ValType>
std::unique_ptr<Node<ValType>> & newNode(ValType key)
{
	//std::unique_ptr<Node<ValType>> newN(key);
	auto newN = std::make_unique<Node<ValType>>(key);
	//newN->_key = key;
	//newN->_left = nullptr;
	//newN->_right = nullptr;
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
    std::vector<ValType> range(std::distance(first, last));
    std::vector<ValType> endResult;
    std::move(first, last, range.begin());
    std::unique_ptr<Node<ValType>> root = nullptr;
	if (range.size() == 0)
	{
		
	}
	else
	{
		std::move(insert(root, range[0]));
		for (auto i = 1; i < range.size(); i++)
		{
			insert(root, range[i]);
		}
		traverse(root, endResult);
		std::move(endResult.begin(), endResult.end(), first);
	}
}


template<typename ValType>
 std::unique_ptr<Node<ValType>> & insert(std::unique_ptr<Node<ValType>> & node, ValType & key)
{
    if (node == nullptr)
    {
		//node->_key = key;
		//return node;
		return newNode(key);
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


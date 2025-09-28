/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This struct is a base node for use in the Binary Tree data structure.
 *
 */

#ifndef BINNODE_H
#define BINNODE_H

template <typename TYPE>
struct BinNode
{
	private:
		TYPE data;
		BinNode<TYPE>* left;
		BinNode<TYPE>* right;

	public:
		BinNode();
		BinNode(const TYPE & d, BinNode<TYPE>* l = nullptr, BinNode<TYPE>* r = nullptr);
};

/**
* Construct the BinNode with null values.
*/
template <typename TYPE>
BinNode<TYPE>::BinNode()
{
	data = 0;
	left = nullptr;
	right = nullptr;
}

/**
* Construct the BinNode with user defined values.
* 
* @param d The data to be entered into the node.
* @param l Pointer to the left node.
* @param r Pointer to the right node.
*/
template <typename TYPE>
BinNode<TYPE>::BinNode(const TYPE& d, BinNode<TYPE>* l, BinNode<TYPE>* r)
{
	data = d;
	left = l;
	right = r;
}

#endif
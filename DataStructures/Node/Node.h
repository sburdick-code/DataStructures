/*
 * This file is part of DataStructures.sln.
 * Developed for educational purposes.
 * This program is free software: you can redistribute it and/or modify it.
 *
 * This program is used to create a Node Struct for use in other data 
 * structures.
 *
 */

#ifndef NODE_H
#define NODE_H

template <typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE>* next;
	Node<TYPE>* prev;

	Node();
	Node(const TYPE& d, Node<TYPE>* n = nullptr, Node<TYPE>* p = nullptr);
};

/**
* Construct the Node with null values.
*/
template <typename TYPE>
Node<TYPE>::Node()
{
	data = 0;
	next = nullptr;
}

/**
* Construct the BinNode with user defined values.
*
* @param d The data to be entered into the node.
* @param n Pointer to the next node.
* @param p Pointer to the previous node.
*/
template <typename TYPE>
Node<TYPE>::Node(const TYPE & d, Node<TYPE>* n, Node<TYPE>* p)
{
	data = d;
	next = n;
	prev = p;
}

#endif
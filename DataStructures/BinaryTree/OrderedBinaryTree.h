#ifndef ORDEREDBINARYTREE_H
#define ORDEREDBINARYTREE_H

#include <new>
#include "../Node/BinNode.h"

template <typename TYPE>
class BinaryTree
{
	private:
		BinNode<TYPE>* root;

	public:
		BinaryTree();
		~BinaryTree();
		bool insert();
		bool remove();
		bool retrieve();
		bool viewRoot();
		void display();
		bool isEmpty();
		bool isFull();

	private:
		void destroyTree(BinNode<TYPE>* node);

};

template <typename TYPE>
BinaryTree<TYPE>::BinaryTree()
{
	root = nullptr;
}

template <typename TYPE>
BinaryTree<TYPE>::~BinaryTree()
{
	destroyTree(root);
	root = nullptr;
}

template <typename TYPE>
void BinaryTree<TYPE>::destroyTree(BinNode<TYPE>* node)
{
	if (node == nullptr)
		return;

	destroyTree(node->left);
	destroyTree(node->right);
	delete node;
}

#endif
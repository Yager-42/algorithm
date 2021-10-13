#pragma once
#ifndef AVL_H
#define AVL_H
#include<iostream>
using namespace std;
template<typename T>
class AVL
{
public:
	struct node
	{
		T data;
		node* left;
		node* right;
		int high = 0;
		node(T element, node* l=NULL, node* r=NULL):data(element),left(l),right(r)
		{
			high = Height(this);
		}
		node()
		{
			data = 0;
			left = right = NULL;
			high = Height(this);
		}
		int Height(node* r)
		{
			int lh, rh;
			lh = rh = 0;
			if (r == NULL)
			{
				return -1;
			}
			else if (r->left != NULL && r->right != NULL)
			{
				lh = 1 + Height(r->left);
				rh = 1 + Height(r->right);
			}
			else if (r->left == NULL && r->right != NULL)
			{
				lh = 0;
				rh = 1 + Height(r->right);
			}
			else if (r->left != NULL && r->right == NULL)
			{
				rh = 0;
				lh = 1 + Height(r->left);
			}
			else
			{
				rh = lh = 0;
			}
			if (lh > rh)
			{
				return lh;
			}
			else
			{
				return rh;
			}
		}
		
	};
private:
	node* root;
public:
	AVL()
	{
		root = new node;
	}
	AVL(T element)
	{
		root = new node(element);
	}
	void insert(T element)
	{
		return insert(element, root);
	}
	void insert(T element, node*& r)
	{
		if (r == NULL)
		{
			r = new node;
			r->data = std::move(element);
		}
		else if (element < r->data)
		{
			insert(element, r->left);
		}
		else if (element > r->data)
		{
			insert(element, r->right);
		}
		balance(r);
	}
	const T& findMin(node* r) const
	{
		node* temp = r;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp->data;
	}
	void remove( T element)
	{
		return remove(element, root);
	}
	void remove( T element, node*& r)
	{
		if (r == NULL)
		{
			return;
		}
		else if (element < r->data)
		{
			 remove(element, r->left);
		}
		else if (element > r->data)
		{
			 remove(element, r->right);
		}
		else if (r->left != NULL && r->right != NULL)
		{
			T theData = findMin(r->right);
			r->data = theData;
			remove(theData, r);
		}
		else
		{
			node* old = r;
			if (r->left == NULL)
			{
				r = r->right;
			}
			else if (r->right == NULL)
			{
				r = r->left;
			}
			else
			{
				r = NULL;
			}
			delete old;
		}
		balance(r);

	}
	int height(node* r)
	{
		if (r == NULL)
		{
			return -1;
		}
		else
		{
			if (r->Height(r->left) > r->Height(r->right))
			{
				return height(r->left) + 1;
			}
			else
			{
				return height(r->right) + 1;
			}
		}
	}
	void rotatefromleft(node*& r)
	{
		node* nr = r->left;
		r->left = nr->right;
		nr->right = r;
		r->high = height(r);
		nr->high = height(nr);
		r = nr;
	}
	void rotatefromright(node*& r)
	{
		node* nr = r->right;
		r->right = nr->left;
		nr->left = r;
		r->high = height(r);
		nr->high = height(nr);
		r = nr;
	}
	void doublerotatefromleft(node*& r)//²åÁË×ó±ßµÄÓÒ±ß
	{
		rotatefromright(r->left);
		rotatefromleft(r);
	}
	void doublerotatefromright(node*& r)
	{
		rotatefromleft(r->right);
		rotatefromright(r->left);
	}
	void balance(node*& r)
	{
		if (r == NULL)
		{
			return;
		}
		if (height(r->left) - height(r->right) > 1)
		{
			if (height(r->left->left) >= height(r->left->right))
			{
				rotatefromleft(r);
			}
			else
			{
				doublerotatefromleft(r);
			}
		}
		else if(height(r->right)-height(r->left)>1)
		{
			if (height(r->right->right) >= height(r->right->left))
			{
				rotatefromright(r);
			}
			else
			{
				doublerotatefromright(r);
			}
		}
		r->high=height(r);
	}
	void print()
	{
		print(root);
	}
	void print(node*& r)
	{
		if (r != NULL)
		{
			print(r->left);
			cout << r->data << " " << r->high << " ";
			print(r->right);
		}
	}
};
#endif
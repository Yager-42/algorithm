#pragma once
#ifndef LIST_H
#define LIST_H

#include<iostream>
using namespace std;

#define MAXSIZE 1000

class RotateArray
{
private:
	int rear;
	int tail;
	int TheArray[MAXSIZE] = { 0 };
	int size;
public:
	RotateArray()
	{
		rear = tail = 0;
		size = 0;
	}

	bool Full()
	{
		if (size == MAXSIZE)
			return 1;
		else
			return 0;
	}
	bool Empty()
	{
		if (size == 0)
			return 1;
		else
			return 0;
	}
	bool insert(int&& target)
	{
		if (!this->Full())
		{
			TheArray[tail] = target;
			tail = (tail + 1) % size;
			++size;
		}
		else
		{
			cout << "is full" << endl;
		}
	}
	bool pop()
	{
		if (!this->Empty())
		{
			TheArray[rear] = 0;
			rear = (rear + 1) % size;
			--size;

		}
		else
		{
			cout << "is empty" << endl;
		}
	}
};

template<typename T>
class List
{
public:
	struct Node
	{
		T data;
		Node* pre;
		Node* next;
	};
protected:
	Node* header;
	Node* tail;
	int size;
public:
	class iterator
	{
	protected:
		Node* curr;
	public:
		iterator()
		{
			curr = NULL;
		}
		T operator*()
		{
			return curr->data;
		}
		iterator operator++()
		{
			curr = curr->next;
			return *this;
		}
		iterator operator++(int)
		{
			Node* tem = curr;
			curr = curr->next;
			return tem;
		}
		bool operator==(const iterator& target)
		{
			if (curr->data == target.curr->data)
				return 1;
			else
				return 0;
		}
		bool operator!=(const iterator& target)
		{
			if (curr->data != target.curr->data)
				return 1;
			else
				return 0;
		}

	};
public:
	List()
	{
		init();
	}
	void init()
	{
		header = new Node;
		tail = new Node;
		header->next = tail;
		tail->pre = header;
		cout << "enter the size" << endl;
		cin >> size;
		T Data = 0;
		Node* tem = NULL;
		for (int i = 0; i < size; ++i)
		{
			cout << "enter data of " << i + 1 << " element" << endl;
			cin >> Data;
			tem = new Node;
			tem->data = Data;
			tem->pre = tail->pre;
			tail->pre->next = tem;
			tem->next = tail;
			tail->pre = tem;
		}
	}
	List(const List& target)
	{
		size = target.size;
		header = target.header;
		tail = target.tail;
	}
	List& operator=(const List& target)
	{
		size = target.size;
		header = target.header;
		tail = target.tail;
		return *this;
	}
	iterator begin()
	{
		iterator temp{ header->next };
		return temp;
	}
	iterator end()
	{
		iterator temp{ tail->pre };
		return temp;
	}
	iterator insert(iterator itr, T&& data)
	{
		Node* temp = itr.curr;
		++size;
		return { temp->pre = temp->pre->next = new Node{std::move(data),temp->pre,temp} };
	}
	void insert(T data,int index)
	{
		Node* tem = header->next;
		for (int i = 0; i < index; ++i)
		{
			tem = tem->next;
		}
		Node* newnode = new Node{ data,tem->pre,tem };
		tem->pre->next = newnode;
		tem->pre = newnode;
		++size;
	}
	void Delete(int index)
	{
		Node* tem = header->next;
		for (int i = 0; i < index; ++i)
		{
			tem = tem->next;
		}
		tem->pre->pre->next = tem;
		Node* temp = tem->pre;
		tem->pre = tem->pre->pre;
		delete temp;
		--size;
	}
	int SIZE()const
	{
		return this->size;
	}
	void print()
	{
		Node* temp = header->next;
		for (int i = 0; i < size; ++i)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	void ThreeOne(const List& target)
	{
		Node* tempNode = header->next;
		Node* tracer = target.header->next;
		int j = 0;
		int num = 0;
		for (int i = 0; i < target.SIZE(); ++i)
		{
			num = tracer->data;
			tracer = tracer->next;
			for (; j < num -1; ++j)
			{
				tempNode = tempNode->next;
			}
			cout << tempNode->data << endl;
		}
	}

};

template<typename T>
class vector
{
private:
	int size;
	int capcity;
	T* handle;
public:
	vector(int size=0)
	{
		this->size = size;
		this->capcity = 2 * size + 1;
		handle = new T[capcity];
	}
	vector(const vector& target)
		:size{ target.size }, capcity{ target.capcity }, handle{ NULL }
	{
		handle = new T;
		for (int i = 0; i < size; ++i)
		{
			handle[i] = target.handle[i];
		}
	}
	vector(vector&& target)
	{
		size = target.size;
		capcity = target.capcity;
		handle = target.handle;
		target.handle = NULL;

	}

	void resize(int newsize)
	{
		if (newsize > capcity)
		{
			return reserve(newsize * 2);
		}
		size = newsize;
	}
	void reserve(int newcapcity)
	{
		T* newone = new T[newcapcity];
		for (int i = 0; i < size; ++i)
		{
			newone[i] = handle[i];
		}
		delete[]handle;
		handle = newone;
		newone = NULL;
		capcity = newcapcity;

	}
	T& operator[](int index)
	{
		return handle[index];
	}
	bool empty()
	{
		return size == 0;
	}
	int SIZE()
	{
		return size;
	}
	int Capcity()
	{
		return capcity;
	}
	void push_back(T&& data)
	{
		if (size + 1 < capcity)
		{
			++size;
			handle[size] = std::move(data);
		}
		else
		{
			reserve(2 * (size + 1) + 1);
		}
	}
	void popback()
	{
		--size;
	}
	typedef T* iterator;
	iterator begin()
	{
		return handle;
	}
	iterator end()
	{
		return handle[size - 1];
	}


	
};

template<typename T>
class stack
{
private:
	int top;
	vector<T> myVec;
public:
	stack()
	{
		top = -1;
	}
	stack(int ursize)
	{
		initstack(ursize);
	}
	void initstack(int urSize)
	{
		myVec.resize(urSize);
		top = -1;
	}
	void push(T&& data)
	{
		++top;
		myVec[top] = std::move(data);
	}
	void push(const T& data)
	{
		++top;
		myVec[top] = data;
	}
	T pop()
	{
		return myVec[top--];
	}
	T Top()
	{
		return myVec[top];
	}
	int topvalue()
	{
		return top;
	}
};

void computer()
{
	string expression;
	string postexpression;
	stack<char> str;
	cout << "输入要求的表达式" << endl;
	cin >> expression;
	for (int i = 0; i < (unsigned int)expression.length(); ++i)
	{
		if (expression[i] <= 47 || expression[i] >= 58)
		{
			if (expression[i] == '+'||expression[i]=='-')
			{
				if (str.topvalue() != -1)
				{
					if (str.Top() == '*' || str.Top() == '/')
					{
						postexpression += str.pop();
						while (str.Top() == '+' || str.Top() == '-')
						{
							postexpression += str.pop();
						}
					}
				}
				str.push(expression[i]);
			}
			else if (expression[i] == '*' || expression[i] == '/')
			{
				str.push(expression[i]);
			}
			else if (expression[i] == '(')
			{
				str.push(expression[i]);
			}
			else if (expression[i] == ')')
			{
				while (str.Top() != '(')
				{
					postexpression += str.pop();
				}
				str.pop();
			}
		}
		else
		{
			postexpression += expression[i];
		}
	}
	while (str.topvalue() != -1)
	{
		postexpression += str.pop();
	}
	cout << postexpression;
}

template<typename T>
class BinarySearchTree
{
public:
	struct treeNode
	{
		T data;
		treeNode* left;
		treeNode* right;
		treeNode()
		{
			data = 0;
			left = right = NULL;
		}
		treeNode(const T& thedata, treeNode* lt, treeNode* rt) :data(thedata), left(lt), right(rt)
		{

		}
		treeNode(T&& thedata, treeNode* lt, treeNode* rt) :data(std::move(thedata), left(lt), right(rt))
		{

		}
	};
private:
	treeNode* root;
public:
	BinarySearchTree()
	{
		root = new treeNode;
		cout << "enter root" << endl;
		cin >> root->data;
	}
	const T& findMax()const
	{
		return findMax(root);
	}
	const T& findMin()const
	{
		return findMin(root);
	}
	const T& findMax(treeNode* r) const
	{
		treeNode* temp = r;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		return temp->data;
	}
	const T& findMin(treeNode* r) const
	{
		treeNode* temp = r;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp->data;
	}
	bool contain(const T& element)
	{
		return contain(element, root);
	}
	bool contain(const T& element, treeNode* r)
	{
		if (r == NULL)
		{
			return 0;
		}
		if (element == r -> data)
		{
			return 1;
		}
		else if (element < r->data)
		{
			return contain(element, r->left);
		}
		else
		{
			return contain(element, r->right);
		}
	}
	bool isEmpty()const
	{
		if (root == NULL)
		{
			return 1;
		}
		return 0;
	}
	void printTree(ostream& out,treeNode* n)const
	{
		out << n->data << endl;
	}
	void insert(const T& element)
	{
		return insert(element, root);
	}
	void insert(const T& element, treeNode*& r)
	{
		if (r == NULL)
		{
			r = new treeNode;
			r->data = element;
		}
		else if (element < r->data)
		{
			insert(element, r->left);
		}
		else if (element > r->data)
		{
			insert(element, r->right);
		}
		else
		{

		}
	}
	void insert(T&& element)
	{
		return insert(element, root);
	}
	void insert(T&& element, treeNode* r)
	{
		if (r == NULL)
		{
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
		else
		{

		}
	}
	void remove(const T& element)const
	{
		return remove(element, root);
	}
	void remove(const T& element, treeNode* r)const
	{
		if (r == NULL)
		{
			return;
		}
		else if (element < r->data)
		{
			return remove(element, r->left);
		}
		else if (element > r->data)
		{
			return remove(element, r->right);
		}
		else if (r->left != NULL && r->right != NULL)
		{
			T theData = findMin(r->right);
			r->data = theData;
			remove(theData, r);
		}
		else
		{
			treeNode* old = r;
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
	}


};

#endif
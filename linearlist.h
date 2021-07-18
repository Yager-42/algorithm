#pragma once
#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H
#define MAXSIZE 1000
#include<iostream>
using namespace std;

template<typename T>
class sequential_list
{
private:
	T data[MAXSIZE] = { 0 };
	int length;
public:
	sequential_list()
	{
		cout << "enter the length of the list" << endl;
		cin >> length;
		for (int i = 0; i < length; ++i)
		{
			cout << "enter number" << endl;
			cin >> data[i];
		}
	}
	void initList()
	{
		for (int i = 0; i < length; ++i)
		{
			data[i] = 0;
		}
	}
	void listEmpty()
	{
		if (length == 0)
		{
			return 0;
		}
		return 1;
	}
	void clearList()
	{
		initList();
		length = 0;
	}
	T getElem(int index,T* element);
	int locateElem(T element);
	bool listInsert( int index, T num);
	T listDelete( int index, T* num);
	int listLength()
	{
		return length;
	}
	void showdata()
	{
		for (int i = 0; i < length; ++i)
		{
			cout << data[i]<<endl;
		}
	}



};
template<typename T>
struct Node
{
	T data;
	Node* next=NULL;
};
template<typename T>
class chain
{
private:
	Node<T>* head=new Node<T>;
	int length = 0;
public:
	chain()
	{
		initListTail();
	}
	void initList()
	{
		cout << "the length of the list pls" << endl;
		cin >> length;
		head->next = NULL;
		for (int i = 0; i < length; ++i)
		{
			Node<T>* temp = new Node<T>;
			cout << "enter the data of " << i + 1 << " element" << endl;
			cin >> temp->data;
			temp->next = head->next;
			head->next = temp;
		}
	}
	void initListTail()
	{
		Node<T>* temp=head;
		cout << "enter the length of the list " << endl;
		cin >> length;
		head->next = NULL;
		for (int i = 0; i < length; ++i)
		{
			Node<T>* p = new Node<T>;
			cout << "enter the data of " << i + 1 << " element" << endl;
			cin >> p->data;
			temp->next = p;
			temp = p;
		}
		temp->next = NULL;
	}
	bool getElem(int index,Node<T>* element)
	{
		Node<T>* temp;
		if (index >= length && index < 0)
		{
			return 0;
		}
		temp = head->next;
		for (int i = 0; i < index; ++i)
		{
			temp=temp->next;

		}
		element->data = temp->data;
		return 1;
	}
	bool deleteElem(int index,Node<T>* e)
	{
		Node<T>* temp;
		if (index < 0 || index >= length)
		{
			return 0;
		}
		temp = head->next;
		for (int i = 0; i < index-1; ++i)
		{
			temp = temp->next;
		}
		Node<T>* tempP = temp->next;
		temp->next = tempP->next;
		e->data = tempP->data;
		delete tempP;
		--length;
		return 1;


	}
	int locateElement(Node<T> element)
	{
		Node<T>* temp = NULL;
		temp = head->next;
		for (int i = 0; i < length; ++i)
		{
			if (temp->data == element.data)
			{
				return i+1;
			}
			temp = temp->next;
		}
		return -1;
	}
	bool insertList(int index, Node<T>*element)
	{
		if (index >= length || index < 0)
		{
			return 0;
		}
		Node<T>* temp = NULL;
		temp = head->next;
		for (int i = 0; i < index-1; ++i)
		{
			temp = temp->next;
		}
		Node<T>* tempP = temp->next;
		temp->next = element;
		element->next = tempP;
		++length;
		return 1;


	}
	void clearList()
	{
		Node<T>* tempN = head->next;
		Node<T>* tempN_ = NULL;
		while (tempN)
		{
			tempN_ = tempN->next;
			delete tempN;
			tempN = tempN_;
		}
		head->next = NULL;
		length = 0;
	}
	void show()
	{
		Node<T>* temp;
		temp = head->next;
		for (int i = 0; i < length; ++i)
		{
			cout <<"µÚ"<<i+1<<"¸öÔªËØ£º "<< temp->data << endl;
			temp = temp->next;
		}
	}


};

#endif
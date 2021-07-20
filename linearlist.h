#pragma once
#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H
#define MAXSIZE 1000
#include<iostream>
#include<time.h>
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
	Node<T>* tail = new Node<T>;
	int length = 0;
public:
	chain()
	{
		magician();
	}
	void initRlist()
	{
		head->next = head;
		Node<T>* temp;
		Node<T>* endP_before;
		cout << "the length pls " << endl;
		cin >> length;
		for (int i = 0; i < length; ++i)
		{
			for (endP_before = head->next; endP_before->next != head; endP_before = endP_before->next);
			cout << "enter the data of " << i + 1 << " element" << endl;
			temp = new Node<T>;
			cin >> temp->data;
			temp->next = head;
			endP_before->next = temp;
			
		}
	}
	void random_initList()
	{
		head->next = NULL;
		srand(time(0));
		length = 20;
		for (int i = 0; i < length; ++i)
		{
			Node<T>* temp = new Node<T>;
			temp->data = (T)rand();
			temp->next = head->next;
			head->next = temp;
		}
	}
	void random_initList_Tail()
	{
		Node<T>* temp = head;
		head->next = NULL;
		srand(time(0));
		length = 20;
		for (int i = 0; i < length; ++i)
		{
			Node<T>* p = new Node<T>;
			p->data = (T)rand();
			temp->next = p;
			temp = p;
		}
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
	T getMidNode()
	{
		Node<T>* fast = head;
		Node<T>* low = head;
		while (fast->next!=NULL && fast!=NULL)
		{
			fast =fast->next->next;
			low=low->next;
		}
		return low->data;
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
		int i = 0;
		temp = head->next;
		while(temp!=NULL&&temp!=head)
		{
			cout <<"第"<<i+1<<"个元素： "<< temp->data << endl;
			temp = temp->next;
			++i;
		}
	}
	void Rinsert(int index)
	{
		Node<T>* temp=new Node<T>;
		Node<T>* target=head->next;
		Node<T>* p;
		cout << "the value you want to insert: " << endl;
		cin >> temp->data;
		if (index == 0)
		{
			head->next = temp;
			temp->next = head;
		}
		else
		{
			for (int i = 0; i < index - 1; ++i)
			{
				target = target->next;
			}
			p = target->next;
			target->next = temp;
			temp->next = p;
		}

	}
	void Rdelete(int index)
	{
		Node<T>* temp;
		Node<T>* target;
		if (index == 0)
		{
			temp = head->next;
			head->next = temp->next;
			delete temp;
			temp = NULL;
		}
		else
		{
			target = head->next;
			for (int i = 0; i < index - 1; ++i)
			{
				target = target->next;
			}
			temp = target->next;
			target->next = temp->next;
			delete temp;
			temp = NULL;
		}
	}
	int Rsearch(T data)
	{
		Node<T>* temp = head->next;
		int i = 0;
		while (temp != head)
		{
			if (temp->data == data)
			{
				return i;
			}
			++i;
			temp = temp->next;
		}
		return -1;
	}
	//下面为了方便我把头指针当作头节点来用了
	void josephus()
	{
		head->next = head;
		head->data = 1;
		length = 41;
		Node<T>* temp;
		Node<T>* target;
		for (int i = 1; i < length; ++i)
		{
			temp = new Node<T>;
			temp->data = i + 1;
			for (target = head; target->next != head; target = target->next);
			temp->next = head;
			target->next = temp;
		}//生成1到41的循环链表
		Node<T>* handle = head;
		Node<T>* tempH = NULL;
		int times = 0;
		while (handle->next!=handle)
		{
			handle = handle->next;
			cout << handle->next->data << " has suicided" ;
			tempH = handle->next;
			handle->next = handle->next->next;
			handle = handle->next;
			delete tempH;
			tempH = NULL;
			++times;
			cout << "  " << times << endl;
		}
		cout << handle->data << " has suicided" << "  " << ++times << endl;

	}
	//带头节点和尾节点的循环链表
	void InitRlist_tail()//尾插法
	{
		Node<T>* temp;
		Node<T>* p=head;
		head->next = tail;
		cout << "enter the length pls " << endl;
		cin >> length;
		for (int i = 0;i < length; ++i)
		{
			cout << "enter the data pls " << endl;
			temp = new Node<T>;
			cin >> temp->data;
			temp->next = p->next;//将尾指针指向新的尾部
			p->next = temp;
			p = temp;
		}
	}
	void InitRlist_head()//头插法
	{
		Node<T>* temp;
		head->next = tail;
		cout << "enter the length pls " << endl;
		cin >> length;
		for (int i = 0; i < length; ++i)
		{
			cout << "enter the data pls " << endl;
			temp = new Node<T>;
			cin >> temp->data;
			temp->next = head->next;
			head->next = temp;
		}
	}//头插法使得尾指针不用重新指向
	void magician()
	{
		Node<T>* temp;
		Node<T>* p = head;
		length = 13;
		for (int i = 0; i < length; ++i)
		{
			temp = new Node<T>;
			temp->data = 0;
			p->next = temp;
			p = temp;
		}
		p->next = head->next;
		//生成一个十三个数的循环链表
		head->next->data = 1;
		Node<T>* tempPoint = head->next;
		int count = 2;
		while (1)
		{
			for (int i = 0; i < count; ++i)
			{
				tempPoint = tempPoint->next;
				if (tempPoint->data != 0)
				{
					tempPoint = tempPoint->next;
					--i;
				}
			}
			tempPoint->data = count;
			count+=1;
			if (count == 14)
			{
				break;
			}
		}
		Node<T>* tempNode = head->next;
		for (int i = 0; i < length; ++i)
		{
			cout << "the " << i + 1 << " card is " << tempNode->data << endl;
			tempNode = tempNode->next;
		}

	}



};
//接下来是双向链表
template<typename T>
struct double_node
{
	T data;
	double_node* prior;
	double_node* next;
};
template<typename T>
class dualList
{
private:
	double_node<T>* head;
	int length;
public:
	dualList()
	{
		initList();
	}
	void initList()
	{
		head = new double_node<T>;
		double_node<T>* temp;
		double_node<T>* p = head;//尾插，头插不写了，差不多
		cout << "enter the length pls" << endl;
		cin >> length;
		for (int i = 0; i < length; ++i)
		{
			temp = new double_node<T>;
			p->next = temp;
			temp->prior = p;
			p = temp;
		}
		p->next = NULL;//不循环，循环指向头就好了

	}
	void insertList(int index)
	{
		double_node<T>* temp = new double_node<T>;
		double_node<T>* pointer = head->next;
		cout << "enter the data" << endl;
		cin >> temp->data;
		for (int i = 0; i < index; ++i)
		{
			pointer = pointer->next;
		}
		pointer->prior->next = temp;
		temp->next = pointer;
		temp->prior = pointer->prior;
		pointer->prior = temp;
	}
	void deletelist(int index,double_node<T>* temp)
	{
		double_node<T>* pointer = head->next;
		for (int i = 0; i < index; ++i)
		{
			pointer = pointer->next;
		}
		pointer->prior->next = pointer->next;
		pointer->next->prior = pointer->prior;
		temp->data = pointer->data;
		delete pointer;
	}

};

#endif
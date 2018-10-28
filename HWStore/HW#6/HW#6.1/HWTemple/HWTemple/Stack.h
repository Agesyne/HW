#pragma once
#include "pch.h"
#include <iostream>
#include "StackElement.h"


//extern class StackElement;

template<typename T>
class Stack
{
private:
	size_t size = 0;
	StackElement<T> *top = nullptr;
public:
	//�����������
	Stack<T>(size_t sizeN = 0, StackElement<T> *topN = nullptr)
	{
		size = sizeN;
		top = topN;
	}

	//����������
	~Stack<T>()
	{
		while (size != 0)
		{
			pop();
		}
	}

	//�������� �������
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}

	//�������� �������
	void push(T data)
	{
		StackElement<T> *newElement = new StackElement<T>{ data, top };
		top = newElement;
		++size;
	}

	//������� �������
	void pop()
	{
		if (!isEmpty())
		{
			StackElement<T> *deletingElement = top;
			top = top->prev;
			delete deletingElement;
			--size;
		}
		else
		{
			cout << "Stack is empty" << endl;
			exit(1);
		}
	}

	//�������� ������� ��������
	T peak()
	{
		if (!isEmpty())
		{
			return top->data;
		}
		else
		{
			cout << "Stack is empty" << endl;
			exit(1);
		}
	}
};


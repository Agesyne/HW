#pragma once
#include "pch.h"
#include <iostream>
#include "StackElement.h"



template<typename T>
class Stack
{
private:
	size_t size = 0;
	StackElement<T> *top = nullptr;
public:
	//�����������
	explicit Stack<T>(size_t sizeN = 0, StackElement<T> *topN = nullptr)
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
	bool isEmpty() const
	{
		return size == 0;
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
			top = top->getPrev();
			delete deletingElement;
			--size;
		}
		else
		{
			std::cout << "Stack is empty" << std::endl;
			exit(1);
		}
	}

	//�������� ������� ��������
	T peak() const
	{
		if (!isEmpty())
		{
			return top->getData();
		}
		else
		{
			std::cout << "Stack is empty" << std::endl;
			exit(1);
		}
	}
};


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
	//конструктор
	Stack<T>(size_t sizeN = 0, StackElement<T> *topN = nullptr)
	{
		size = sizeN;
		top = topN;
	}

	//деструктор
	~Stack<T>()
	{
		while (size != 0)
		{
			pop();
		}
	}

	//проверка пустоты
	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}

	//добавить элемент
	void push(T data)
	{
		StackElement<T> *newElement = new StackElement<T>{ data, top };
		top = newElement;
		++size;
	}

	//удалить элемент
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

	//получить верхний элеммент
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


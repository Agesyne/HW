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
	//конструктор
	explicit Stack<T>(size_t sizeN = 0, StackElement<T> *topN = nullptr)
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
	bool isEmpty() const
	{
		return size == 0;
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

	//получить верхний элеммент
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


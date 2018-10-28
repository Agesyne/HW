#pragma once
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
	Stack<T>(size_t = 0, StackElement<T>* = nullptr);

	//деструктор
	~Stack<T>();

	//проверка пустоты
	bool isEmpty();

	//добавить элемент
	void push(T data);

	//удалить элемент
	void pop();

	//получить верхний элеммент
	T peak();
};


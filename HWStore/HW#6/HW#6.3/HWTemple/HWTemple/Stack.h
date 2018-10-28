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
	//�����������
	Stack<T>(size_t = 0, StackElement<T>* = nullptr);

	//����������
	~Stack<T>();

	//�������� �������
	bool isEmpty();

	//�������� �������
	void push(T data);

	//������� �������
	void pop();

	//�������� ������� ��������
	T peak();
};


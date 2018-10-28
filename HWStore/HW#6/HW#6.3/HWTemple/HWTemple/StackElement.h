#pragma once

template<typename T>
class StackElement
{
public:
	T data;
	StackElement<T> *prev;

	StackElement(T data, StackElement<T> *prev);
};


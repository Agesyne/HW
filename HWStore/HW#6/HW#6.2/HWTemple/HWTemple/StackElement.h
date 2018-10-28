#pragma once

template<typename T>
class StackElement
{
public:
	T data;
	StackElement<T> *prev;

	StackElement(T dataN, StackElement<T> *prevN)
	{
		data = dataN;
		prev = prevN;
	}

};


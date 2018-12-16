#pragma once

template<typename T>
class StackElement
{
private:
	T data;
	StackElement<T> *prev;
public:

	StackElement(T dataN, StackElement<T> *prevN)
	{
		data = dataN;
		prev = prevN;
	}

	StackElement<T> *getPrev()
	{
		return prev;
	}
	
	T getData()
	{
		return data;
	}

};

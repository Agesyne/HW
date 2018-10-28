//#include "pch.h"
//#include "Stack.h"
//#include <iostream>
//#include "StackElement.h"
//using namespace std;
//
//
//
////template<typename T>
////struct StackElement
////{
////	T data;
////	StackElement<T> *prev;
////};
//
//template<typename T>
//Stack<T>::Stack(size_t size, StackElement<T> *top)
//{
//	this.size = size;
//	this.top = top;
//}
//
//template<typename T>
//Stack<T>::~Stack()
//{
//	while (size != 0)
//	{
//		pop();
//	}
//}
//
//template<typename T>
//bool  Stack<T>::isEmpty()
//{
//	if (size == 0)
//	{
//		return true;
//	}
//	return false;
//}
//
//template<typename T>
//void  Stack<T>::push(T data)
//{
//	StackElement<T> newElement = new StackElement<T>{ data, top };
//	top = newElement;
//	++size;
//}
//
//template<typename T>
//void  Stack<T>::pop()
//{
//	if (!isEmpty)
//	{
//		StackElement<T> *deletingElement = top;
//		top = top->prev;
//		delete deletingElement;
//		--size;
//	}
//	else
//	{
//		cout << "Stack is empty" << endl;
//		exit(1);
//	}
//}
//
//template<typename T>
//T  Stack<T>::peak()
//{
//	if (!isEmpty)
//	{
//		return top->data;
//	}
//	else
//	{
//		cout << "Stack is empty" << endl;
//		exit(1);
//	}
//}
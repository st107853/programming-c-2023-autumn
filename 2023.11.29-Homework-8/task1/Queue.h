#pragma once
#include<exception>
#include <iostream>
#include <thread>
#include <mutex>

#include "Node.h"

template<typename obj>

class Queue
{
	Node<obj>* head = nullptr;
	Node<obj>* tail = nullptr;
	std::mutex mut;
public:
	void push(obj x);
	obj  front();
	obj  back();
	void pop();
	bool empty();

	Queue(): head(nullptr), tail(nullptr), mut() {};
	~Queue() {}
};

template<typename obj>
bool Queue<obj>::empty()
{
	if (head) return 1;
	return 0;
}

template<typename obj>
void Queue<obj>::push(obj x)
{
	Node<obj>* temp = new Node<obj>();
	temp->data = x;
	std::lock_guard<std::mutex> lock(mut);
	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

template<typename obj>
obj Queue<obj>::front()
{
	std::lock_guard<std::mutex> lock(mut);
	if (head == nullptr) throw std::exception("queue is empty");
	return head->data;
}

template<typename obj>
obj Queue<obj>::back()
{
	std::lock_guard<std::mutex> lock(mut);
	if (tail == nullptr) throw std::exception("queue is empty");
	return tail->data;
}

template<typename obj>
void Queue<obj>::pop()
{
	std::lock_guard<std::mutex> lock(mut);
	if (head == nullptr)
	{
		throw std::exception("pop from empty queue");
	}
	Node<obj>* temp = head;
	head = head->next;
	delete temp;
}
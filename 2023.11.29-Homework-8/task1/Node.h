#pragma once

template<typename obj>
struct Node
{
	obj data;
	Node<obj>* next;

	Node() : data(), next(nullptr) {};
	
	~Node() = default;
};
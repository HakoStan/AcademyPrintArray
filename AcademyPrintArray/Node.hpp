#pragma once
#include <iostream>

namespace YAFramework
{
	template <typename T>
	class Node
	{
	public:
		Node();
		Node(T item, Node<T>* ptr = nullptr);
		~Node();
		void InsertAfter(Node<T>* newNode);
		Node<T>* DeleteAfter();
		Node<T>* GetNext();
		T GetData() const;
		void SetNext(Node<T>* next);

		template <typename U>
		friend std::ostream& operator<<(std::ostream& os, const Node<U>& node);
	private:
		T data;
		Node* next = nullptr;
	};

	template <typename U>
	std::ostream& operator<<(std::ostream & os, const Node<U>& node)
	{
		os << node.GetData();
		return os;
	}

	template <typename T>
	Node<T>::Node()
	{
		this->next = nullptr;
	}

	template <typename T>
	Node<T>::Node(T item, Node<T>* ptr)
	{
		this->data = item;
		this->next = ptr;
	}

	template <typename T>
	Node<T>::~Node()
	{
	}

	template <typename T>
	void Node<T>::InsertAfter(Node<T>* newNode)
	{
		newNode->next = this->next;
		this->next = newNode;
	}

	template <typename T>
	Node<T>* Node<T>::DeleteAfter()
	{
		Node<T>* temp = this->next;
		if (this->next == nullptr)
		{
			return nullptr;
		}
		this->next = temp->next;
		return temp;
	}

	template<typename T>
	Node<T>* Node<T>::GetNext()
	{
		return this->next;
	}
	template<typename T>
	T Node<T>::GetData() const
	{
		return this->data;
	}

	template<typename T>
	void Node<T>::SetNext(Node<T>* next)
	{
		this->next = next;
	}
}
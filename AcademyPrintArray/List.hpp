#pragma once
#include "Node.hpp"
#include <cstdint>
#include <iostream>

namespace YAFramework
{
	template <typename T>
	class List
	{
	public:
		List();
		List(Node<T>* ptr);
		~List();
		void MakeEmpty();
		bool IsEmpty();
		Node<T>* First() const;
		Node<T>* Last();
		void Insert(Node<T>* newNode);
		void InsertAfter(Node<T>* position, Node<T>* newNode);
		void InsertToHead(Node<T>* newNode);

		template <typename U>
		friend std::ostream& operator<<(std::ostream & os, const List<U>& list);
	private:
		void FreeList();
		Node<T>* head = nullptr;
		Node<T>* tail = nullptr;
	};

	template <typename U>
	std::ostream& operator<<(std::ostream & os, const List<U>& list)
	{
		Node<U>* temp = list.First();
		while (temp != nullptr)
		{
			os << *temp << std::endl;
			temp = temp->GetNext();
		}
		return os;
	}

	template <typename T>
	List<T>::List()
	{
		MakeEmpty();
	}

	template <typename T>
	List<T>::List(Node<T> * ptr)
	{
		this->head = ptr;
		this->tail = ptr;
	}

	template <typename T>
	List<T>::~List()
	{
		FreeList();
	}

	template <typename T>
	void List<T>::MakeEmpty()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	template <typename T>
	bool List<T>::IsEmpty()
	{
		return head == nullptr;
	}

	template <typename T>
	Node<T> * List<T>::First() const
	{
		return this->head;
	}

	template <typename T>
	Node<T> * List<T>::Last()
	{
		return this->tail;
	}

	template <typename T>
	void List<T>::Insert(Node<T> * newNode)
	{
		if (this->head == nullptr && this->tail == nullptr)
		{
			this->head = newNode;
			this->tail = newNode;
			return;
		}
		this->tail->InsertAfter(newNode);
		this->tail = newNode;
	}

	template<typename T>
	void List<T>::InsertToHead(Node<T>* newNode)
	{
		if (this->head == nullptr && this->tail == nullptr)
		{
			this->head = newNode;
			this->tail = newNode;
			return;
		}
		Node<T>* temp = this->head;
		this->head = newNode;
		this->head->SetNext(temp);
	}

	template <typename T>
	void List<T>::InsertAfter(Node<T>* position, Node<T> * newNode)
	{
		if (position == nullptr)
		{
			// Error - Invalid position
			return;
		}
		else if (position == this->tail)
		{
			this->tail->InsertAfter(newNode);
			this->tail = newNode;
			return;
		}
		else
		{
			Node<T>* temp = this->head;
			while (temp != nullptr)
			{
				if (temp == position)
				{
					temp->InsertAfter(newNode);
					return;
				}
				temp = temp->GetNext();
			}
		}
	}

	template <typename T>
	void List<T>::FreeList()
	{
		Node<T>* temp = this->head;
		Node<T>* tempNext = nullptr;
		while (temp != nullptr)
		{
			tempNext = temp->GetNext();
			delete temp;
			temp = tempNext;
		}
	}
}
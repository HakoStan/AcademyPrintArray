#pragma once
#include <cstdint>
#include "BSTreeNode.hpp"

namespace YAFramework
{
	template <class KeyType, class DataType>
	class BSTree
	{
	public:
		BSTree();
		~BSTree() = default;

		BSTreeNode<KeyType, DataType>* Find(KeyType key);
		void Insert(KeyType key, DataType item);
		void Delete(DataType item);
		void MakeEmpty();
		bool IsEmpty();

		void PrintTreeInorder();
		void PrintTreeInorderTillKey(KeyType key);

		BSTreeNode<KeyType, DataType>* GetRoot();

	private:
		BSTreeNode<KeyType, DataType>* m_root;
	};

	template<class KeyType, class DataType>
	void BSTree<KeyType, DataType>::Delete(DataType item)
	{
		// TODO
	}

	template<class KeyType, class DataType>
	void BSTree<KeyType, DataType>::MakeEmpty()
	{
		this->m_root = nullptr;
	}

	template<class KeyType, class DataType>
	BSTree<KeyType, DataType>::BSTree()
	{
		MakeEmpty();
	}

	template<class KeyType, class DataType>
	BSTreeNode<KeyType, DataType>* BSTree<KeyType, DataType>::Find(KeyType key)
	{
		BSTreeNode<KeyType, DataType>* temp = m_root;
		while (temp != nullptr)
		{
			if (key == temp->m_key)
			{
				return temp;
			}
			else if (key < temp->m_key)
			{
				temp = temp->m_left;
			}
			else
			{
				temp = temp->m_right;
			}
		}

		return nullptr;
	}

	template<class KeyType, class DataType>
	void BSTree<KeyType, DataType>::Insert(KeyType key, DataType item)
	{
		if (this->Find(key) != nullptr)
		{
			return;
		}

		BSTreeNode<KeyType, DataType>* temp = m_root;
		BSTreeNode<KeyType, DataType>* parent = nullptr;
		BSTreeNode<KeyType, DataType>* newNode;

		while (nullptr != temp)
		{
			parent = temp;
			if (key < temp->m_key)
			{
				temp = temp->m_left;
			}
			else
			{
				temp = temp->m_right;
			}
		}

		newNode = new BSTreeNode<KeyType, DataType>(key, item, nullptr, nullptr);
		if (parent == nullptr)
		{
			m_root = newNode;
		}
		else if (key < parent->m_key)
		{
			parent->m_left = newNode;
		}
		else
		{
			parent->m_right = newNode;
		}
	}

	template<class KeyType, class DataType>
	bool BSTree<KeyType, DataType>::IsEmpty()
	{
		return m_root == nullptr;
	}

	template<class KeyType, class DataType>
	void BSTree<KeyType, DataType>::PrintTreeInorder()
	{
		if (m_root != nullptr)
		{
			m_root->InOrder();
		}
	}

	template<class KeyType, class DataType>
	void BSTree<KeyType, DataType>::PrintTreeInorderTillKey(KeyType key)
	{
		if (m_root != nullptr)
		{
			m_root->InOrderTillKey(key);
		}
	}

	template<class KeyType, class DataType>
	BSTreeNode<KeyType, DataType>* BSTree<KeyType, DataType>::GetRoot()
	{
		return this->m_root;
	}
}
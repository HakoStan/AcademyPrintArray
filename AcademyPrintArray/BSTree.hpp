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
		~BSTree();

		BSTreeNode<KeyType, DataType>* Find(KeyType key);
		void Insert(KeyType key, DataType item);
		void Delete(DataType item);
		BSTreeNode<KeyType, DataType>* DeleteByNode(BSTreeNode<KeyType, DataType>* node, DataType item);
		void MakeEmpty();
		bool IsEmpty();
		void FreeTree(BSTreeNode<KeyType, DataType>* node);
		BSTreeNode<KeyType, DataType>* FindMin(BSTreeNode<KeyType, DataType>* node);

		void PrintTreeInorder();
		void PrintTreeInorderTillKey(KeyType key);

		BSTreeNode<KeyType, DataType>* GetRoot();

	private:
		BSTreeNode<KeyType, DataType>* m_root;
	};

	template<class KeyType, class DataType>
	BSTreeNode<KeyType, DataType>* BSTree<KeyType, DataType>::DeleteByNode(BSTreeNode<KeyType, DataType>* node, DataType item)
	{
		if (node == nullptr)
		{
			return node;
		}
		else if (item < node->m_data)
		{
			node->m_left = DeleteByNode(node->m_left, item);
		}
		else if (item > node->m_data)
		{
			node->m_right = DeleteByNode(node->m_right, item);
		}
		else // Equal
		{
			if (node->m_left == nullptr && node->m_right == nullptr)
			{
				delete node;
				node = nullptr;
			}
			else if (node->m_left == nullptr)
			{
				BSTreeNode<KeyType, DataType>* temp = node;
				node = node->m_right;
				delete temp;
			}
			else if (node->m_right == nullptr)
			{
				BSTreeNode<KeyType, DataType>* temp = node;
				node = node->m_left;
				delete temp;
			}
			else
			{
				// 2 Children exists
				BSTreeNode<KeyType, DataType>* temp = FindMin(node->m_right);
				node->m_data = temp->m_data;
				node->m_right = DeleteByNode(node->m_right, temp->m_data);
			}

		}
		return node;
	}

	template<class KeyType, class DataType>
	void BSTree<KeyType, DataType>::Delete(DataType item)
	{
		DeleteByNode(m_root, item);
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
	BSTree<KeyType, DataType>::~BSTree()
	{
		FreeTree(m_root);
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
	void BSTree<KeyType, DataType>::FreeTree(BSTreeNode<KeyType, DataType>* node)
	{
		if (node == nullptr)
		{
			return;
		}
		FreeTree(node->m_left);
		FreeTree(node->m_right);
		delete node;
	}

	template<class KeyType, class DataType>
	BSTreeNode<KeyType, DataType>* BSTree<KeyType, DataType>::FindMin(BSTreeNode<KeyType, DataType>* node)
	{
		while (node->m_left != nullptr)
		{
			node = node->m_left;
		}
		return node;
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
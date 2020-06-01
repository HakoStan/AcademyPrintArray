#pragma once
#include "BSTree.hpp"
#include <iostream>

namespace YAFramework
{
	template <typename KeyType, typename DataType>
	class BSTreeNode
	{
	public:
		BSTreeNode() = default;
		BSTreeNode(KeyType key, DataType data, BSTreeNode<KeyType, DataType>* left, BSTreeNode<KeyType, DataType>* right);
		~BSTreeNode() = default;

		void InOrderTillKey(KeyType key);
		void InOrder();
	private:
		KeyType m_key;
		DataType m_data;
		BSTreeNode<KeyType, DataType>* m_left;
		BSTreeNode<KeyType, DataType>* m_right;

		template <typename KeyType2, typename DataType2>
		friend class BSTree;
	};

	template<typename KeyType, typename DataType>
	BSTreeNode<KeyType, DataType>::BSTreeNode(KeyType key, DataType data, BSTreeNode<KeyType, DataType>* left, BSTreeNode<KeyType, DataType>* right) :
		m_data(data), m_key(key), m_left(left), m_right(right)
	{ }

	template<typename KeyType, typename DataType>
	void BSTreeNode<KeyType, DataType>::InOrder()
	{
		if (m_left != nullptr)
		{
			m_left->InOrder();
		}

		std::cout << m_data << std::endl;

		if (m_right != nullptr)
		{
			m_right->InOrder();
		}
	}

	template<typename KeyType, typename DataType>
	void BSTreeNode<KeyType, DataType>::InOrderTillKey(KeyType key)
	{
		bool goRight = true;

		if (m_key >= key)
		{
			goRight = false;
		}

		if (m_left != nullptr)
		{
			m_left->InOrderTillKey(key);
		}

		if (goRight)
		{
			std::cout << m_data << std::endl;
		}

		if (m_right != nullptr && goRight)
		{
			m_right->InOrderTillKey(key);
		}
	}
}
#pragma once
#include <cstdint>

namespace YAFramework
{
	template <typename T>
	class ComparisonCounter
	{
	public:
		ComparisonCounter() = default;
		ComparisonCounter(T data);
		~ComparisonCounter() = default;

		bool operator==(const ComparisonCounter& other) const;
		bool operator!=(const ComparisonCounter& other) const;
		bool operator<(const ComparisonCounter& other) const;
		bool operator>(const ComparisonCounter& other) const;
		bool operator<=(const ComparisonCounter& other) const;
		bool operator>=(const ComparisonCounter& other) const;

		T GetData() const;
		static std::uint32_t m_counter;

	private:
		T m_data;
	};

	template<typename T>
	std::uint32_t ComparisonCounter<T>::m_counter = 0;

	template<typename T>
	ComparisonCounter<T>::ComparisonCounter(T data) :
		m_data(data) { }

	template<typename T>
	bool ComparisonCounter<T>::operator==(const ComparisonCounter & other) const
	{
		m_counter++;
		return m_data == other.GetData();
	}

	template<typename T>
	bool ComparisonCounter<T>::operator!=(const ComparisonCounter & other) const
	{
		m_counter++;
		return m_data != other.GetData();
	}

	template<typename T>
	bool ComparisonCounter<T>::operator>(const ComparisonCounter & other) const
	{
		m_counter++;
		return m_data > other.GetData();
	}

	template<typename T>
	bool ComparisonCounter<T>::operator<(const ComparisonCounter & other) const
	{
		m_counter++;
		return m_data < other.GetData();
	}

	template<typename T>
	bool ComparisonCounter<T>::operator>=(const ComparisonCounter & other) const
	{
		m_counter++;
		return m_data >= other.GetData();
	}

	template<typename T>
	bool ComparisonCounter<T>::operator<=(const ComparisonCounter & other) const
	{
		m_counter++;
		return m_data <= other.GetData();
	}
	
	template<typename T>
	T ComparisonCounter<T>::GetData() const
	{
		return m_data;
	}
}
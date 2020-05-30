#pragma once
#include <cstdint>

namespace YAFramework
{
	namespace Sort
	{
		template <typename T>
		void Swap(T* first, T* second)
		{
			T temp = *first;
			*first = *second;
			*second = temp;
		}

		template <typename T>
		std::uint32_t Partition(T arr[], std::uint32_t low, std::uint32_t high, std::uint32_t& numberOfComparissons = 0)
		{
			T pivot = arr[high];
			std::uint32_t i = (low - 1);

			for (std::uint32_t j = low; j <= high - 1; j++)
			{
				numberOfComparissons++;
				if (arr[j] <= pivot)
				{
					i++;
					Swap(&arr[i], &arr[j]);
				}
			}
			Swap(&arr[i + 1], &arr[high]);
			return (i + 1);
		}

		template <typename T>
		void QuickSort(T arr[], std::uint32_t low, std::uint32_t high, std::uint32_t& numberOfComparissons = 0)
		{
			if (low < high)
			{
				std::uint32_t partitionIndex = Partition(arr, low, high, numberOfComparissons);

				if (partitionIndex != 0)
				{
					QuickSort(arr, low, partitionIndex - 1, numberOfComparissons);
				}
				QuickSort(arr, partitionIndex + 1, high, numberOfComparissons);
			}
		}
	}
}
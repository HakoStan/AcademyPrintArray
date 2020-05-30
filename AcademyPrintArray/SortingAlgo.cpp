#include <iostream>
#include "SortingAlgo.hpp"
#include "PlayerList.hpp"
#include "QuickSort.hpp"
#include "BSTree.hpp"
#include "ComparisonCounter.hpp"

int NaivePrint(Player players[], int n, int k)
{
	std::uint32_t numberOfComparissons = 0;
	PlayerList listOfPlayers;

	for (int i = 0; i < n; i++)
	{
		numberOfComparissons++; // TODO :: Check this - maybe not need
		if (players[i].GetId() < k)
		{
			numberOfComparissons += listOfPlayers.Insert(players[i]);
		}
	}

	std::cout << listOfPlayers;
	return numberOfComparissons;
}

int PrintBySort(Player players[], int n, int k)
{
	std::uint32_t numberOfComparissons = 0;

	YAFramework::Sort::QuickSort(players, 0, n - 1, numberOfComparissons);

	for (std::uint32_t i = 0; i < n; i++)
	{
		numberOfComparissons++; // TODO :: Check this - maybe not need
		if (players[i].GetId() >= k)
		{
			break;
		}
		std::cout << players[i] << std::endl;
	}

	return numberOfComparissons;
}

int BSTPrint(Player players[], int n, int k)
{
	std::uint32_t numberOfComparissons = 0;

	YAFramework::BSTree<YAFramework::ComparisonCounter<std::uint32_t>, Player> bsTree;

	for (int i = 0; i < n; i++)
	{
		bsTree.Insert(YAFramework::ComparisonCounter<std::uint32_t>(players[i].GetId()), players[i]);
	}

	bsTree.PrintTreeInorderTillKey(k);

	return YAFramework::ComparisonCounter<std::uint32_t>::m_counter;
}

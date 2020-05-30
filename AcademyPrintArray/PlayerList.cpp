#include "PlayerList.hpp"

// Return number of comparisons
std::uint32_t PlayerList::Insert(Player player)
{
	std::uint32_t numberOfComparisons = 0;

	YAFramework::Node<Player>* playerNode = new YAFramework::Node<Player>(player);
	YAFramework::Node<Player>* temp = m_listOfPlayers.First();

	numberOfComparisons++;
	if (temp == nullptr || player.GetId() <= temp->GetData().GetId())
	{
		m_listOfPlayers.InsertToHead(playerNode);
		return numberOfComparisons;
	}

	while (temp != nullptr)
	{
		if (temp->GetNext() == nullptr)
		{
			break;
		}

		numberOfComparisons++;
		if (player.GetId() <= temp->GetNext()->GetData().GetId())
		{
			break;
		}
		temp = temp->GetNext();
	}

	m_listOfPlayers.InsertAfter(temp, playerNode);
	return numberOfComparisons;
}

std::ostream & operator<<(std::ostream& os, const PlayerList& playerList)
{
	os << playerList.m_listOfPlayers;
	return os;
}

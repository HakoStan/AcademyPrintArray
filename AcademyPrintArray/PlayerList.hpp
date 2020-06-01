#pragma once

#include "Node.hpp"
#include "List.hpp"
#include "Player.hpp"

#include <iostream>


class PlayerList
{
public:
	PlayerList() = default;
	~PlayerList() = default;
	PlayerList(const PlayerList& other) = delete;
	PlayerList(PlayerList&& other) noexcept = delete;
	PlayerList& operator=(const PlayerList& other) = delete;
	PlayerList& operator=(PlayerList&& other) noexcept = delete;

	std::uint32_t Insert(Player player);
	YAFramework::List<Player> GetListOfPlayers();
	friend std::ostream& operator<<(std::ostream& os, const PlayerList& playerList);

private:
	YAFramework::List<Player> m_listOfPlayers;
};


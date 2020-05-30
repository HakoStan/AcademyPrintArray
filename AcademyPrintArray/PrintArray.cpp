#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "PrintArray.hpp"
#include "Player.hpp"
#include "SortingAlgo.hpp"

void PopulatePlayersArray(Player*& players, std::uint32_t numberOfPlayers)
{
	std::cin.ignore();

	players = new Player[numberOfPlayers];
	for  (std::uint32_t i = 0; i < numberOfPlayers; i++)
	{
		std::string line = "";
		std::getline(std::cin, line);
		std::stringstream stringStream(line);

		std::uint32_t id = 0;
		std::string firstName = "";
		std::string lastName = "";
		stringStream >> id >> firstName >> lastName;
		VERIFY_AND_EXIT_PROGRAM((id != 0));
		VERIFY_AND_EXIT_PROGRAM((!firstName.empty()));
		VERIFY_AND_EXIT_PROGRAM((!lastName.empty()));

		for (std::uint32_t j = 0; j < i; j++)
		{
			VERIFY_AND_EXIT_PROGRAM((id != players[j].GetId()));
		}

		players[i].SetFirstName(firstName);
		players[i].SetLastName(lastName);
		players[i].SetId(id);
	}
}

int main()
{
	////////////////////////////////////////////////////////////////////////
	////////////////////////////INPUT///////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	std::uint32_t numberOfPlayers = 0;
	std::cin >> numberOfPlayers;
	VERIFY_AND_EXIT_PROGRAM((numberOfPlayers != 0));

	Player* players = nullptr;
	PopulatePlayersArray(players, numberOfPlayers);
	
	std::string line = "";
	std::getline(std::cin, line);
	std::stringstream stringStream(line);

	std::uint32_t minimalId = 0;
	std::string next = "";
	stringStream >> minimalId >> next;
	VERIFY_AND_EXIT_PROGRAM((next.empty()));

	////////////////////////////////////////////////////////////////////////
	////////////////////////////Algos///////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	std::uint32_t naivePrintComparissons = NaivePrint(players, numberOfPlayers, minimalId);
	std::uint32_t bstPritnComparissons = BSTPrint(players, numberOfPlayers, minimalId);
	std::uint32_t printBySortComparissons = PrintBySort(players, numberOfPlayers, minimalId);

	std::cout << "NaivePrint: " << naivePrintComparissons << " comparissons" << std::endl;
	std::cout << "BSTPrint: " << bstPritnComparissons << " comparissons" << std::endl;
	std::cout << "PrintBySort: " << printBySortComparissons << " comparissons" << std::endl;
}

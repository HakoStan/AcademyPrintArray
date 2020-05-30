#pragma once

#include <string>
#include <iostream>

class Player
{
public:
	Player() = default;
	Player(std::string firstName, std::string lastName, std::uint32_t id);
	~Player() = default;
	Player(const Player& other) = default;
	Player(Player&& other) noexcept = default;
	Player& operator=(const Player& other) = default;
	Player& operator=(Player&& other) noexcept = default;

	friend std::ostream& operator<<(std::ostream& os, const Player& player);

	bool operator==(const Player& other) const;
	bool operator!=(const Player& other) const;
	bool operator<(const Player& other) const;
	bool operator>(const Player& other) const;
	bool operator<=(const Player& other) const;
	bool operator>=(const Player& other) const;
	

	std::uint32_t GetId();

	void SetFirstName(std::string firstName);
	void SetLastName(std::string lastName);
	void SetId(std::uint32_t id);
private:
	std::string m_firstName;
	std::string m_lastName;
	std::uint32_t m_id;
};


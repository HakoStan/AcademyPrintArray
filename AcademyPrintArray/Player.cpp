#include "Player.hpp"

Player::Player(std::string firstName, std::string lastName, std::uint32_t id) :
	m_firstName(firstName), m_lastName(lastName), m_id(id)
{ }

bool Player::operator==(const Player& other) const
{
	return m_id == other.m_id;
}

bool Player::operator!=(const Player& other) const
{
	return m_id != other.m_id;
}

bool Player::operator<(const Player& other) const
{
	return m_id < other.m_id;
}

bool Player::operator>(const Player& other) const
{
	return m_id > other.m_id;
}

bool Player::operator<=(const Player& other) const
{
	return m_id <= other.m_id;
}

bool Player::operator>=(const Player& other) const
{
	return m_id >= other.m_id;
}

std::uint32_t Player::GetId()
{
	return m_id;
}

void Player::SetFirstName(std::string firstName)
{
	this->m_firstName = firstName;
}

void Player::SetLastName(std::string lastName)
{
	this->m_lastName = lastName;
}

void Player::SetId(std::uint32_t id)
{
	this->m_id = id;
}

std::ostream & operator<<(std::ostream & os, const Player & player)
{
	os << player.m_id << " " << player.m_firstName << " " << player.m_lastName;
	return os;
}

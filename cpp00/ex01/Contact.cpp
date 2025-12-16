#include "Contact.hpp"

Contact::Contact() {}

void Contact::setFirstName(std::string name)
{
	firstName = name;
}

void Contact::setLastName(std::string name)
{
	lastName = name;
}

void Contact::setNickName(std::string name)
{
	nickName = name;
}

void Contact::setPhoneNumber(std::string number)
{
	phoneNumber = number;
}

void Contact::setDarkestSecret(std::string secret)
{
	darkestSecret = secret;
}

//getters

std::string	Contact::getFirstName()
{
	return firstName;
}

std::string Contact::getLastName()
{
	return lastName;
}

std::string Contact::getNickName()
{
	return nickName;
}

std::string Contact::getPhoneNumber()
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return darkestSecret;
}


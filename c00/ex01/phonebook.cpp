#include "phonebook.hpp"

void Contact::setFirstName(std::string str)
{
	_firstname = str;
}
void Contact::setLastName(std::string str)
{
	_lastname = str;
}
void Contact::setPhone(std::string str)
{
	_phone = str;
}
std::string Contact::getFirstName(void)
{
	return (_firstname);
}
std::string Contact::getLastName(void)
{
	return (_lastname);
}
std::string Contact::getPhone(void)
{
	return (_phone);
}

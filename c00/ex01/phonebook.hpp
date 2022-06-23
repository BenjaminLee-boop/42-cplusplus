#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>

class Contact
{
public:
	void setFirstName(std::string str);
	void setLastName(std::string str);
	void setPhone(std::string str);

	std::string getFirstName(void);
	std::string getLastName(void);
	std::string getPhone(void);

private:
	std::string _firstname;
	std::string _lastname;
	std::string _phone;
};

#endif
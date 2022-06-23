#include "phonebook.hpp"

std::string truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}

void show_contact(Contact *book, int index)
{
    std::cout << "First name      : " << book[index].getFirstName() << std::endl;
    std::cout << "Last name       : " << book[index].getLastName() << std::endl;
    std::cout << "phone number    : " << book[index].getPhone() << std::endl;
}

void search_book(Contact *book, int count)
{
    int i;
    std::string input;

    if (count == 0)
    {
        std::cout << "No contacts to show." << std::endl
                  << std::endl;
        return;
    }
    for (i = 0; i < count; i++)
    {
        std::cout << "*********************************************" << std::endl;
        std::cout << "|" << std::setw(10) << i + 1;
        std::cout << "|" << std::setw(10) << truncate(book[i].getFirstName());
        std::cout << "|" << std::setw(10) << truncate(book[i].getLastName());
        std::cout << "|" << std::endl;
    }
    std::cout << "*********************************************" << std::endl;
    std::cout << "Select a contact by typing its number." << std::endl
              << std::endl;
    getline(std::cin, input);
    if (input[0] > '0' && input[0] < '9' && input[1] == '\0')
        show_contact(book, stoi(input) - 1);
    std::cout << std::endl;
}

void add_book(Contact **book, int i)
{
    std::string str;

    std::cout << "Please enter contact's first name." << std::endl;
    getline(std::cin, str);
    (*book)[i].setFirstName(str);
    std::cout << "Please enter contact's last name." << std::endl;
    getline(std::cin, str);
    (*book)[i].setLastName(str);
    std::cout << "Please enter contact's phone number." << std::endl;
    getline(std::cin, str);
    (*book)[i].setPhone(str);
}

int main(void)
{
    Contact *book;
    std::string cmd;
    int i;

    i = 0;
    book = new Contact[8];
    while (1)
    {
        getline(std::cin, cmd);
        if (cmd == "SEARCH")
            search_book(book, i);
        else if (cmd == "ADD")
        {
            if (i < 8)
                add_book(&book, i++);
            else
                std::cout << "Too many contacts, can't add anymore." << std::endl
                          << std::endl;
        }
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Invalid command." << std::endl
                      << std::endl;
    }
    delete[] book;
    return (0);
}
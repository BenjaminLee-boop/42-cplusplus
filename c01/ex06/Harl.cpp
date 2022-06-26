#include <iostream>
#include "Harl.hpp"

Harl::Harl(void) : _level(levelDebug)
{
}

Harl::Harl(Harl::filterLevel level) : _level(level)
{
}

Harl::Harl(const std::string &level)
{
    this->_level = this->getLevelFromString(level);
}

Harl::~Harl(void)
{
}

Harl::filterLevel Harl::getLevelFromString(std::string level)
{
    std::string complaintLevels[] = {
        "ERROR",
        "WARNING",
        "INFO",
        "DEBUG"};

    std::transform(level.begin(), level.end(), level.begin(), ::toupper);
    for (int i = 0; i < 4; i++)
    {
        if (level == complaintLevels[i])
            return ((filterLevel)i);
    }
    return (Harl::levelInsignificant);
}

void Harl::complain(const std::string &level)
{
    this->complain(this->getLevelFromString(level));
}

void Harl::complain(Harl::filterLevel level)
{
    if (level <= this->_level)
    {
        switch (level)
        {
        case Harl::levelError:
            this->error();
            break;
        case Harl::levelWarning:
            this->warning();
            break;
        case Harl::levelInfo:
            this->info();
            break;
        case Harl::levelDebug:
            this->debug();
            break;
        default:
            this->defaultMessage();
        }
    }
}

void Harl::defaultMessage(void)
{
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
}

void Harl::debug(void)
{
    std::cout << MAGENTA << "[DEBUG]   " << DEFAULT
              << "I love to get extra bacon for my 7X"
                 "L-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
              << std::endl;
}

void Harl::info(void)
{

    std::cout << GRAY << "[INFO]    " << DEFAULT
              << "I cannot believe adding extra bacon "
                 "cost more money. You don’t put enough! If you did I would not have to "
                 "ask for it!"
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << YELLOW << "[WARNING] " << DEFAULT
              << "I think I deserve to have some ex"
                 "tra bacon for free. I’ve been coming here for years and you just start"
                 "ed working here last month."
              << std::endl;
}

void Harl::error(void)
{
    std::cout << RED << "[ERROR]   " << DEFAULT
              << "This is unacceptable, I want to spe"
                 "ak to the manager now."
              << std::endl;
}

Harl::filterLevel Harl::getLevel(void) const
{
    return (this->_level);
}

bool Harl::setLevel(const filterLevel &newLevel)
{
    this->_level = newLevel;
    return (true);
}

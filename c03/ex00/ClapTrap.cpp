#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(std::string name)
{
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackPoints = 0;
    return;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " was crashed with a hydraulic press." << std::endl;
    return;
}
void ClapTrap::attack(std::string const &target)
{
    std::cout << "ClapTrap " << _name << " attacks " << target;
    std::cout << ", causing " << _attackDamange << " damage points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " has been repaired." << std::endl;
    std::cout << "He has recovered " << amount << " damage points!" << std::endl;

    this->_hitPoints += amount;

    std::cout << _name << "'s total HPs are now " << _hitPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " has been attacked! He gets " << amount << " damage points!" << std::endl;

    this->_hitPoints -= amount;
    if (this->_hitPoints <= 0)
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << _name << " got smashed." << std::endl;
    }
    std::cout << _name << "'s total HPs are now " << _hitPoints << std::endl;
}

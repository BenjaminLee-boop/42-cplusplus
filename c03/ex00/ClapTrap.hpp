#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamange;
    int _attackPoints;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();

    void attack(std::string const &taget);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif

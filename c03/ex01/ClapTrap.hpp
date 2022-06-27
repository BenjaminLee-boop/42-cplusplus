#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
    // unsigned int _attackPoints;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &copy);

    ~ClapTrap();

    void attack(std::string const &taget);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void operator=(const ClapTrap &op);

    void setHitPoints(unsigned int hp);
    void setEnergyPoints(unsigned int hp);
    void setAttackDamange(unsigned int hp);

    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamange() const;
    std::string getName() const;
};

#endif

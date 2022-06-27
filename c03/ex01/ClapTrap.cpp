#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name)
{
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;

    std::cout << "ClapTrap " << getName() << " spawned in 1984 in Los Angeles, looking for Sarah Connor." << std::endl;
    return;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << getName() << " was crashed with a hydraulic press." << std::endl;
    return;
}

void ClapTrap::attack(std::string const &target)
{
    std::cout << "ClapTrap " << getName() << " attacks " << target;
    std::cout << ", causing " << getAttackDamange() << " damage points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << getName() << " has been repaired." << std::endl;
    std::cout << "He has recovered " << amount << " damage points!" << std::endl;

    this->_hitPoints += amount;

    std::cout << getName() << "'s total HPs are now " << getHitPoints() << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << getName() << " has been attacked! He gets " << amount << " points of damage!" << std::endl;

    setHitPoints(_hitPoints - amount);
    if ((getHitPoints()) <= 0)
    {
        setHitPoints(0);
        std::cout << "ClapTrap " << getName() << " got smashed." << std::endl;
    }
    std::cout << getName() << "'s total HPs are now " << getHitPoints() << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    return;
}

void ClapTrap::operator=(const ClapTrap &op)
{
    if (this == &op)
        return;
    _name = op.getName();
    _hitPoints = op.getHitPoints();
    _energyPoints = op.getEnergyPoints();
    _attackDamage = op.getAttackDamange();
}

void ClapTrap::setHitPoints(unsigned int hp)
{
    this->_hitPoints = hp;
}

void ClapTrap::setEnergyPoints(unsigned int ep)
{
    this->_energyPoints = ep;
}

void ClapTrap::setAttackDamange(unsigned int ad)
{
    this->_attackDamage = ad;
}

int ClapTrap::getHitPoints() const
{
    return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
    return (this->_energyPoints);
}

int ClapTrap::getAttackDamange() const
{
    return (this->_attackDamage);
}

std::string ClapTrap::getName() const
{
    return (this->_name);
}

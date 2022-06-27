#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), gateKeeper(false)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamange(30);
    return;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    *this = copy;
    return;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << getName() << " was dropped inside a recipient of melting iron, along with all Cyberdyne Systems tech residues." << std::endl;
    return;
}

void ScavTrap::gaurdGate()
{
    gateKeeper = true;
    std::cout << "ScavTrap " << getName() << " has entered in Gate Keeper mode" << std::endl;
}
void ScavTrap::attack(std::string const &target)
{
    std::cout << "ScavTrap " << getName() << " attacks " << target;
    std::cout << ", causing " << getAttackDamange() << " points of damage!" << std::endl;
}

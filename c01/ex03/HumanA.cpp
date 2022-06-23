#include "HumanA.hpp"

// Create a human a Instance Define a name and a weapon
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    std::cout << "HumanA " << name << " created with ";
    std::cout << weapon.getType() << std::endl;
}

// Fired when humanA is destroyed
HumanA::~HumanA(void)
{
    std::cout << "HumanA " << this->_name << " destroyed" << std::endl;
}

// HumanA is Attacking people Help!
void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
// Humana Is now changing weapons
void HumanA::setWeapon(Weapon weapon)
{
    this->_weapon = weapon;
}

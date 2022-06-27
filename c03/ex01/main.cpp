#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

    ScavTrap trap("T-1000");

    trap.gaurdGate();
    std::cout << "HP : " << trap.getHitPoints() << std::endl;
    std::cout << "EP : " << trap.getEnergyPoints() << std::endl;
    std::cout << "AD : " << trap.getAttackDamange() << std::endl;
    trap.attack("John Connor's Foster Parents");
    trap.takeDamage(100);
    trap.beRepaired(42);

    return (0);
}

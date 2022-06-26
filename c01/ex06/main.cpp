#include "Harl.hpp"
#include <iostream>

void complain(std::string level)
{
    Harl h(level);

    h.complain("DEBUG");
    h.complain("INFO");
    h.complain("WARNING");
    h.complain("ERROR");
    if (h.getLevel() == Harl::levelInsignificant)
        std::cout << "[ Probably complaining about insignificant problems ]"
                  << std::endl;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: \"./harlFilter CompaintLevel\"" << std::endl;
        return (1);
    }
    complain(argv[1]);
}

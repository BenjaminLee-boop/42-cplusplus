#include <iostream>

/*
    Takes a sstring and loops through and returns the number of characters
*/
int ft_strlen(const char *str)
{
    const char *s;

    s = str;
    while (*s)
    {
        s++;
    }
    return (s - str);
}

/*
    Takes a char and returns the char in uppercase.
*/

char ft_toupper(char c)
{

    if (c >= 97 && c <= 122)
    {
        return c - 32;
    }
    return c;
}

/*
    Checks to see if we are calling the program with an argument.
    Then we loop throught the arguments and return the uppercase version of the argument
    if no argument is passed we print LOUD AND UNBEARABLE FEEDBACK NOISE 
*/

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; j < ft_strlen(argv[i]); j++)
            {
                std::cout << ft_toupper(argv[i][j]);
            }
        }
        std::cout << std::endl;
        return (0);
    }
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}
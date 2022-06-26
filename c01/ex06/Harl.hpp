#include <string>

#ifndef Harl_HPP
#define Harl_HPP

#define DEFAULT "\001\033[0;39m\002"
#define RED "\001\033[1;91m\002"
#define YELLOW "\001\033[1;93m\002"
#define MAGENTA "\001\033[1;95m\002"
#define GRAY "\001\033[1;90m\002"

class Harl
{
public:
    enum filterLevel
    {
        levelError = 0,
        levelWarning,
        levelInfo,
        levelDebug,
        levelInsignificant = -1
    };
    Harl(void);
    Harl(const std::string &filterLevel);
    Harl(filterLevel filterLevel);
    ~Harl(void);
    void complain(const std::string &level);
    void complain(filterLevel level);
    filterLevel getLevel(void) const;
    bool setLevel(const filterLevel &newLevel);

private:
    void defaultMessage(void);
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    filterLevel _level;
    filterLevel getLevelFromString(std::string level);
};
#endif

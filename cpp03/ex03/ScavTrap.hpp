#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        virtual ~ScavTrap();
        ScavTrap(const ScavTrap &copy);
        ScavTrap &operator=(const ScavTrap &copy);
        
        void        attack(const std::string &target);
        void        guardGate();
};

#endif
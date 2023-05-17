#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(const std::string &name);
        DiamondTrap(DiamondTrap const &);
        DiamondTrap &operator=(DiamondTrap const &);
        ~DiamondTrap();
    public:
        virtual void attack(const std::string &name);
        void whoAmI1();
        void whoAmI();
        void setHitPoints(const unsigned int x);
        unsigned int getHitPoints(void) const;
        void setEnergyPoints(const unsigned int x);
        unsigned int getEnergyPoints(void) const;
        void setAttackDamage(const unsigned int x);
        unsigned int getAttackDamage(void) const;
        std::string getName(void) const;
        void setName(const std::string &name);
    private:
       std::string name;
};


#endif
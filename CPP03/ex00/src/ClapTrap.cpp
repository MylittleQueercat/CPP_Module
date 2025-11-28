#include "ClapTrap.hpp"

// 默认构造
ClapTrap::ClapTrap()
    : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called for "
              << _name << std::endl;
}

// 带名字构造
ClapTrap::ClapTrap(const std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap name constructor called for "
              << _name << std::endl;
}

// 拷贝构造
ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

// 赋值运算符
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_name         = other._name;
        this->_hitPoints    = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return (*this);
}

// 析构
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for "
              << _name << std::endl;
}

// attack
void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot attack because it has no hit points left!"
                  << std::endl;
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot attack because it has no energy points left!"
                  << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
}

// takeDamage
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " is already out of hit points!" << std::endl;
        return ;
    }

    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;

    std::cout << "ClapTrap " << _name
              << " takes " << amount << " points of damage, "
              << "remaining hit points: " << _hitPoints << std::endl;
}

// beRepaired
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot be repaired because it has no hit points left!"
                  << std::endl;
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot be repaired because it has no energy points left!"
                  << std::endl;
        return ;
    }
    _energyPoints--;
    _hitPoints += amount;

    std::cout << "ClapTrap " << _name
              << " is repaired for " << amount
              << " hit points, total hit points: " << _hitPoints
              << std::endl;
}

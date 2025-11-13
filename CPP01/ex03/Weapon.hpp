#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {
private:
	std::string _type;

public:  
	explicit Weapon(const std::string &type);
	const std::string &getType() const;
	void setType(const std::string &newType);
};

#endif

// explicit用于防止隐式类型转换
// 只能 Weapon w("knife") 不能 Weapon w = "knife"
#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {}

const std::string &Weapon::getType() const {
	return (_type);
}
//返回类型为 std::string & （引用）
//返回的是 _type的引用

void Weapon::setType(const std::string &newType) {
	_type = newType;
}

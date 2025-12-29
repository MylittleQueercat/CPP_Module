#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

// 先告诉编译器后面会提到ICharacter这个类型，但不需要知道具体内容
// 前向声明 forward declaration
// 比互相include要稳
class ICharacter;

class AMateria {
	protected:  
		std::string _type;

	public:  
		AMateria(std::string const& type);
		AMateria(AMateria const& other);
		AMateria& operator=(AMateria const& other);
		virtual ~AMateria(void);

		std::string const& getType(void) const;

		virtual AMateria* clone(void) const=0;

		virtual void use(ICharacter& target);
};

#endif

// virtual就是指，不要按照表面决定，等真正用再看是谁
// 用盒子（AMateria）里的东西，而不是用盒子表面的规则
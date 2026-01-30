#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other) { (void)other; return (*this); }
Intern::~Intern() {}

AForm*	Intern::createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	static const s_entry table[] = {
		{ "shrubbery creation",  &Intern::createShrubbery   },
		{ "robotomy request",    &Intern::createRobotomy    },
		{ "presidential pardon", &Intern::createPresidential}
	};
	// si on veut ajouter des nouveaux forms, ca march et c'est facile

	for (size_t i = 0; i < (sizeof(table) / sizeof(table[0])); ++i)
	{
		if (formName == table[i].name)
		{
			AForm* f = table[i].create(target);
			std::cout << "Intern creates " << f->getName() << std::endl;
			return f;
		}
	}
	std::cout << "Intern couldn't create form \"" << formName << "\": unknown form name" << std::endl;
	return (NULL);
}
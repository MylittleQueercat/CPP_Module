#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    IMateriaSource* src = new MateriaSource();

    AMateria* m1 = new Ice();
    AMateria* m2 = new Cure();
    src->learnMateria(m1);
    src->learnMateria(m2);
    delete m1;
    delete m2;

    ICharacter* me = new Character("me");

    AMateria* tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
}

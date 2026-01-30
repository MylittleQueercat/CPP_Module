#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstddef>
# include <stdint.h>
# include <iostream>
# include "Data.hpp"

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);
        ~Serializer();

    public:
        static uintptr_t serializer(Data *ptr);
        static Data* deserializer(uintptr_t raw);
};

#endif

// uintptr_t : pouvoir contenir une adresse memoire sans perte d'information
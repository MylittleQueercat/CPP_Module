#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

// reinterpret_cast： conversion bas niveau entre un pointeru et un entier
// Aucune donnee n'est copiee ou modifiee, seule l'adresse memoire est reinterpretee
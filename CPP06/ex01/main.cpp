/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:34:54 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:34:55 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data data;
    data.n = 42;
    data.s = "cat school";
    data.x = 10.26;

    Data *original = &data;

    uintptr_t raw = Serializer::serialize(original);
    Data *back = Serializer::deserialize(raw);

    std::cout << "original ptr: " << original << "\n";
    std::cout << "raw value: " << raw << "\n";
    std::cout << "back ptr: " << back << "\n";

    if (back == original)
        std::cout << "OK: pointers are equal\n";
    else
        std::cout << "KO: pointer differ\n";

    std::cout << "back->n = "<< back->n << "\n";
    std::cout << "back->s = "<< back->s << "\n";
    std::cout << "back->x = "<< back->x << "\n";

    return 0;
}
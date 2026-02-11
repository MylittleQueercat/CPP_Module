/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:35:20 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:35:21 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Usage: ./convert <literal>\n";
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:35:01 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:35:02 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cerrno>
# include <limits>
# include <climits>
# include <cctype>
# include <cmath>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

    public:
        static void convert(const std::string &literal);

};

#endif

// <iomanip>： permet de controler le format d'affichage des nombres (precision)
// ex ->  std::cout << std::fixed << std::setprecision(1) << value

// <cstblib>: convertir des chaines de caracteres en nombres (strtod, strtol)
// strtod: chaine de caracters->double
// strtol: chaine de caracters->long
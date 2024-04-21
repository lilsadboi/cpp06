/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:57:23 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/11 18:39:34 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <cmath>
# include <cstdlib>
# include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &obj);
		~ScalarConverter();

		ScalarConverter & operator=(ScalarConverter &src);

	public:
		static void convert(const std::string &input);
};

#endif
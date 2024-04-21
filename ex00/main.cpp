/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:57:20 by gmorelli          #+#    #+#             */
/*   Updated: 2024/03/05 17:36:12 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
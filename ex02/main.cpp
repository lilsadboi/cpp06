/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:47:30 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/11 17:36:27 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base *base;

	base = generate();
	if (!base)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
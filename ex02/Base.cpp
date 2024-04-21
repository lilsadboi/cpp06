/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:49:22 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/11 17:33:48 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
	srand(time(0));
	int i = rand() % 3;
	switch (i)
	{
		case 0:
			std::cout << "generate A" << std::endl;
			return new A;
		case 1:
			std::cout << "generate B" << std::endl;
			return new B;
		case 2:
			std::cout << "generate C" << std::endl;
			return new C;
		default:
			std::cout << "Error" << std::endl;
			return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		if (dynamic_cast<A*>(&p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B*>(&p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << "C" << std::endl;
		else
			std::cout << "Unknown type" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
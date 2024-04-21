/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:47:44 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/11 17:27:59 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
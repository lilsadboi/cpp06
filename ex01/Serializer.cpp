/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:24:41 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/11 16:02:16 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	return ;
}

Serializer::Serializer(Serializer &obj)
{
	(void)obj;
	return ;
}

Serializer::~Serializer()
{
	return ;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	// if (raw % 4 != 0)
	// {
	// 	std::cerr << "Deserialization failed. Invalid pointer address." << std::endl;
	// 	return 0;
	// }
	return reinterpret_cast<Data *>(raw);
}
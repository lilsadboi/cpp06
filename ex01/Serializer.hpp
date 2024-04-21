/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:24:53 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/11 17:49:48 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
	int n;

	Data(int value) : n(value) {}
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer &src);
		~Serializer();
		Serializer &operator=(const Serializer &rhs);

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);
};

#endif

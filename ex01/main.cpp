/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:24:19 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/11 17:50:58 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	// Data	*data;
	// uintptr_t	raw;

	// data = new Data(42);
	// raw = Serializer::serialize(data);
	// std::cout << "raw: " << raw << std::endl;
	// std::cout << "data: " << data << std::endl;
	// std::cout << "data->n: " << data->n << std::endl;
	// delete data;
	// data = Serializer::deserialize(raw);
	// std::cout << "raw: " << raw << std::endl;
	// std::cout << "data: " << data << std::endl;
	// std::cout << "data->n: " << data->n << std::endl;
	// return (0);

    // Data data(42);    

    // uintptr_t serialized_ptr = Serializer::serialize(&data);

    // Data* deserialized_ptr = Serializer::deserialize(serialized_ptr);
    
    // if (deserialized_ptr == &data) {
    //     std::cout << "Serialization and deserialization successful.\n";
    // } else {
    //     std::cout << "Serialization and deserialization failed.\n";
    // }
    // return 0;
	{
		Data data(42);

		uintptr_t raw = Serializer::serialize(&data);
		Data *ptr = Serializer::deserialize(raw);

		std::cout << "          data value = " << data.n << std::endl;
		std::cout << "    original address = " << &data << std::endl;
		std::cout << "  serialized address = " << raw << std::endl;
		std::cout << "deserialized address = " << ptr << std::endl;
	}

	{
		Data *data = new Data(21);

		uintptr_t raw = Serializer::serialize(data);
		Data *ptr = Serializer::deserialize(raw);

		std::cout << "          data value = " << data->n << std::endl;
		std::cout << "    original address = " << data << std::endl;
		std::cout << "  serialized address = " << raw << std::endl;
		std::cout << "deserialized address = " << ptr << std::endl;

		delete data;
	}
	
    return 0;
}
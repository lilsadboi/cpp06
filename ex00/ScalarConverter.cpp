/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:57:27 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/11 18:43:26 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter &obj)
{
	(void)obj;
	return ;
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter &src)
{
	(void)src;
	return *this;
}

static void  dealPseudo(const std::string &input)
{
	std::string str = input;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str[0] == '+')
		str.substr(1);
	else if (str == "nanf" || str == "-inff" || str == "+inff")
		str[input.length() - 1] = '\0';
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

static void dealChar(const std::string &input)
{
	if (input.size() != 3 && input[0] != '\'' && input[input.size() - 1] != '\'')
		std::cerr << "Error: wrong char" << std::endl;
	if (input[1] < 32 || input[1] > 126)
		std::cerr << "Error: wrong char" << std::endl;
	char c = static_cast<char>(input[1]);
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;	
}

static void dealInt(const std::string &input)
{
	std::stringstream ss(input);
	int value;
	int i = static_cast<int>(std::atoi(input.c_str()));
	if (!(ss >> value))
	{
		std::cerr << "Error: wrong int" << std::endl;
		return ;
	}
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{
		std::cerr << "Error: wrong int" << std::endl;
		return ;
	}
	if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

static void dealFloat(const std::string &input)
{
	std::stringstream ss(input);
	float value;
	float f = static_cast<float>(std::strtof(input.c_str(), NULL));
	if (!(ss >> value))
	{
		std::cerr << "Error: wrong float" << std::endl;
		return ;
	}
	if (f < std::numeric_limits<float>::min() || f > std::numeric_limits<float>::max())
	{
		std::cerr << "Error: wrong float" << std::endl;
		return ;
	}
	if (f < 32 || f > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void dealDouble(const std::string &input)
{
	std::stringstream ss(input);
	double value;
	double d = std::strtod(input.c_str(), NULL);
	if (!(ss >> value))
	{
		std::cerr << "Error: wrong double" << std::endl;
		return ;
	}
	if (d < std::numeric_limits<double>::min() || d > std::numeric_limits<double>::max())
	{
		std::cerr << "Error: wrong double" << std::endl;
		return ;
	}
	if (d < 32 || d > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

int checkType(const std::string &input);

void ScalarConverter::convert(const std::string &input)
{
	switch (checkType(input))
	{
		case 0: 
			dealPseudo(input);
			break;
		case 1: 
			dealChar(input);
			break;
		case 2: 
			dealInt(input);
			break;
		case 3: 
			dealFloat(input);
			break;
		case 4: 
			dealDouble(input);
			break;
		default:
			std::cerr << "Error: wrong pseudo" << std::endl;
			break;
	}
}
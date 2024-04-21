/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:58:31 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/11 18:28:55 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

bool isPseudo(const std::string &input)
{
	return (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "inf" || input == "inff" || input == "-inf" || input == "-inff");
}

static bool isChar(const std::string &input)
{
	if (input.size() != 3 || input[0] != '\'' || input[input.size() - 1] != '\'')
		return false;
	if ((input[1] < 65 || input[1] > 90) && (input[1] < 97 || input[1] > 122) && (input[1] < 48 || input[1] > 57))
		return false;
	return true;
}

static bool isInt(const std::string &input)
{
	int i = 0;
	if (input.length() == 0)
		return false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return false;
		i++;
	}
	return true;
}

static bool isFloat(const std::string &input)
{
	int i = 0;
	int dot = 0;
	if (input.length() == 0)
		return false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i])
	{
		if (input[i] == '.')
		{
			if (dot == 1)
				return false;
			dot = 1;
		}
		else if (input[i] != 'f' && (input[i] < '0' || input[i] > '9'))
			return false;
		else if (input[i] == 'f')
		{
			if (input[i + 1] != '\0')
				return false;
			else if (input[i - 1] == '.')
				return false;
			else if (input[i - 1] == '+' || input[i - 1] == '-')
				return false;
		}
		i++;
	}
	return true;
}

static bool isDouble(const std::string &input)
{
	int i = 0;
	int dot = 0;
	if (input.length() == 0)
		return false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	for (; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (dot == 1)
				return false;
			dot = 1;
		}
		else if (input[i] < '0' || input[i] > '9')
			return false;
	}
	return true;
}

int checkType(const std::string &input)
{
	int i = -1;
	
	if (isPseudo(input))
		i = 0;
	else if (isChar(input))
		i = 1;
	else if (isInt(input))
		i = 2;
	else if (isFloat(input))
		i = 3;
	else if (isDouble(input))
		i = 4;
	return i;
}
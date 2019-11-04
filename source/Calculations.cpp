/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculations.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:03:54 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 21:02:11 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"

std::string	Calculations::Add(std::string lhs, std::string rhs)
{
	std::stringstream ret;
	
	double l = atof(lhs.data());
	double r = atof(rhs.data());
	ret << r + l;
	return (ret.str());
}

std::string	Calculations::Sub(std::string lhs, std::string rhs)
{
	std::stringstream ret;

	double l = atof(lhs.data());
	double r = atof(rhs.data());
	ret << l - r;
	return (ret.str());
}

std::string	Calculations::Mul(std::string lhs, std::string rhs)	
{
	std::stringstream ret;

	double l = atof(lhs.data());
	double r = atof(rhs.data());
	ret << l * r;
	return (ret.str());
}

std::string	Calculations::Div(std::string lhs, std::string rhs)
{
	std::stringstream ret;

	double l = atof(lhs.data());
	double r = atof(rhs.data());
	ret << l / r;
	return (ret.str());
}

std::string	Calculations::Mod(std::string lhs, std::string rhs)
{
	std::stringstream ret;

	double l = atof(lhs.data());
	double r = atof(rhs.data());
	ret << fmod(l, r);
	return (ret.str());
}

void	Calculations::outOfBounds(std::string s, eOperandType opType)
{
	long int x = atol(s.data());
	if (opType == Int8 && (x > CHAR_MAX || x < CHAR_MIN))
		throw Errors::OutOfBoundsException8();
	if (opType == Int16 && (x > SHRT_MAX || x < SHRT_MIN))
		throw Errors::OutOfBoundsException16();
	if (opType == Int32 && (x > INT_MAX || x < INT_MIN))
		throw Errors::OutOfBoundsException32();
}

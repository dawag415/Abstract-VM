/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 22:45:25 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 15:51:21 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"

IOperand const	*Factory::createInt8(std::string const &value) const
{
	return (new class Int8(value));
}

IOperand const	*Factory::createInt16(std::string const &value) const
{
	return (new class Int16(value));
}

IOperand const	*Factory::createInt32(std::string const &value) const
{
	return (new class Int32(value));
}

IOperand const	*Factory::createFloat(std::string const &value) const
{
	return (new class Float(value));
}

IOperand const	*Factory::createDouble(std::string const &value) const
{
	return (new class Double(value));
}

IOperand const	*Factory::createOperand(eOperandType type, std::string const &value) const
{
	switch (type)
	{
		case Int8: return createInt8(value);
		case Int16: return createInt16(value);
		case Int32: return createInt32(value);
		case Float: return createFloat(value);
		case Double: return createDouble(value);
		default: return nullptr;
	}
}
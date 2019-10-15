/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:38:24 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 15:51:18 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "avm.hpp"

Int16::Int16(void)
{
}

Int16::Int16(std::string value)
{
	_val = value;
}

Int16::Int16(Int16 &obj)
{
	*this = obj;
}

class Int16 &Int16::operator = (Int16 &obj)
{
	if (this != &obj)
		_val = obj._val;
	return (*this);
}

int Int16::getPrecision( void ) const
{
	return (eOperandType::Int16);
}

eOperandType Int16::getType( void ) const
{
	return (eOperandType::Int16);
}

IOperand const * Int16::operator+( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Add(this->toString(), rhs.toString());
	Calculations::checkRange(res, opType);
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Int16::operator-( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Sub(this->toString(), rhs.toString());
	Calculations::checkRange(res, opType);
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Int16::operator*( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Mul(this->toString(), rhs.toString());
	Calculations::checkRange(res, opType);
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Int16::operator/( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Div(this->toString(), rhs.toString());
	Calculations::checkRange(res, opType);
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Int16::operator%( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Mod(this->toString(), rhs.toString());
	Calculations::checkRange(res, opType);
	return g_Global::factory.createOperand(opType, res);
}

std::string const & Int16::toString( void ) const
{
	return (_val);
}

Int16::~Int16(void)
{
}

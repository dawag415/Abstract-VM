/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:38:30 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 21:02:22 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "avm.hpp"

Int32::Int32(void)
{
}

Int32::Int32(std::string value)
{
	_val = value;
}

Int32::Int32(Int32 &obj)
{
	*this = obj;
}

class Int32 &Int32::operator = (Int32 &obj)
{
	if (this != &obj)
		_val = obj._val;
	return (*this);
}

int Int32::getPrecision( void ) const
{
	return (eOperandType::Int32);
}

eOperandType Int32::getType( void ) const
{
	return (eOperandType::Int32);
}

IOperand const * Int32::operator+( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Add(this->toString(), rhs.toString());
	Calculations::outOfBounds(res, opType);
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Int32::operator-( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Sub(this->toString(), rhs.toString());
	Calculations::outOfBounds(res, opType);
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Int32::operator*( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Mul(this->toString(), rhs.toString());
	Calculations::outOfBounds(res, opType);
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Int32::operator/( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Div(this->toString(), rhs.toString());
	Calculations::outOfBounds(res, opType);
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Int32::operator%( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Mod(this->toString(), rhs.toString());
	Calculations::outOfBounds(res, opType);
	return g_Global::factory.createOperand(opType, res);
}

std::string const & Int32::toString( void ) const
{
	return (_val);
}

Int32::~Int32(void)
{
}

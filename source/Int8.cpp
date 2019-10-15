/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:21:51 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 15:51:19 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"

Int8::Int8(void)
{
}

Int8::Int8(std::string value)
{
	_val = value;
}

Int8::Int8(Int8 &obj)
{
	*this = obj;
}

class Int8 &Int8::operator = (Int8 &obj)
{
	if (this != &obj)
		_val = obj._val;
	return (*this);
}

int	Int8::getPrecision( void ) const
{
	return (eOperandType::Int8);
}

eOperandType Int8::getType( void ) const
{
	return (eOperandType::Int8);
}

IOperand const * Int8::operator+( IOperand const &rhs ) const
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

IOperand const * Int8::operator-( IOperand const &rhs ) const
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

IOperand const * Int8::operator*( IOperand const &rhs ) const
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

IOperand const * Int8::operator/( IOperand const &rhs ) const
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

IOperand const * Int8::operator%( IOperand const &rhs ) const
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

std::string const & Int8::toString( void ) const
{
	return (_val);
}

Int8::~Int8(void)
{
}
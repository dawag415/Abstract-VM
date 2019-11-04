/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:37:25 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 21:02:13 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"

Float::Float(void)
{
}

Float::Float(std::string value)
{
	_val = value;
}

Float::Float(Float &obj)
{
	*this = obj;
}

class Float	&Float::operator = (Float &obj)
{
	if (this != &obj)
		_val = obj._val;
	return (*this);
}

int Float::getPrecision( void ) const
{
	return (eOperandType::Float);
}

eOperandType Float::getType( void ) const
{
	return (eOperandType::Float);
}

IOperand const * Float::operator+( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Add(this->toString(), rhs.toString());
	Calculations::outOfBounds(res, opType);
	std::size_t found = res.find(".");
    if(found == std::string::npos)
		res.append(".0");
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Float::operator-( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Sub(this->toString(), rhs.toString());
	Calculations::outOfBounds(res, opType);
	std::size_t found = res.find(".");
    if(found == std::string::npos)
		res.append(".0");
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Float::operator*( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Mul(this->toString(), rhs.toString());
	Calculations::outOfBounds(res, opType);
	std::size_t found = res.find(".");
    if(found == std::string::npos)
		res.append(".0");
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Float::operator/( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Div(this->toString(), rhs.toString());
	Calculations::outOfBounds(res, opType);
	std::size_t found = res.find(".");
    if(found == std::string::npos)
		res.append(".0");
	return g_Global::factory.createOperand(opType, res);
}

IOperand const * Float::operator%( IOperand const &rhs ) const
{
	eOperandType opType;

	if (rhs.getPrecision() > this->getPrecision())
		opType = rhs.getType();
	else
		opType = this->getType();
	std::string res = Calculations::Mod(this->toString(), rhs.toString());
	Calculations::outOfBounds(res, opType);
	std::size_t found = res.find(".");
    if(found == std::string::npos)
		res.append(".0");
	return g_Global::factory.createOperand(opType, res);
}

std::string const & Float::toString( void ) const
{
	return (_val);
}

Float::~Float(void)
{
}

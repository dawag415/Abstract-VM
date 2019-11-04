/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:36:17 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 21:01:59 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"

Double::Double(void)
{
}

Double::Double(std::string value)
{
	_val = value;
}

Double::Double(Double &obj)
{
	*this = obj;
}

class Double &Double::operator = (Double &obj)
{
	if (this != &obj)
		_val = obj._val;
	return (*this);
}

int Double::getPrecision( void ) const
{
	return (eOperandType::Double);
}

eOperandType Double::getType( void ) const
{
	return (eOperandType::Double);
}

IOperand const * Double::operator+( IOperand const &rhs ) const
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

IOperand const * Double::operator-( IOperand const &rhs ) const
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

IOperand const * Double::operator*( IOperand const &rhs ) const
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

IOperand const * Double::operator/( IOperand const &rhs ) const
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

IOperand const * Double::operator%( IOperand const &rhs ) const
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

std::string const & Double::toString( void ) const
{
	return (_val);
}

Double::~Double(void)
{
}

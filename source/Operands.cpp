/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:38:43 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 16:50:57 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "avm.hpp"

Operands::Operands(void)
{	
}

Operands::~Operands(void)
{
}

Operands::Operands(Operands &obj)
{
	*this = obj;
}

Operands &Operands::operator = (const Operands &)
{
	return (*this);
}

void	Operands::clear(void)
{
	while (_stack.size())
	{
		delete _stack.back();
		_stack.pop_back();
	}
}

void	Operands::push(IOperand const *x)
{
	_stack.push_back(x);
}

void	Operands::pop(void)
{
	if (!_stack.size())
		throw EmptyStackException();
	_stack.erase(_stack.end() - 1);	
}

void	Operands::dump(void)
{
	for (int i = _stack.size() - 1; i >= 0; i--)
		g_Global::output << _stack[i]->toString() << std::endl;
}

void	Operands::asserts(IOperand const *x)
{
	if (!_stack.size())
		throw EmptyStackException();
	if (x->getType() != (_stack[_stack.size() - 1]->getType()))
		throw AssertTypeFailureException();
	if (x->toString() != _stack[_stack.size() - 1]->toString())
		throw AssertValueFailureException();		
}

void	Operands::add(void)
{
	IOperand const *rhs;
	IOperand const *lhs;
	
	if (_stack.size() < 2)
		throw ShortStackException();
	rhs = _stack.back();
	_stack.pop_back();
	lhs = _stack.back();
	_stack.pop_back();
	try
	{
		_stack.push_back(*lhs + *rhs);
	}
	catch (std::exception &e)
	{
		delete rhs;
		delete lhs;
		throw e;
	}
}

void	Operands::sub(void)
{
	IOperand const *rhs;
	IOperand const *lhs;

	if (_stack.size() < 2)
		throw ShortStackException();
	rhs = _stack.back();
	_stack.pop_back();
	lhs = _stack.back();
	_stack.pop_back();
	try
	{
		_stack.push_back(*lhs - *rhs);
	}
	catch (std::exception &e)
	{
		delete rhs;
		delete lhs;
		throw e;
	}
}

void	Operands::mul(void)
{
	IOperand const *rhs;
	IOperand const *lhs;
	
	if (_stack.size() < 2)
		throw ShortStackException();
	rhs = _stack.back();
	_stack.pop_back();
	lhs = _stack.back();
	_stack.pop_back();
	try
	{
		_stack.push_back(*lhs * *rhs);
	}
	catch (std::exception &e)
	{
		delete rhs;
		delete lhs;
		throw e;
	}
}

void	Operands::div(void)
{
	IOperand const *rhs;
	IOperand const *lhs;
	
	if (_stack.size() < 2)
		throw ShortStackException();
	rhs = _stack.back();
	_stack.pop_back();
	lhs = _stack.back();
	_stack.pop_back();
	if (atof(rhs->toString().data()) == 0)
	{
		delete rhs;
		delete lhs;
		throw DivisionByZeroException();
	}
	try
	{
		_stack.push_back(*lhs / *rhs);
	}
	catch (std::exception &e)
	{
		delete rhs;
		delete lhs;
		throw e;
	}
}

void	Operands::mod(void)
{
	IOperand const *rhs;
	IOperand const *lhs;

	if (_stack.size() < 2)
		throw ShortStackException();
	rhs = _stack.back();
	_stack.pop_back();
	lhs = _stack.back();
	_stack.pop_back();
	if (atof(rhs->toString().data()) == 0)
	{
		delete rhs;
		delete lhs;
		throw DivisionByZeroException();
	}
	_stack.push_back(*lhs % *rhs);
	delete rhs;
	delete lhs;
}

void	Operands::print(void)
{
	if (!_stack.size())
		throw EmptyStackException();
	long int x = atol(_stack.back()->toString().data());
	g_Global::output << static_cast<char>(x) << std::endl;
}

void	Operands::exit(void)
{
	std::exit(EXIT_SUCCESS);	
}

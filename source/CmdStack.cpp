/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdStack.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:07:10 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 16:50:54 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "avm.hpp"

CmdStack::CmdStack(void)
{
	_exitCode = false;
}

CmdStack::~CmdStack(void)
{
	_stack.clear();
}

CmdStack::CmdStack(CmdStack &obj)
{
	*this = obj;
}

CmdStack &CmdStack::operator = (const CmdStack &obj)
{
	if (this != &obj)
	{
		_stack = obj._stack;
		_type = obj._type;
		_cmd = obj._cmd;
		_val = obj._val;
		_exitCode = obj._exitCode;
	}
	return (*this);
}

void	CmdStack::validateRange(eOperandType type, std::string value)
{
	value.erase(0, value.find('(') + 1);	
	value.erase(value.find(')'));
	long int x = atol(value.data());
	double f = atof(value.data());

	if ((type == Int8 && x >= CHAR_MIN && x <= CHAR_MAX) ||
	    (type == Int16 && x >= SHRT_MIN && x <= SHRT_MAX) ||
	    (type == Int32 && x >= INT_MIN && x <= INT_MAX) ||
	    ((type == Double || type == Float) && isfinite(f)))
	{
		_val = value;
		_type = type;
	}
	else
		throw OutOfBoundsException();
}

void CmdStack::runCommandCode()
{
	switch (_cmd)
	{
		case Push: _stack.push(g_Global::factory.createOperand(_type, _val));
			break; 
		case Pop: _stack.pop();
			break;
		case Dump: _stack.dump();
			break;
		case Assert: _stack.asserts(g_Global::factory.createOperand(_type, _val));
			break;
		case Add: _stack.add();
			break;
		case Sub: _stack.sub();
			break;
		case Mul: _stack.mul();
			break;
		case Div: _stack.div();
			break;
		case Mod: _stack.mod();
			break;
		case Print: _stack.print();
			break;
		case Exit: _exitCode = true;
			break;
	}
}

void CmdStack::parseCommandCodes(std::string cmd)
{
	if (std::regex_match(cmd, std::regex("push.*")))
		_cmd = Push;
	else if (cmd == "pop")
		_cmd = Pop;		
	else if (cmd == "dump")
		_cmd = Dump;
	else if (std::regex_match(cmd, std::regex("assert.*")))
		_cmd = Assert;
	else if (cmd == "add")
		_cmd = Add;		
	else if (cmd == "sub")
		_cmd = Sub;
	else if (cmd == "mul")
		_cmd = Mul;
	else if (cmd == "div")
		_cmd = Div;
	else if (cmd == "mod")
		_cmd = Mod;
	else if (cmd == "print")
		_cmd = Print;
	else if (cmd == "exit")
		_cmd = Exit;
	else
		throw BadSyntaxException();
}

void CmdStack::parseValues(std::string value)
{
	if (std::regex_match(value, std::regex("int8\\([-]?[0-9]+\\)")))
		validateRange(Int8, value);
	else if (std::regex_match(value, std::regex("int16\\([-]?[0-9]+\\)")))
		validateRange(Int16, value);
	else if (std::regex_match(value, std::regex("int32\\([-]?[0-9]+\\)")))
		validateRange(Int32, value);
	else if (std::regex_match(value, std::regex("float\\([-]?[0-9]+[.][0-9]+\\)")))
		validateRange(Float, value);
	else if (std::regex_match(value, std::regex("double\\([-]?[0-9]+[.][0-9]+\\)")))
		validateRange(Double, value);
	else
		throw BadSyntaxException();	
}

void CmdStack::uncomment(std::string &line)
{
	if (line.find(';') != std::string::npos)
		line.erase(line.find(';'));
	line.erase(line.find_last_not_of(' ') + 1);
}

void CmdStack::runLexer(std::string line)
{
	uncomment(line);
	if (line.empty())
		return;
	parseCommandCodes(line);
	if (_cmd == Push || _cmd == Assert)
	{
		line.erase(0, line.find(' ') + 1);
		parseValues(line);
	}
	if (!_exitCode)
		runCommandCode();
}

bool CmdStack::checkExit(void)
{
	return (_exitCode);
}

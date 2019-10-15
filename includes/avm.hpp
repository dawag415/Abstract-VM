/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avm.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:27:58 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 15:51:44 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AVM_HPP
#define AVM_HPP


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>
#include <cmath>

enum eOperandType
{
	Int8, Int16, Int32, Float, Double
};
enum eCommandCode
{
	Push, Pop, Dump, Assert, Add, Sub, Mul, Div, Mod, Print, Exit
};

#include "IOperand.hpp"
#include "Factory.hpp"

struct g_Global
{
	static Factory factory;
	static std::stringstream output;
	static std::stringstream errorOutput;
};

#include "CmdStack.hpp"
#include "Operands.hpp"

#include "Int8.hpp"
#include "Int16.hpp"
#include "Int32.hpp"
#include "Float.hpp"
#include "Double.hpp"
#include "Calculations.hpp"
#include "Errors.hpp"



class Errors;
class CmdStack;
class Factory;
class IOperand;
class Int8;
class Int16;
class Int32;
class Float;
class Double;
class Operands;



#endif
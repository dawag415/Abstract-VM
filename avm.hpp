
#ifndef AVM_HPP
#define AVM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>





#include "CmdStack.hpp"
#include "Factory.hpp"
#include "IOperand.hpp"
#include "macros.hpp"

class CmdStack;
class Factory;
class IOperand;



struct	g_Global
{
	static std::stringstream output;
	static std::stringstream errorOutput;
	static OperandFactory factory;	
};
enum eOperandType
{
	Int8, Int16, Int32, Float, Double
};


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdStack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:28:10 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 16:06:04 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDSTACK_HPP
#define CMDSTACK_HPP

#include "avm.hpp"
#include "Errors.hpp"
#include "Operands.hpp"

class	CmdStack : public Errors
{
	private:
		Operands _stack;	
		eOperandType _type;
		eCommandCode _cmd;
		std::string _val;
		bool _exitCode;
       
		void runCommandCode(void);
		void validateRange(eOperandType type, std::string value);
		void parseCommandCodes(std::string cmd);
		void parseValues(std::string value);
		void uncomment(std::string &line);

	public:
		CmdStack(void);
		CmdStack(CmdStack &obj);
		CmdStack &operator=(const CmdStack &obj);
		void runLexer(std::string line);
		bool checkExit(void);
		virtual	~CmdStack(void);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:38:45 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 15:51:30 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OPERANDS_HPP
#define OPERANDS_HPP

#include "avm.hpp"
#include "IOperand.hpp"

class	Operands : public Errors
{
	private:
		std::vector<IOperand const *> _stack;

	public:
		Operands(void);
		Operands(Operands &obj);
		Operands &operator=(const Operands &);
		void push(IOperand const *);
		void pop(void);
		void dump(void);
		void asserts(IOperand const *);
		void add(void);
		void sub(void);
		void mul(void);
		void div(void);
		void mod(void);
		void print(void);
		void exit(void);
		void clear(void);
		virtual ~Operands(void);
};

#endif

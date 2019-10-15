/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:37:47 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 15:51:33 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
#define INT8_HPP

#include "avm.hpp"

class	Int8 : public IOperand
{
    private:
		std::string _val;
		Int8(void);

	public:
		Int8(std::string value);
		Int8(Int8 &obj);
		Int8 &operator=(Int8 &obj);
	
		int getPrecision( void ) const;
		eOperandType getType( void ) const;

		IOperand const * operator+( IOperand const &rhs ) const;
		IOperand const * operator-( IOperand const &rhs ) const;
		IOperand const * operator*( IOperand const &rhs ) const;
		IOperand const * operator/( IOperand const &rhs ) const;
		IOperand const * operator%( IOperand const &rhs ) const;

		std::string const & toString( void ) const;

		virtual	~Int8(void);
};

#endif

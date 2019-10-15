/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:38:32 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 15:51:32 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_HPP
#define INT32_HPP

#include "avm.hpp"

class	Int32 : public IOperand
{
    private:
       	std::string _val;
        Int32(void);

    public:
	    Int32(std::string value);
        Int32(Int32 &obj);
	    Int32 &operator=( Int32 &obj);
	
	    int getPrecision( void ) const;
	    eOperandType getType( void ) const;

	    IOperand const * operator+( IOperand const &rhs ) const;
	    IOperand const * operator-( IOperand const &rhs ) const;
	    IOperand const * operator*( IOperand const &rhs ) const;
	    IOperand const * operator/( IOperand const &rhs ) const;
	    IOperand const * operator%( IOperand const &rhs ) const;

	    std::string const & toString( void ) const;
    
        virtual ~Int32(void);
};

#endif
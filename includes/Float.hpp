/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:37:29 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 15:51:35 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
#define FLOAT_HPP

#include "avm.hpp"

class	Float : public IOperand
{
    private:
       	std::string _val;
        Float(void);

    public:
	    Float(std::string value);
        Float(Float &obj);
	    Float &operator=(Float &obj);
	
	    int getPrecision( void ) const;
	    eOperandType getType( void ) const;

	    IOperand const * operator+( IOperand const &rhs ) const;
	    IOperand const * operator-( IOperand const &rhs ) const;
	    IOperand const * operator*( IOperand const &rhs ) const;
	    IOperand const * operator/( IOperand const &rhs ) const;
	    IOperand const * operator%( IOperand const &rhs ) const;

	    std::string const & toString( void ) const;
    
        virtual ~Float(void);
};

#endif
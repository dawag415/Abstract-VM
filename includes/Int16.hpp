/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int16.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:38:27 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 15:51:32 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT16_HPP
#define INT16_HPP

#include "avm.hpp"

class	Int16 : public IOperand
{
    private:
       	std::string _val;
        Int16(void);

    public:
	    Int16(std::string value);
        Int16(Int16 &obj);
	    Int16 &operator=(Int16 &obj);
	
	    int getPrecision( void ) const;
	    eOperandType getType( void ) const;

	    IOperand const * operator+( IOperand const &rhs ) const;
	    IOperand const * operator-( IOperand const &rhs ) const;
	    IOperand const * operator*( IOperand const &rhs ) const;
	    IOperand const * operator/( IOperand const &rhs ) const;
	    IOperand const * operator%( IOperand const &rhs ) const;

	    std::string const & toString( void ) const;
    
        virtual ~Int16(void);
};

#endif

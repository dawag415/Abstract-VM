/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:37:19 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 15:51:38 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
#define DOUBLE_HPP

#include "avm.hpp"

class	Double : public IOperand
{
    private:
       	std::string _val;
        Double(void);

    public:
	    Double(std::string value);
        Double(Double &obj);
	    Double &operator=(Double &obj);
	
	    int getPrecision( void ) const;
	    eOperandType getType( void ) const;

	    IOperand const * operator+( IOperand const &rhs ) const;
	    IOperand const * operator-( IOperand const &rhs ) const;
	    IOperand const * operator*( IOperand const &rhs ) const;
	    IOperand const * operator/( IOperand const &rhs ) const;
	    IOperand const * operator%( IOperand const &rhs ) const;

	    std::string const & toString( void ) const;
    
        virtual ~Double(void);
};

#endif

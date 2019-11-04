/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:24:48 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 22:32:50 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avm.hpp"

const char	*Errors::BadSyntaxException::what() const throw()
{
	return ("The syntax is incorrect. Check the subject for proper syntax.\n");
}
const char	*Errors::OutOfBoundsException::what() const throw()
{
	return ("Value is out of bounds for type.\nOnly enter values in the proper range for the specific type.\n");
}
const char	*Errors::OutOfBoundsException8::what() const throw()
{
	return ("Value is out of bounds for type INT8. Only enter values in the proper range for INT8. \n");
}
const char	*Errors::OutOfBoundsException16::what() const throw()
{
	return ("Value is out of bounds for type INT16. Only enter values in the proper range for INT16. \n");
}
const char	*Errors::OutOfBoundsException32::what() const throw()
{
	return ("Value is out of bounds for type INT32. Only enter values in the proper range for INT32. \n");
}
const char	*Errors::OverUnderException::what() const throw()
{
	return ("OVERFLOW or UNDERFLOW due to arithmatic instruction.\n");
}
const char	*Errors::EmptyStackException::what() const throw()
{
        return ("No values on the stack. Operation could not be performed.\n");
}
const char	*Errors::AssertValueFailureException::what() const throw()
{
	return ("Assert failure - Values do not match\n");
}

const char	*Errors::AssertTypeFailureException::what() const throw()
{
	return ("Assert failure - Types do not match\n");
}

const char	*Errors::ShortStackException::what() const throw()
{
	return ("Less than two values on the stack. Operation could not be performed. \n");
}

const char	*Errors::DivisionByZeroException::what() const throw()
{
	return ("Division by ZERO encountered. Opperation could not be performed. \n");
}



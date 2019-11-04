/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 17:24:38 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 22:32:38 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_HPP
#define ERRORS_HPP

#include "avm.hpp"

class	Errors
{
	public:
		class BadSyntaxException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class OutOfBoundsException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class OutOfBoundsException8 : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class OutOfBoundsException16 : public std::exception
		{
			public:
			virtual	const char	*what() const throw();
		};
		class OutOfBoundsException32 : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class OverUnderException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class EmptyStackException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class AssertValueFailureException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class AssertTypeFailureException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class ShortStackException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class DivisionByZeroException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif

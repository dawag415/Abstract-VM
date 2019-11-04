/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Calculations.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwagner <iwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:35:42 by iwagner           #+#    #+#             */
/*   Updated: 2019/10/14 21:02:01 by iwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATIONS_HPP
#define CALCULATIONS_HPP

#include "avm.hpp"

namespace	Calculations
{
	std::string	Add(std::string lhs, std::string rhs);
	std::string	Sub(std::string lhs, std::string rhs);
	std::string	Mul(std::string lhs, std::string rhs);
	std::string	Div(std::string lhs, std::string rhs);
	std::string	Mod(std::string lhs, std::string rhs);

	void outOfBounds(std::string s, eOperandType opType);
}

#endif
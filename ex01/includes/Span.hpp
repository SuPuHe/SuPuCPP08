/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:49:41 by omizin            #+#    #+#             */
/*   Updated: 2025/12/26 13:28:54 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <list>
#include <cstdlib>
#include <ctime>

class Span
{
	private:
		unsigned int			_N;
		std::vector<int>		_numbers;
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &copy);
		Span &operator=(Span const &copy);
		~Span();

		void	addNumber(int number);
		long	shortestSpan();
		long	longestSpan();

		template <typename It> void addIterators(It begin, It end);
};

#include "Span.tpp"

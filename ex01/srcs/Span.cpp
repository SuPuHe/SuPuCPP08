/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:51:43 by omizin            #+#    #+#             */
/*   Updated: 2025/12/26 13:06:12 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _N(0), _numbers() {}

Span::Span(unsigned int N): _N(N) { _numbers.reserve(N); }

Span::Span(const Span& copy) :_N(copy._N), _numbers(copy._numbers) {}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		_N = copy._N;
		_numbers = copy._numbers;
	}
	return *this;
}

Span::~Span(){}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _N)
		throw std::out_of_range("Span is full");
	_numbers.push_back(number);
}

long	Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::length_error("Couldn't find span because of < 2 elements");
	std::vector<int> tmp(_numbers);
	std::sort(tmp.begin(), tmp.end());

	long shortest = static_cast<long>(tmp[1]) - static_cast<long>(tmp[0]);
	for(size_t i = 2; i < tmp.size(); i++){
		long diff = static_cast<long>(tmp[i]) - static_cast<long>(tmp[i - 1]);
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

long	Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::length_error("Couldn't find span because of < 2 elements");

	auto [min_it, max_it] = std::minmax_element(_numbers.begin(), _numbers.end());
	return static_cast<long>(*max_it) - static_cast<long>(*min_it);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:51:43 by omizin            #+#    #+#             */
/*   Updated: 2026/04/06 12:29:49 by omizin           ###   ########.fr       */
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

	long shortest = tmp[1] - tmp[0];
	for(size_t i = 2; i < tmp.size(); i++){
		long diff = tmp[i] - tmp[i - 1];
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
	return *max_it - *min_it;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 13:25:13 by omizin            #+#    #+#             */
/*   Updated: 2025/12/26 13:27:50 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename It>
void	Span::addIterators(It begin, It end)
{
	if (_numbers.size() + std::distance(begin, end) > _N)
		throw std::out_of_range("Span is full");

	_numbers.insert(_numbers.end(), begin, end);
}

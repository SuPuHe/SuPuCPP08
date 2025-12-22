/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:43:06 by omizin            #+#    #+#             */
/*   Updated: 2025/12/22 15:15:48 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it =  std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::exception();
	return it;
}

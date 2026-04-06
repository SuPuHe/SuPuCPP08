/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:44:50 by omizin            #+#    #+#             */
/*   Updated: 2026/04/06 12:18:58 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <deque>

int main()
{
	std::cout << "Deque test\n" << std::endl;
	std::deque<int> d = {1, 2, 3, 4, 5};

	std::cout << "Container: ";
	for (size_t i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;

	try
	{
		std::deque<int>::iterator it = easyfind(d, 3);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "Value not found" << std::endl;
	}

	try
	{
		easyfind(d, 325);
	}
	catch (const std::exception&)
	{
		std::cout << "Value not found" << std::endl;
	}

	std::cout << "\nVector test\n" << std::endl;
	std::vector<int> v = {1, 2, 3, 4, 5};

	std::cout << "Container: ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "Value not found" << std::endl;
	}
	try
	{
		easyfind(v, 325);
	}
	catch (const std::exception&)
	{
		std::cout << "Value not found" << std::endl;
	}

	std::cout << "\nList test\n" << std::endl;
	std::list<int> l = {1, 2, 3, 4, 5};

	std::cout << "Container: ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	try
	{
		std::list<int>::iterator it = easyfind(l, 3);
		std::cout << "Found value: " << *it << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "Value not found" << std::endl;
	}
	try
	{
		easyfind(l, 325);
	}
	catch (const std::exception&)
	{
		std::cout << "Value not found" << std::endl;
	}
	return 0;
}

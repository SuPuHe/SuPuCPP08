/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omizin <omizin@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:13:34 by omizin            #+#    #+#             */
/*   Updated: 2025/12/26 13:46:14 by omizin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int erewrew()
{
	std::cout << "===== BASIC TEST =====" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== EXCEPTION TEST =====" << std::endl;
	try
	{
		Span sp(1);
		sp.addNumber(5);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== OVERFLOW TEST =====" << std::endl;
	try
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== COPY TEST =====" << std::endl;
	try
	{
		Span original(3);
		original.addNumber(1);
		original.addNumber(10);
		original.addNumber(20);

		Span copy = original;
		copy.addNumber(30); // should throw

		std::cout << copy.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== RANGE INSERT TEST =====" << std::endl;
	try
	{
		std::vector<int> v;
		for (int i = 0; i < 100; i++)
			v.push_back(i * 2);

		Span sp(100);
		sp.addIterators(v.begin(), v.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== BIG TEST (10 000 numbers) =====" << std::endl;
	try
	{
		const int SIZE = 10000;
		Span sp(SIZE);
		std::vector<int> v(SIZE);

		std::srand(static_cast<unsigned>(std::time(NULL)));
		for (int i = 0; i < SIZE; i++)
			v[i] = std::rand();

		sp.addIterators(v.begin(), v.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== ALL TESTS PASSED =====" << std::endl;
	return 0;
}

int	main()
{
	std::cout << "Manual test\n" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(-3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTest with < than 2 elemens\n" << std::endl;
	try
	{
		Span sp(1);
		sp.addNumber(6);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nOverflow test\n" << std::endl;
	try
	{
		Span sp(1);
		sp.addNumber(6);
		sp.addNumber(-3);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nCopy test\n" << std::endl;
	try
	{
		Span sp(2);
		sp.addNumber(6);
		sp.addNumber(-3);

		Span copy = sp;
		copy.addNumber(17);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nVector insert test\n" << std::endl;
	try
	{
		std::vector<int> v;
		for (int i = 0; i < 100; ++i)
			v.push_back(i * 2);

		Span sp(100);
		sp.addIterators(v.begin(), v.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nTest with 10000 numbers\n" << std::endl;
	try
	{
		const int SIZE = 10000;
		Span sp(SIZE);
		std::vector<int> v(SIZE);

		srand(time(NULL));
		for (int i = 0; i < SIZE; ++i)
			v[i] = std::rand();

		sp.addIterators(v.begin(), v.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}

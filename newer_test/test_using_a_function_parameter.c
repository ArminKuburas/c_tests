/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_using_a_function_parameter.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:01:49 by akuburas          #+#    #+#             */
/*   Updated: 2024/05/30 14:14:57 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	add(int a, int b)
{
	return (a + b);
}

int	subtract(int a, int b)
{
	return (a - b);
}

int	do_math(int (*func)(int, int), int a, int b)
{
	return (func(a, b));
}

int	main(void)
{
	int	(*func)(int, int);
	int	a;
	int	b;

	func = add;
	a = 10;
	b = 5;
	printf("Result: %d\n", do_math(func, a, b));
	func = subtract;
	printf("Result: %d\n", do_math(func, a, b));
	printf("Result without using a function pointer: %d\n", do_math(subtract, a, b));
	printf("Result without using a function pointer: %d\n", do_math(add, a, b));
	return (0);
}

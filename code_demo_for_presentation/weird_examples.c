/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weird_examples.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:38:15 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/04 01:09:39 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
/*
Using bitwise XOR to swap two integers without using a temporary variable.
It works like this:
a = 5 = 0101
b = 10 = 1010
a = a ^ b = 0101 ^ 1010 = 1111
b = a ^ b = 1111 ^ 1010 = 0101
a = a ^ b = 1111 ^ 0101 = 1010
*/
void	ft_swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int	main(void)
{
	int		a;
	int		b;
	int		i;

	a = 5;
	b = 10;
	printf("Before swap: a = %d, b = %d\n", a, b);
	ft_swap(&a, &b);
	printf("After swap: a = %d, b = %d\n", a, b);
	i = 0;
	i = (i++);
	printf("i = %d\n", i);
	return (0);
}

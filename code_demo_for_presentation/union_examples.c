/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_examples.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 02:23:46 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/04 02:24:14 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

union	u_example
{
	int		a;
	float	b;
};

int	main(void)
{
	union u_example	example;

	example.a = 5;
	printf("a = %d\n", example.a);
	example.b = 5.5;
	printf("b = %f\n", example.b);
	printf("a = %d\n", example.a);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_examples.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 02:22:51 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/04 02:23:03 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

enum	e_example
{
	EXAMPLE1,
	EXAMPLE2,
	EXAMPLE3
};

int	main(void)
{
	enum e_example	example;

	example = EXAMPLE1;
	printf("example = %d\n", example);
	example = EXAMPLE2;
	printf("example = %d\n", example);
	example = EXAMPLE3;
	printf("example = %d\n", example);
	return (0);
}
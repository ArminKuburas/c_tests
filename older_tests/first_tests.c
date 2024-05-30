/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:00:51 by akuburas          #+#    #+#             */
/*   Updated: 2023/12/20 09:04:08 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int		x;
	char	*str;

	x = 5;
	str = "Hello World";
	while ((x == 5), (x)-- > 1)
		printf("test\n");
	printf("character string %c\n", 2[str]);
	printf("character string %c\n", *(str + 2));
	return (0);
}
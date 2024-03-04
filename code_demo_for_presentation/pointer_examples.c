/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_examples.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 02:11:48 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/04 02:20:49 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_free(int *arr)
{
	free(arr);
	arr = NULL;
}

int	main(void)
{
	int		a;
	int		*b;
	int		**c;
	int		*arr;

	a = 5;
	b = &a;
	c = &b;
	arr = malloc(sizeof(int) * 5);
	*arr = 5;
	printf("a = %d\n", a);
	printf("b = %d\n", *b);
	printf("c = %d\n", **c);
	printf("arr[0] = %d\n", *arr);
	ft_free(arr);
	if (arr == NULL)
		printf("arr is NULL\n");
	else
		printf("arr[0] = %d\n", *arr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_variable_examples.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 02:26:15 by akuburas          #+#    #+#             */
/*   Updated: 2024/03/04 02:26:31 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		g_example;

void	ft_example(void)
{
	g_example = 5;
}

int	main(void)
{
	g_example = 10;
	printf("g_example = %d\n", g_example);
	ft_example();
	printf("g_example = %d\n", g_example);
	return (0);
}
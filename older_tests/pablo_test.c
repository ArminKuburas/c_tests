/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pablo_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:52:58 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/20 00:22:20 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pablo_header.h"

int	main(void)
{
	t_Mystruct	mystruct;
	int			i;

	mystruct.example_one = "123456";
	mystruct.example_two = (char *[]){"Hello World1", "Hello World2", NULL};
	i = -1;
	while (mystruct.example_one[++i] != '\0' && mystruct.example_two[i] != NULL)
	{
		printf("%s\n", mystruct.example_two[i]);
		printf("%c\n", mystruct.example_one[i]);
	}
	return (0);
}

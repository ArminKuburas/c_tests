/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_weird_thing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:14:58 by akuburas          #+#    #+#             */
/*   Updated: 2024/05/30 14:17:48 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//make sure to compile with -trigraphs flag
int	main(void)
{
	if (1 || 0)
		printf("This will print\n");
	if (1 ??!??! 0)
		printf("This will not print\n");
	return (0);
}

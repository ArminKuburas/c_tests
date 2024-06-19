/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/06/19 10:26:35 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

void	free_hash(t_hash *hash_table, int table_size)
{
	int	i;

	i = 0;
	while (i < table_size)
	{
		if (hash_table[i].key)
			free(hash_table[i].key);
		i++;
	}
	free(hash_table);
}

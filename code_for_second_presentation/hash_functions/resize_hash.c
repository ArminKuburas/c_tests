/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:11:54 by akuburas          #+#    #+#             */
/*   Updated: 2024/06/19 10:16:42 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

int	resize_hash(int new_size, t_hash **hash_table, int table_size)
{
	t_hash	*new_table;
	t_hash	*old_table;
	int		i;

	new_table = (t_hash *)malloc(sizeof(t_hash) * new_size);
	if (!new_table)
		return (1);
	old_table = *hash_table;
	*hash_table = new_table;
	i = 0;
	while (i < table_size)
	{
		if (old_table[i].key)
		{
			insert_hash(new_table, old_table[i].key, new_size);
			free(old_table[i].key);
		}
		i++;
	}
	free(old_table);
	return (0);
}
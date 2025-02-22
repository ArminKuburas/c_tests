/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 08:53:06 by akuburas          #+#    #+#             */
/*   Updated: 2025/02/04 08:57:07 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:33:10 by akuburas          #+#    #+#             */
/*   Updated: 2024/05/30 13:35:11 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static t_hash	*search_collision(t_hash *hash_table, char *key,
	unsigned long hash, int table_size)
{
	int	i;
	int	old_index;

	old_index = hash % table_size;
	if (old_index == table_size - 1)
		i = 0;
	else
		i = old_index + 1;
	while (hash_table[i].key)
	{
		if (hash_table[i].value == hash)
			if (ft_strcmp(hash_table[i].key, key) == 0)
				return (&hash_table[i]);
		i++;
		if (i == table_size && (old_index == 0 || old_index == table_size - 1))
			return (NULL);
		else if (i == table_size && old_index != table_size - 1)
			i = 0;
		if (i == old_index)
			return (NULL);
	}
	return (NULL);
}

t_hash	*search_hash(t_hash *hash_table, char *key, int table_size)
{
	unsigned long	hash;
	int				index;

	hash = create_hash((unsigned char *)key);
	index = hash % table_size;
	if (hash_table[index].key)
	{
		if (hash_table[index].value == hash)
		{
			if (ft_strcmp(hash_table[index].key, key) == 0)
				return (&hash_table[index]);
		}
		else
			return (search_collision(hash_table, key, hash, table_size));
	}
	return (NULL);
}

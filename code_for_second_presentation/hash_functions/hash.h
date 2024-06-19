/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:10:21 by akuburas          #+#    #+#             */
/*   Updated: 2024/06/19 10:26:49 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H

# define HASH_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>

unsigned long	create_hash(unsigned char *str);
int				insert_hash(t_hash *hash_table, char *key, int table_size);
t_hash			*search_hash(t_hash *hash_table, char *key, int table_size);
int				resize_hash(int new_size, t_hash **hash_table, int table_size);
void			free_hash(t_hash *hash_table, int table_size);

typedef struct s_hash_table
{
	char			*key;
	unsigned long	value;
}	t_hash;

#endif
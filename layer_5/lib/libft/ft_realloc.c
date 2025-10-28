/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholterh <jholterh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:14:54 by jholterh          #+#    #+#             */
/*   Updated: 2025/09/15 12:31:02 by jholterh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *p, size_t new_size, size_t old_size)
{
	void	*ptr;
	size_t	copy_size;

	if (new_size == 0)
	{
		free(p);
		return (NULL);
	}
	if (p == NULL)
		return (malloc(new_size));
	ptr = malloc(new_size);
	if (!ptr)
		return (NULL);
	if (new_size < old_size)
		copy_size = new_size;
	else
		copy_size = old_size;
	ft_memcpy(ptr, p, copy_size);
	free(p);
	return (ptr);
}

void	**ft_realloc2(void **p, size_t old_count, size_t new_count)
{
	void	**ptr;
	size_t	copy_count;
	size_t	i;

	if (new_count == 0)
		return (NULL);
	ptr = malloc(new_count * sizeof(void *));
	if (!ptr)
		return (NULL);
	if (old_count < new_count)
		copy_count = old_count;
	else
		copy_count = new_count;
	ft_memcpy(ptr, p, copy_count * sizeof(void *));
	i = copy_count;
	while (i < new_count)
	{
		ptr[i] = NULL;
		i++;
	}
	return (ptr);
}

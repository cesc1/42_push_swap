/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:46:17 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/27 18:46:20 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static void	free_strs(char *str1, char *str2, unsigned int num_free)
{
	if (num_free == 1 || num_free >= 3)
		free(str1);
	if (num_free == 2 || num_free >= 3)
		free(str2);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	res_n;

	res_n = 0;
	while (src[res_n] != '\0')
		res_n++;
	if (size == 0)
		return (res_n);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res_n);
}

size_t	gnl_ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strjoin_free(char *str1, char *str2, unsigned int num_free)
{
	size_t	n1;
	size_t	n2;
	char	*result;

	if (!str1 && !str2)
	{
		free_strs(str1, str2, num_free);
		return (NULL);
	}
	n1 = gnl_ft_strlen(str1);
	n2 = gnl_ft_strlen(str2);
	result = (char *)malloc(n1 + n2 + 1);
	if (str1)
		ft_strlcpy(result, str1, n1 + 1);
	else
		result[0] = '\0';
	if (str2)
		ft_strlcpy(&result[n1], str2, n2 + 1);
	free_strs(str1, str2, num_free);
	return (result);
}

char	*gnl_ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n_s;
	size_t	n_res;
	char	*result;

	if (!s)
		return (NULL);
	n_s = gnl_ft_strlen(s);
	if (start >= n_s)
	{
		result = (char *)malloc(1);
		result[0] = '\0';
		return (result);
	}
	if (n_s - start < len)
		n_res = n_s - start;
	else
		n_res = len;
	result = (char *)malloc((n_res + 1) * sizeof (char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s[start], n_res + 1);
	return (result);
}

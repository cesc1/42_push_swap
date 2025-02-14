/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faguirre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:30:41 by faguirre          #+#    #+#             */
/*   Updated: 2024/09/29 10:32:38 by faguirre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Extra defines
# ifndef MAX_FILES_OPEN
#  define MAX_FILES_OPEN 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

// Includes
# include <sys/types.h>

// Static structure
typedef struct s_static
{
	ssize_t	pos0;
	ssize_t	pos1;
	ssize_t	bytes_loaded;
	char	*buffer;
	int		init_if;
}	t_static;

// Main function
char	*get_next_line(int fd);

// Helper funcctions
size_t	gnl_ft_strlen(const char *str);
char	*gnl_strjoin_free(char *str1, char *str2, unsigned int num_free);
char	*gnl_ft_substr(char const *s, unsigned int start, size_t len);

#endif

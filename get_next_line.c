/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:50:38 by lidbaha           #+#    #+#             */
/*   Updated: 2024/11/17 04:11:49 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer(char *buff, char *str)
{
	if (check_new_line(buff) == 1)
	{
		remove_line(buff);
		str = ft_strjoin(str, buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*result;
	int			r;

	result = NULL;
	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = buffer(buff, result);
	while (r > 0 && check_new_line(buff) == 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			return (free(result), NULL);
		if (r == 0)
		{
			if (result != NULL && result[0] != '\0')
				return (result);
			return (free(result), NULL);
		}
		buff[r] = '\0';
		result = ft_strjoin(result, buff);
	}
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	char	*result;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	result = get_next_line(fd);
	printf("%s\n", result);
	result = get_next_line(fd);
	printf("%s\n", result);
	close(fd);
	return (1);
}*/

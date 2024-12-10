/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lidbaha <lidbaha@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:57:07 by lidbaha           #+#    #+#             */
/*   Updated: 2024/11/17 04:06:34 by lidbaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		result[i] = s1[i];
	free(s1);
	while (s2[j] != '\n' && s2[j] != '\0')
		result[i++] = s2[j++];
	if (s2[j] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

int	check_new_line(char	*str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	remove_line(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i + j] != '\0')
	{
		line[j] = line[i + j];
		j++;
	}
	line[j] = '\0';
}

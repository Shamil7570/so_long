/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:17:48 by medeana           #+#    #+#             */
/*   Updated: 2021/12/19 15:10:20 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static void	*ft_split_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**ft_write_split(char **str, char const *s, char c)
{
	size_t		i;
	size_t		len;
	char		*start_chr;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		start_chr = (char *)s;
		while (*s && *s != c)
		{	
			len++;
			s++;
		}
		if (*(s - 1) != c)
		{	
			str[i++] = ft_substr(start_chr, 0, len);
			if (str[i - 1] == NULL)
				return (ft_split_free(str));
		}
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**res_str;

	if (!s)
		return (NULL);
	res_str = (char **)malloc((words((char *)s, c) + 1) * sizeof(char *));
	if (!res_str)
		return (NULL);
	return (ft_write_split(res_str, s, c));
}

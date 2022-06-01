/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:10:20 by medeana           #+#    #+#             */
/*   Updated: 2021/12/14 13:26:24 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char *str, unsigned int start, size_t lenght)
{
	char	*s;
	char	*buf;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	if (lenght > ft_strlen(str))
		lenght = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!s)
		return (NULL);
	buf = s;
	while (lenght-- > 0)
	{
		*s = str[start];
		s++;
		start++;
	}
	*s = '\0';
	return (buf);
}

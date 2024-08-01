/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:20:00 by felhafid          #+#    #+#             */
/*   Updated: 2024/03/19 10:46:08 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *s)
{
	int		sz;
	int		i;
	char	*remplir;

	remplir = malloc (BUFFER_SIZE + 1);
	if (!remplir)
		return (NULL);
	sz = 1;
	while (sz != 0)
	{
		sz = read(fd, remplir, BUFFER_SIZE);
		if (sz < 0 || (sz == 0 && (!s || !*s)))
			return (free(remplir), free (s), NULL);
		i = 0;
		remplir[sz] = '\0';
		while (remplir[i])
		{
			if (remplir[i++] == '\n')
				sz = 0;
		}
		s = ft_strjoin(s, remplir);
	}
	free (remplir);
	return (s);
}

char	*ft_lign(char *s)
{
	int		i;
	int		j;
	char	*lign;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	lign = malloc(i + 1);
	if (!lign)
		return (NULL);
	j = 0;
	while (j < i)
	{
		lign[j] = s[j];
		j++;
	}
	lign[j] = '\0';
	return (lign);
}

char	*get_next_line(int fd)
{
	static char	*s[OPEN_MAX];
	char		*lign;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = ft_read(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	lign = ft_lign(s[fd]);
	s[fd] = ft_afterline(s[fd]);
	return (lign);
}

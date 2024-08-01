/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:21:43 by felhafid          #+#    #+#             */
/*   Updated: 2024/03/17 21:08:55 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_afterline(char *s);
char	*ft_strjoin(char *s, char *s1);

#endif
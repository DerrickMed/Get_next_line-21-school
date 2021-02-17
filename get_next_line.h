/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:59:50 by srorscha          #+#    #+#             */
/*   Updated: 2020/11/27 17:24:41 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		readit(int fd, char *temp, char **line, char **old);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, size_t start, size_t len);
long	ft_strrchr(const char *str, int ch);
int		ft_strlen(char *str);
#endif

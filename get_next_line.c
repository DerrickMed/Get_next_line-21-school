/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srorscha <srorscha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:05:08 by srorscha          #+#    #+#             */
/*   Updated: 2020/11/27 17:23:51 by srorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	ft_strrchr(const char *str, int ch)
{
	unsigned char	cc;
	unsigned int	ret;

	ret = 0;
	cc = (unsigned char)ch;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == cc)
			return (ret);
		str++;
		ret++;
	}
	ret = -1;
	if (*str == 0 && ch == 0)
		ret = -1;
	return (ret);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s || start + len > (size_t)ft_strlen((char *)s))
		return (0);
	if ((result = malloc(sizeof(char) * (len + 1))))
	{
		while (len)
		{
			result[i++] = s[start++];
			len--;
		}
		result[i] = '\0';
	}
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	i;
	char	*res;

	i = 0;
	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	res = (char *)malloc(total_len + 1);
	if (!res)
		return (0);
	while (*s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = 0;
	return (res);
}

int		readit(int fd, char *temp, char **line, char **old)
{
	int		n_num;
	int		r_num;
	char	buffer[BUFFER_SIZE + 1];

	r_num = 1;
	while (r_num)
	{
		if ((n_num = ft_strrchr(temp, '\n')) != -1)
		{
			if (!(*line = ft_substr(temp, 0, n_num)))
				return (-1);
			old[fd] = ft_substr(temp, n_num + 1, ft_strlen(temp) - n_num - 1);
			free(temp);
			return (1);
		}
		r_num = read(fd, buffer, BUFFER_SIZE);
		buffer[r_num] = '\0';
		old[fd] = ft_strjoin(temp, buffer);
		if (!buffer[0])
			(*line) = old[fd];
		free(temp);
		temp = old[fd];
	}
	old[fd] = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*temp;
	static char *old[1024];

	if (fd < 0 || !(line) || BUFFER_SIZE <= 0 || BUFFER_SIZE > 100000
		|| (read(fd, 0, 0) == -1))
		return (-1);
	temp = old[fd];
	if (!temp)
	{
		if (!(temp = malloc(sizeof(char))))
			return (-1);
		*temp = 0;
	}
	return (readit(fd, temp, line, old));
}

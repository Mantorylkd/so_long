/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhallaf <ekhallaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:42:20 by ekhallaf          #+#    #+#             */
/*   Updated: 2025/04/14 19:22:42 by ekhallaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_word(char const *s, char c)
{
	int		len;
	int		in_word;
	size_t	i;

	len = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			len++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (len);
}

static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	*ft_free(char **split)
{
	int i;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

static char	*allocate_word(char const **s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = len_word(*s, c);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (**s && **s != c)
	{
		word[i++] = *(*s)++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			split[i] = allocate_word(&s, c);
			if (!split[i])
				return (ft_free(split));
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}



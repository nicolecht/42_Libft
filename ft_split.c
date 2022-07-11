/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchee <nchee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:41:53 by nchee             #+#    #+#             */
/*   Updated: 2022/07/11 14:18:28 by nchee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (0);
	dest = malloc(sizeof(char *) * count_words(s, c) + 1);
	if (!dest)
		return (0);
	start = 0;
	i = 0;
	while (i < count_words(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		dest[i] = ft_substr(s, start, (end - start));
		start = end;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

// **dest || dest[0][0] (2d array)
// |---------------------------------------|
// | *dest + 0 = one   ||  dest[0] = one   |
// | *dest + 1 = two   ||  dest[1] = two   |
// | *dest + 2 = three ||  dest[2] = three |
// | *dest + 3 = four  ||  dest[3] = four  |
// |---------------------------------------| 
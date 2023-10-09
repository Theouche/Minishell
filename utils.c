/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 15:42:21 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/21 13:42:00 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == 34 || cmd[i] == 39)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strndup_ms(char *src, int n)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i] && i < n)
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	ft_count_word_ms(char *str, char c)
{
	int		i;
	size_t	count;
	int		block;

	count = 0;
	block = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && block == 0)
		{
			block = 1;
			count++;
		}
		else if (str[i] == c)
			block = 0;
		i++;
	}
	return (count);
}

void	ft_free_split(char **tab)
{
	int	i;

	if (!tab)
		printf("------- NOT TQB\n");

	//printf("\n\n\n\n\nqvqnt whilllllllllllllllllllll\n");
	i = 0;
	//printf("\n\n\ndebut check\n");
	//check_tab(tab);
	//printf("\n\n\ndebut free\n");
	while (tab[i])
	{
	//	printf("free i=%d\n", i);
		//printf("free i=%d : %s\n", i, tab[i]);
		free(tab[i]);
		//printf("ok\n");
		i++;
	}
	//printf("apres whilllllllllllllllllllll\n\n\n\n\n");
	free(tab);
}

char	*first_word(char *cmd)
{
	int		i;
	char	*fw;

	i = 0;
	fw = malloc(sizeof(char) * 7);
	while (ft_isalpha(cmd[i]))
	{
		fw[i] = cmd[i];
		i++;
	}
	fw[i] = 0;
	return (fw);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (s1[i] - s2[i]);
	}
	return (s1[i] - s2[i]);
}

char	*ft_remove_first_space(char *cmd)
{
	char	*dup;
	int	i;
	int	deb;

	i = 0;
	deb = 0;
	while (cmd[i] == ' ' || cmd[i] == '\t')
		i++;
	dup = malloc(ft_strlen(cmd) - i + 1 * sizeof(char));
	while (cmd[i])
		dup[deb++] = cmd[i++];
	dup[deb] = 0;
	//free(cmd);
	return (dup);
}

int		check_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 9)
			return (0);
		i++;
	}
	return (1);
}

int		red_not_ok(char *cmd, char c)
{
	char	**split;
	int		len;
	int		i;

	split = ft_split(cmd, ' ');
	len = 0;
	while (split[len])
		len++;
	//if (len == 1)
	//	return (1);
	i = 0;
	while (split[i][0] != c)
		i++;
	if (i == len - 1 || len == 1)
	{
		ft_free_split(split);
		printf("bash: syntax error near"); 
		printf(" unexpected token `newline'\n");
		return (1);
	}
	ft_free_split(split);
	return (0);
}

int	all_com_ok(char **cmd)	
{
	int		i;
	char	c;

	i = 0;
	while (cmd[i])
	{
		if (check_only_space(cmd[i]) == 1)
		{
			printf("bash: syntax error near"); 
			printf(" unexpected token `|'\n");
			return (0);
		}
		if (ft_strchr_dbred(cmd[i], '<') == 1)
		{
			c = '<';
			if (red_not_ok(cmd[i], c) == 1)
				return (0);
		}
		if (ft_strchr_dbred(cmd[i], '>') == 1)
		{
			c = '>';
			if (red_not_ok(cmd[i], c) == 1)
				return (0);
		}
		i++;
	}
	return (1);
}
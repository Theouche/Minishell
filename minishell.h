/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:15:22 by tlorne            #+#    #+#             */
/*   Updated: 2023/09/12 14:46:20 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>

# define NAME "\033[1;36m🐚  Minishell "
# define VIOLET "\033[1;35m"
# define BLACK "\033[1;30m"
# define WHITE "\033[1;37m"

/*typedef struct s_list
{
	char			*cmd;
	int				pipe;
	int				redir;
//	char			*file_out;
//	char			*file_in;
//	char			*type_in;
//	char			*type_out;
	struct s_list *next;
}	t_list;*/

typedef	struct s_data
{
	char		*pwd;
	char		*path;
	char		**cpyenv;
	char		*home;
	char		**fsplit;
	char		**cmd;
	int	num_pip;
}	t_data;

void    ft_init(t_data *data, char **env);
void    ft_parse(char *prompt, t_list **lst_cmd);
//char	**ft_parse(char *prompt);
void	ft_echo(char *word_to_print);
//void    print_cmd(char **list_cmd);
void    print_cmd(t_list *lst_cmd);
void    execute_cmd(t_data *data, char **env);
int     apply_echo(t_data *data);
int		is_quote(char *cmd);
char    *remove_quote(char *cmd);
int     apply_pwd(t_data *data, char **env);
char	*ft_strndup_ms(char *src, int n);
size_t	ft_count_word_ms(char *src, char c);
void	ft_check_and_parse(t_data *data, char *prompt);
void	ft_free_split(char **tab);
void	begin_cmd(t_data *data, char **env);
char    *first_word(char *cmd);
int     ft_strcmp(char *s1, char *s2);
void    check_tab(char **tab);
int     apply_env(t_data *data, char **env);
int     apply_cd(t_data *data, char **env);
int		apply_export(t_data *data);
int 	apply_unset(t_data *data);
void	do_export_no_name(t_data *data, char *exp);
void    no_builtin(t_data *data, char **env);

#endif

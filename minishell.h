/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:15:22 by tlorne            #+#    #+#             */
/*   Updated: 2023/10/04 15:05:33 by leudelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
#include <sys/wait.h>
# include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>

# define NAME "\033[1;36m🐚  Minishell "
# define VIOLET "\033[1;35m"
# define BLACK "\033[1;30m"
# define WHITE "\033[1;37m"

/*struct sigaction {
    void     (*sa_handler) (int);
    void     (*sa_sigaction) (int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer) (void);
};*/

typedef	struct s_data
{
	char		*pwd;
	char		*path;
	char		**cpyenv;
	char		*home;
	char		**fsplit;
	char		**cmd;
	char		*prompt;
	int	num_pip;
	int	redir;
	int	status;
}	t_data;

void    ft_init(t_data *data, char **env);
//void    ft_parse(char *prompt, t_list **lst_cmd);
//char	**ft_parse(char *prompt);
void	ft_echo(char *word_to_print);
//void    print_cmd(char **list_cmd);
void    print_cmd(t_list *lst_cmd);
//void    execute_cmd(t_data *data, char **env);
int     apply_echo(char *cmd, t_data *data);
int		is_quote(char *cmd);
char    *remove_quote(char *cmd);
int     apply_pwd(t_data *data);
char	*ft_strndup_ms(char *src, int n);
size_t	ft_count_word_ms(char *src, char c);
int		ft_check_and_parse(t_data *data, char *prompt);
void	ft_free_split(char **tab);
void	begin_cmd(t_data *data, char *cmd);
char    *first_word(char *cmd);
int     ft_strcmp(char *s1, char *s2);
void    check_tab(char **tab);
int     apply_env(t_data *data);
int     apply_cd(t_data *data, char **env);
int		apply_export(t_data *data, char **cmd);
int 	apply_unset(t_data *data, char **cmd);
void	do_export_no_name(t_data *data, char *exp);
void    no_builtin(t_data *data, char **env);
char    *ft_remove_first_space(char *cmd);
int     ft_strchr_red(char *cmd, char chev);
int     ft_strchr_dbred(char *cmd, char chev);
void    ft_redir_double_droite(t_data *data, char *cmd);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	*add_space(char *cmd);
void	ft_redir_droite(t_data *data, char *cmd);
void	ft_init_bis(t_data *data, t_data *bis, char *new_cmd);
void	ft_redir_gauche(t_data *data, char *cmd);
void	ft_redir_double_gauche(t_data *data, char *cmd);
char	*ft_strjoin_and_free1(char *s1, char *s2);
char	*handle_dollar(t_data *data, char *prompt);
char	*ft_strjoin_and_free2(char *s1, char *s2);
int 	len_tab(char **tab);
char    *char_vide(void);
void	set_signal(void);
void	checkcmd(char **cmd, t_data *data);
int		forpipe(char **cmd, t_data *data);
int		new_std_outin(int output_fd, int input_fd, char *cmd, t_data *data);
char	*recupthepath(t_data *data, char *cmd);
int		check_only_space(char *str);
int		exitstatus(int status);
int		all_com_ok(char **cmd);

#endif

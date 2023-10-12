/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   signal.c	   :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: tlorne <marvin@42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/09/29 14:38:23 by tlorne	#+#	#+#	 */
/*   Updated: 2023/09/29 14:38:43 by tlorne	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 0);
		ft_printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signal == SIGQUIT)
	{
		ft_printf("\033[2D  ");
		ft_printf("\033[2D");

	}
}

void	set_signal(void)
{
	struct sigaction	act;

	bzero(&act, sizeof(act));
	act.sa_handler = &sigint_handler;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:46:38 by jeunjeon          #+#    #+#             */
/*   Updated: 2022/01/03 17:29:40 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	execute_command(t_mini *mini)
{
	return ;
}

char	*is_valid_cmd(t_mini *mini, char *cmd)
{
	int		i;
	int		fd;
	char	*absolute_path_cmd;
	char	*tmp_cmd;

	absolute_path_cmd = ft_strjoin("/", cmd);
	fd = 0;
	i = 0;
	while (mini->envp[i])
	{
		tmp_cmd = ft_strjoin(mini->envp[i], absolute_path_cmd);
		fd = access(tmp_cmd, X_OK);
		if (fd != -1)
		{
			free(absolute_path_cmd);
			return (tmp_cmd);
		}
		close(fd);
		free(tmp_cmd);
		i++;
	}
	free(absolute_path_cmd);
	return (NULL);
}

int	ft_builtin(t_mini *mini)
{
	return (0);
}

int	ft_command(t_mini *mini, char *input, char **strs)
{
	if (input[0] == '\0')
		return (ENTER);
	mini->cmd = is_valid_cmd(mini, strs[0]);
	if (mini->cmd == NULL)
		printf("-bash: %s: command not found\n", strs[0]);
	ft_builtin(mini);
	free(mini->cmd);
	/*
	여기 까지 했는데 지금 까지 한게 머냐면
	
	*/
	return (0);
}

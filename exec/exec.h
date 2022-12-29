/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:29:12 by hiroaki           #+#    #+#             */
/*   Updated: 2022/12/29 22:32:46 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>

typedef enum e_redir_kind {
	IN_REDIR,
	OUT_REDIR,
	HEREDOC,
}	t_redir_kind;

typedef struct s_redirect {
	char				*exec_cmd[2];
	char				*cmd_arg;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_command {
	char				**cmd;
	bool				is_builtin;
	struct s_command	*next;
}	t_command;

typedef struct s_parse_ast {
	pid_t				pid;
	int					pfd[2];
	t_command			*cmd;
	t_redirect			*redir;
	struct s_parse_ast	*next_pipe;
	struct s_parse_ast	*prev_pipe;
}	t_parse_ast;

typedef struct s_exec_data
{
	int	pipe_cnt;
}	t_exec_data;

#endif

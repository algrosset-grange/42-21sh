/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrosset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:40:04 by agrosset          #+#    #+#             */
/*   Updated: 2017/05/21 15:04:50 by agrosset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include "libft.h"

# define NO_ERROR -1
# define NO_COMMAND -2
# define ERROR -3

char					**g_envv;

/*
** src/cd_builtin.c
*/
int						cd_builtin(char **command);

/*
** src/change_dir.c
*/
int						change_dir(char *path, int print_path);

/*
** src/check_bins.c
*/
int						check_bins(char **command);

/*
** src/display_prompt_msg.c
*/
void					exit_shell(void);
char					*parse_home_path(char *path, int reverse_parse);
int						display_prompt_msg(void);

/*
** src/echo_builtin.c
*/
int						echo_builtin(char **command);

/*
** src/exec_command.c
*/
int						exec_command(char **command);

/*
** src/parse_input.c
*/
char					*parse_input(char *input);

/*
** src/run_cmd.c
*/
int						run_cmd(char *path, char **args);

/*
**src/set_env_var.c
*/
int						find_env_var(char *var);
int						set_env_var(char *key, char *value);

/*
** src/setenv_builtin.c
*/
int						get_env_var(char *var, char **rep);
int						setenv_builtin(char **args);
char					**realloc_envv(int new_size);

/*
** src/signal_handler.c
*/
void					signal_handler(int signo);
void					proc_signal_handler(int signo);

/*
** src/unsetenv_builtin.c
*/
void					print_env(void);
int						init_envv(int ac, char **av, char **envv);
int						unsetenv_builtin(char **command);
#endif

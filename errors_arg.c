/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 03:49:00 by hmochida          #+#    #+#             */
/*   Updated: 2022/05/02 08:18:17 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** checks for fucked up arguments.
** must be used BEFORE initializing MLX to avoid leaks.
*/

#include "fdf.h"

static int		check_filename(char *argv);
static void		check_fd(char *argv);

/*
** Checks for invalid user arguments when launching ./fdf;
** No arguments, too many arguments, wrong file extension, wrong file;
*/
void	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("\033[31;1mInvalid syntax.\033[0m\n", 2);
		exit (0);
	}
	if (argc > 2)
	{
		errno = E2BIG;
		perror("\033[31;1mSomething went bad\033[0m");
		exit (0);
	}
	if (!(check_filename(argv[1])))
	{
		errno = EINVAL;
		perror("\033[31;1mSomething went kinda bad\033[0m");
		exit (0);
	}
	check_fd(argv[1]);
}

static int	check_filename(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = ft_strlen(argv) - 1;
	if (argv[i] != 'f' || argv[i - 1] != 'd' || argv[i - 2] != 'f'
		|| argv[i - 3] != '.')
		return (0);
	while (i <= 0)
		if ((argv[i] < 33) || (argv[i--] > 126))
			return (0);
	return (1);
}

static void	check_fd(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("\033[31;1mSomething went kinda bad\033[0m");
		exit(0);
	}
	close(fd);
	return ;
}

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	ft_cmdlen(char **cmd)
{
	int	len;

	len = 0;
	while (cmd[len] && *cmd[len] != '|' && *cmd[len] != ';')
		len++;
	return (len);
}

void	ft_program(char **cmd, int cmdlen, char **env)
{
	pid_t	cpid;

	cpid = fork ();
	if (cpid == 0)
	{
		cmd[cmdlen] = NULL;
		execve (cmd[0], cmd, env);
	}
	else
	{
		while (wait (NULL) != -1)
			;
	}
}

int	main(int ac, char **av, char **env)
{
	int	cmdlen;

	(void)ac;
	cmdlen = 0;
	while (av[cmdlen] && av[cmdlen + 1])
	{
		av += cmdlen + 1;
		cmdlen = ft_cmdlen (av);
		if (!strcmp (av[0], "cd"))
			dprintf (1, "ft_cd\n");
		else if (av[cmdlen] && *av[cmdlen] == '|')
			dprintf (1, "ft_pipe\n");
		else if (av[cmdlen] == NULL || *av[cmdlen] == ';')
		{
			dprintf (1, "ft_program\n");
			ft_program (av, cmdlen, env);
		}
	}
	return (0);
}

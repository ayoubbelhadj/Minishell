# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <signal.h>

void	sigint_handler(int signum)
{
	
}

int	main()
{
	char	*cmd;
	while(1)
	{
		signal(SIGINT, sigint_handler);
		cmd = readline("my_shell> ");
		if (cmd)
		{
			add_history(cmd);
			printf("You entered: %s\n", cmd);
			free(cmd);
		}
		if (strcmp(cmd, "exit") == 0)
		{
			break;
		}
	}
	return 0;
}

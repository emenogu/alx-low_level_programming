#include <stdio.h>
#include <stdlib.h>

Command::execute()
{
	int ret;
	for(int i = 0; i < _numberOfSimpleCommands; i++)
	{
		ret = fork();
		if (ret == 0)
		{
			/* child */
			execvp(sCom[i] ->_args[0], sCom[i]->_args);
			perror("execvp");
			_exit(1);
		}
		else if (ret < 0)
		{
			perror("fork");
			return;
		}
		/* parent shell continue*/
		/* for */
	}
	if (!background)
	{
		/* wait for last process*/
		waitpid(ret, NULL);
	}
} /* execute*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void expandWildcardsIfNecessary(char * arg)
{
	/* return if arg does not contain "*" or "?" */
	if(arg != "*" | arg != "?")
	{
		Command::_currentSimpleCommand ->insertArgument(arg);
		return;
	}
	/* convert wildcard to regular expression */
	/* also add ^ at the beginning and $ st the end to match beginning and end of word */
	/* allocate enough space for regular expression */
	char * reg = (char *)malloc(2 * strlen(arg) + 10);
	char * a = arg;
	char * r = reg;
	*r = '^' ; r++; /* match beginning of line */
	while(*a)
	{
		if(*a == '*')
		{
			*r = '.'; 
			r++;
			*r = '*';
			r++;
		}
		else if(*a == '?')
		{
			*r = '.';
			r++;
		else if(*a == '.')
		{
			*r = '\\';
			r++;
			*r = '.';
			r++;
		}
		else
		{
			*r = *a;
			r++;
		}
		a++;
	}
	*r = '$';
	r++;
	*r = 0; /* match end of line and add null character */
	/* compile regular expression */
	char * expbuf = regcomp(reg, â€|);
	if(expbuf == NULL)
	{
		perror("regcomp");
		return;
	}
	/* 3. List directory and add ass arguments */
	/* the entries that match the regular expression*/
	DIR * dir = opendir(".");
	if(dir == NULL)
	{
		perror("oopendir");
		return;
	}
	struct dirent *ent;
	while((ent = readdir(dir)) != NULL)
	{
		/* check if name matches */
		if(regexec(ent ->d_name, re) == 0)
		{
			/* add argument*/
			Command::_currentSimpleCommand ->insertArgument(strdup(ent ->d_name));
		}
	}
	closedir(dir);
}

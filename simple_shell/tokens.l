cmd [arg]* [|cmd [arg]*]*
	[[>filename][<filename][>&filename][>>filename]]"[&]
/*
* tokens.l: simple lexical analyzer for the shell
*/

%{
#include <string.h>
#include "y.tab.h"

%}

%%

\n	{
		return NEWLINE;
	}
[ \t]	{
		/* discard spaces and tabs */
	}
">"	{
		return GREAT;
	}
"<"	{
		return LESS;
	}
">>"	{
		return GREATGREAT;
	}
">&"	{
		return GREATAMPERSAND;
	}
"|"	{
		return PIPE;
	}
"&"	{
		return AMPERSAND;
	}
[^ \t\n][^ \t\n]	{
		/* Assume filenames have only alpha chars*/
		yyval.string_val = strdup(yytext);
		return WORD;
	}
"-"	{
		return HYPHEN;
	}
.	{
		/* invalid character in input */

		return NOTOKEN;
	}

%%

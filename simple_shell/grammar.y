cmd [arg]* [|cmd [arg]*]*
        [[>filename][<filename][>&filename][>>filename]]"[&]
%token GREAT LESS GREATGREAT GREATAMPERSAND PIPE AMPERSAND HYPHEN NOTOKEN

goal: command_list;
arg_list:
	arg_list WORD
	|/*empty*/
		;
cmd_and_args:
	    WORD arg_list
		;
pipe_list:
	 pipe_list PIPE cmd_and_args
	| cmd_and_args
		;
iomodifier:
	  GREATGREAT Word
	| GREAT Word
	| GREATGREATAMPERSAND Word
	| GREATAMPERSAND Word
	| LESS Word
	;
iomodifier_list:
	       io_modifier_list io_modifier
		|/*empty*/
	;
background_optional:
		   AMPERSAND
		|/*empty*/
	;
command_line:
	    pipe_list io_modifier_list background_opt NEWLINE
		|NEWLINE /* accept empty cmd line*/
		| error NEWLINE{yyerrok;}
			/* error recovery*/
command_list:
	    command_list command_line
		; /* command loop*/

/** Command data structure
 * describes command and arguments
 */
struct simpleCommand {
	/* existing space for arguments currently preallocated*/
	int _numberOfAvailableArguments;

	/* Number of arguments*/
	int _numberOfArguments;
	/* Array of arguments*/
	char ** _arguments;

	simpleCommand();
	void insertArgument(char *argument);
};
/* describes a complete command with multiple pipes or input output redirections if any*/
struct Command {
	int _numberOfAvailableSimpleCommands;
	int _numberOfSimpleCommands;
	simpleCommand ** _simpleCommands;
	char * _outFile;
	char * _inputFile;
	char * _errFile;
	int _background;

	void prompt();
	void print();
	void execute();
	void clear();

	Command();
	void insertSimpleCommand(simpleCommand * SimpleCommand);

	static Command _currentCommand;
	static simpleCommand *_currentSimpleCommand;
};

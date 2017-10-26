#include "cli_state.h"
#include "cli_command_print_commands.h"

namespace circuit_sim
{

CliState::CliState(MvcController *view)
{
	this->actions_.Add(new CliCommandPrintCommands("prints all avaiable commands", view), "help");
}

} // Namespace
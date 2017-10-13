#ifndef __CIRCUIT_SIM_CLI_COMMAND_PRINT_COMMANDS_H__
#define __CIRCUIT_SIM_CLI_COMMAND_PRINT_COMMANDS_H__

#include "cli_command_interface.h"
#include "cli_state.h"

using circuit_sim::CliCommandInterface;
using circuit_sim::CliState;

namespace circuit_sim
{

	class CliCommandPrintCommands : CliCommandInterface
	{
	public:
		CliCommandPrintCommands(const string &helpdesc, CliState *state) : CliCommandInterface(helpdesc), state_(state) {}

		virtual string execute(const MvcController *controller, const vector<string> &args);

	private:
		CliState *state_;

	};

} // Namespace
#endif // Headerguard
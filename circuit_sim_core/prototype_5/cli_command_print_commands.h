#ifndef __CIRCUIT_SIM_CLI_COMMAND_PRINT_COMMANDS_H__
#define __CIRCUIT_SIM_CLI_COMMAND_PRINT_COMMANDS_H__

// #include "cli_command_interface.h"
#include "mvc_cli_view.h"

using circuit_sim::CliCommandInterface;

namespace circuit_sim
{

	class CliCommandPrintCommands : public CliCommandInterface
	{
	public:
		CliCommandPrintCommands(const string &helpdesc, class MvcCliView *view) : CliCommandInterface(helpdesc), view_(view) {}

		virtual string execute(const vector<string> &args);

	private:
		class MvcCliView *view_;
	};

} // Namespace
#endif // Headerguard
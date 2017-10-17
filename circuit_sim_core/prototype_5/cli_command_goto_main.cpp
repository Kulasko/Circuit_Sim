#include "cli_command_goto_main.h"

namespace circuit_sim
{

string CliCommandGotoMain::execute(MvcController * const controller, const vector<string> &args)
{
	return "main";
}

} // Namespace
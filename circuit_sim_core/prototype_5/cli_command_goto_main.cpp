#include "cli_command_goto_main.h"

namespace circuit_sim
{

string CliCommandGotoMain::execute(const MvcController *controller, const vector<string> &args)
{
	return "main";
}

} // Namespace
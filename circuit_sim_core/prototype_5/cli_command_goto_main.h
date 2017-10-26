#ifndef __CIRCUIT_SIM_CLI_COMMAND_GOTO_MAIN_H__
#define __CIRCUIT_SIM_CLI_COMMAND_GOTO_MAIN_H__

#include "cli_command_interface.h"

using circuit_sim::CliCommandInterface;

namespace circuit_sim
{

class CliCommandGotoMain : public CliCommandInterface
{
public:
	CliCommandGotoMain(const string &helpdesc) : CliCommandInterface(helpdesc) {}

	virtual string execute(const vector<string> &args);
};

} // Namespace
#endif // Headerguard
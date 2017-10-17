#ifndef __CIRCUIT_SIM_CLI_COMMAND_INTERFACE_H__
#define __CIRCUIT_SIM_CLI_COMMAND_INTERFACE_H__

#include <string>
#include <vector>

#include "mvc_controller.h"

using std::string;
using std::vector;

using circuit_sim::MvcController;

namespace circuit_sim
{

class CliCommandInterface
{
public:
	const string helpdesc;

	CliCommandInterface(const string &helpdesc) : helpdesc(helpdesc) {}

	virtual string execute(MvcController * const controller, const vector<string> &args) = 0;
};

} // Namespace
#endif // Headerguard
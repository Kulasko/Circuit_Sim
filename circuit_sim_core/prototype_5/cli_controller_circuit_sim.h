#ifndef __CIRCUIT_SIM_CLI_CONTROLLER_CIRCUIT_SIM_H__
#define __CIRCUIT_SIM_CLI_CONTROLLER_CIRCUIT_SIM_H__

#include <unordered_set>

#include <cli_controller_base.h>

using std::unordered_set;
using arschitek_utils::CliControllerBase;

namespace circuit_sim
{

class CliControllerCircuitSim : public CliControllerBase
{
public:
	CliControllerCircuitSim() : CliControllerBase()
	{
		//this->AddMenue("test", unordered_set<string>{"main"}, CliAction(string("Das hier ist ein tesmenü."), &CliControllerCircuitSim::GotoTest));
		//this->AddAction("main", CliAction(string("Hauptmenü"), &CliControllerCircuitSim::GotoMain));
	}

protected:
	static string GotoTest(vector<string> &args)
	{
		return "test";
	}

	static string GotoMain(vector<string> &args)
	{
		return "main";
	}
};

}
#endif // __CIRCUIT_SIM_CLI_CONTROLLER_CIRCUIT_SIM_H__
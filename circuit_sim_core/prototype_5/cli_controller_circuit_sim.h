#ifndef __CIRCUIT_SIM_CLI_CONTROLLER_CIRCUIT_SIM_H__
#define __CIRCUIT_SIM_CLI_CONTROLLER_CIRCUIT_SIM_H__

#include <unordered_set>

#include "utils\cli_controller_base.h"

using std::unordered_set;
using arschitek_utils::CliControllerBase;

namespace circuit_sim
{

class CliControllerCircuitSim : public CliControllerBase
{
public:
	CliControllerCircuitSim() : CliControllerBase()
	{
		this->Build();
	}
protected:
	void Build()
	{
	}
};

}
#endif // __CIRCUIT_SIM_CLI_CONTROLLER_CIRCUIT_SIM_H__
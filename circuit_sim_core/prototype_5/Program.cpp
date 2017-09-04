#include "cli_controller_circuit_sim.h"

using circuit_sim::CliControllerCircuitSim;

int main()
{
	CliControllerCircuitSim view;

	view.Run("main");

	return 0;
}
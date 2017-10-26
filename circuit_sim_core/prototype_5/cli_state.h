#ifndef __CIRCUIT_SIM_CLI_STATE_H__
#define __CIRCUIT_SIM_CLI_STATE_H__

#include "cli_command_interface.h"
#include "mvc_cli_view.h" // WARNING: Circular dependency here

#include <indexed_vector.h>

using arschitek_utils::IndexedVector;

using circuit_sim::CliCommandInterface;

namespace circuit_sim
{
class MvcCliView;

class CliState
{
public:
	CliState(MvcCliView *view);
	~CliState() {};

	//IndexedVector<string, unique_ptr<CliCommandInterface>> actions2_;
	IndexedVector<string, CliCommandInterface*> actions_;

};

} // Namespace
#endif // Headerguard
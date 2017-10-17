#ifndef __CIRCUIT_SIM_CLI_STATE_H__
#define __CIRCUIT_SIM_CLI_STATE_H__

#include "cli_command_interface.h"

#include <indexed_vector.h>
#include <memory>

using arschitek_utils::IndexedVector;
using std::unique_ptr;

using circuit_sim::CliCommandInterface;

namespace circuit_sim
{

class CliState
{
public:
	IndexedVector<string, CliCommandInterface*> actions_;

};

} // Namespace
#endif // Headerguard
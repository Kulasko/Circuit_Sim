#ifndef __CIRCUIT_SIM_MVC_CLI_VIEW_H__
#define __CIRCUIT_SIM_MVC_CLI_VIEW_H__

#include "cli_state.h"
#include "mvc_controller.h"

// using circuit_sim::CliState;
using circuit_sim::MvcController;

namespace circuit_sim
{
class CliState;

class MvcCliView
{
public:
	MvcCliView();

	CliState &GetCurrState();
	void SetController(MvcController * const controller);

	void Show(const char *begin);

private:
	bool running_;

	MvcController *controller_;
	IndexedVector<string, CliState> states_;

	string curr_status_;
};

} // Namespace
#endif // Headerguard
#ifndef __CIRCUIT_SIM_MVC_CLI_VIEW_H__
#define __CIRCUIT_SIM_MVC_CLI_VIEW_H__

#include "cli_state.h"
#include "mvc_controller.h"

#include <memory>
#include <unordered_set>

using circuit_sim::CliState;
using circuit_sim::MvcController;

using std::unordered_set;
using std::weak_ptr;

namespace circuit_sim
{

class MvcCliView
{
public:
	void SetController(const weak_ptr<MvcController> &controller);

private:
	weak_ptr<MvcController> controller_;
	unordered_set<CliState> states_;

};

} // Namespace
#endif // Headerguard
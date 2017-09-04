#ifndef __CIRCUIT_SIM_UTILS_CLI_CONTROLLER_BASE_H__
#define __CIRCUIT_SIM_UTILS_CLI_CONTROLLER_BASE_H__

#include <string>
#include <vector>

#include "indexed_vector.h"

using std::string;
using std::vector;
using arschitek_utils::IndexedVector;

namespace arschitek_utils
{

class CliControllerBase
{
public:
	CliControllerBase();

	string print_help(vector<string> &args);

protected:
	typedef string(CliControllerBase::*Action) (vector<string> &args);
	struct CliAction {
		string helpdesc;
		Action action;

		CliAction(string &helpdesc, string(CliControllerBase::*action) (vector<string> &args));
	};

	virtual void Build() = 0;


	string curr_status;
	vector<string> curr_data;

	IndexedVector<string, CliAction> actions_;
	IndexedVector<string, vector<string>> allowedActions;
};

} // Namespace
#endif // Headerguard
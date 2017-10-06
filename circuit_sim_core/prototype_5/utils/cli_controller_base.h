#ifndef __CIRCUIT_SIM_UTILS_CLI_CONTROLLER_BASE_H__
#define __CIRCUIT_SIM_UTILS_CLI_CONTROLLER_BASE_H__

#include <unordered_set>
#include <string>
#include <thread>
#include <vector>

#include "indexed_vector.h"

using std::unordered_set;
using std::string;
using std::thread;
using std::vector;
using arschitek_utils::IndexedVector;

namespace arschitek_utils
{

class CliControllerBase
{
public:
	CliControllerBase();

	virtual void Run(string start);

	static string PrintHelp(vector<string> &args);

protected:
	typedef string(*Action) (vector<string> &args);
	struct CliAction {
		string helpdesc;
		Action action;

		CliAction(string &helpdesc, string(*action) (vector<string> &args));
	};

	void AddAction(string name, CliAction action);
	void AddMenue(string name, unordered_set<string> allowedActions, CliAction gotoaction);

	bool running_;

	string curr_status_;

	IndexedVector<string, CliAction> actions_;
	IndexedVector<string, unordered_set<string>> allowedActions_;
};

} // Namespace
#endif // Headerguard
#ifndef __ARSCHITEK_UTILS_CLI_CONTROLLER_BASE_H__
#define __ARSCHITEK_UTILS_CLI_CONTROLLER_BASE_H__

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

	void Run(const char* start);
	void Run(const string &start);

	string PrintHelp(const vector<string> &args);

protected:
	typedef string(CliControllerBase::*Action) (const vector<string> &args);
	struct CliAction {
		const string helpdesc;
		const Action action;

		CliAction(const string &helpdesc, const Action action);
		CliAction(const char* helpdesc, const Action action);

		CliAction operator=(CliAction other);
	};

	void AddAction(const string &name, const CliAction &action);
	void AddMenue (const string &name, const unordered_set<string> &allowedActions, const CliAction &gotoaction);

	bool running_;

	string curr_status_;

	IndexedVector<string, CliAction> actions_;
	IndexedVector<string, unordered_set<string>> allowedActions_;
};

} // Namespace
#endif // Headerguard
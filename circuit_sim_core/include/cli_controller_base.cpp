#include <chrono>
#include <iostream>

#include "cli_controller_base.h"
#include "string_utils.h"

using std::char_traits;
using std::chrono::milliseconds;
using std::cin;
using std::cout;
using std::endl;
using std::this_thread::sleep_for;
using arschitek_utils::split;

namespace arschitek_utils
{

	CliControllerBase::CliControllerBase()
	{
		actions_.Add(CliAction("shows a list of available commands together with a short description", &CliControllerBase::PrintHelp), "help");
		allowedActions_.Add(unordered_set<string>(), "main");
		allowedActions_["main"].insert("help");
	}

	CliControllerBase::CliAction::CliAction(const string &helpdesc, const Action action) : helpdesc(helpdesc), action(action) {}
	CliControllerBase::CliAction::CliAction(const char* helpdesc, const Action action) : helpdesc(string(helpdesc)), action(action) {}
	CliControllerBase::CliAction CliControllerBase::CliAction::operator=(CliControllerBase::CliAction other)
	{
		return CliAction(other.helpdesc, other.action);
	}

	void CliControllerBase::Run(const char* start)
	{
		this->Run(string(start));
	}

	void CliControllerBase::Run(const string &start)
	{
		string input;
		string returnstring;
		vector<string> input_args;

		curr_status_ = start;
		running_ = true;
		while (running_ && input != "exit")
		{
			cout << curr_status_ << "> ";
			getline(cin, input);
			input_args = split(input, " ");
			if (allowedActions_[curr_status_].count(input_args[0]) > 0)
			{
				returnstring = (this->*actions_[input_args[0]].action)(input_args);
				if (returnstring != "")
				{
					curr_status_ = returnstring;
				}
			}
			else if (input_args[0] != "" && input_args[0] != "exit")
			{
				cout <<  endl << "Error: found no command \"" << input_args[0] << "\" in this context." << endl
					 << "Type \"help\" for a list of available commands." << endl << endl;
			}
		}
		running_ = false;
	}

string CliControllerBase::PrintHelp(const vector<string> &args)
{
	cout << endl << "Avaiable commands" << endl << "=================" << endl;
	for (size_t i = 0; i < this->actions_.size(); i++)
	{
		cout << this->actions_.Index(i) << " - " << this->actions_[i].helpdesc << endl;
	}
	cout << "exit - exits the program" << endl << endl;
	return "";
}

void CliControllerBase::AddAction(const string &name, const CliAction &action)
{
	this->actions_[name] = action;
}

void CliControllerBase::AddMenue(const string &name, const unordered_set<string> &allowedActions, const CliAction &action)
{
	this->AddAction(name, action);
	this->allowedActions_[name] = allowedActions;
}

} // Namespace
#include <iostream>
#include <string_utils.h>

#include "mvc_cli_view.h"

using std::cin;
using std::cout;
using std::endl;

using arschitek_utils::split;

namespace circuit_sim
{

MvcCliView::MvcCliView()
{
	this->states_.Add(CliState(this), "main");
}

CliState &MvcCliView::GetCurrState()
{
	return this->states_[this->curr_status_];
}

void MvcCliView::SetController(MvcController * const controller)
{
	controller_ = controller;
}

void MvcCliView::Show(const char *begin)
{
	string input;
	string returnstring;
	vector<string> input_args;

	curr_status_ = string(begin);
	running_ = true;
	while (running_ && input != "exit")
	{
		cout << curr_status_ << "> ";
		getline(cin, input);
		input_args = split(input, " ");
		if (states_[curr_status_].actions_.Exists(input_args[0]))
		{
			returnstring = this->states_[curr_status_].actions_[input_args[0]]->execute(input_args);
			if (returnstring != "")
			{
				curr_status_ = returnstring;
			}
		}
		else if (input_args[0] != "" && input_args[0] != "exit")
		{
			cout << endl << "Error: found no command \"" << input_args[0] << "\" in this context." << endl
				<< "Type \"help\" for a list of available commands." << endl << endl;
		}
	}
	running_ = false;
}

} // Namespace
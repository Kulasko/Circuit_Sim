#include <iostream>

#include "cli_command_print_commands.h"

using std::cout;
using std::endl;

namespace circuit_sim
{

string CliCommandPrintCommands::execute(const vector<string> &args)
{
	cout << endl << "Avaiable commands" << endl << "=================" << endl;
	/*for (size_t i = 0; i < this->state_->actions_.size(); i++)
	{
		cout << this->state_->actions_.Index(i) << " - " << this->state_->actions_[i]->helpdesc << endl;
	}*/
	cout << "exit - exits the program" << endl << endl;
	return "";
}

} // Namespace
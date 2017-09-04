#include "cli_controller_base.h"

namespace arschitek_utils
{

CliControllerBase::CliControllerBase()
{
	// WTF Y U no link?
	this->actions_.Add(CliAction(string("displays the avaiable commands with a short description"), &CliControllerBase::print_help), "help");
	this->Build();
}

void CliControllerBase::Build() {}

string CliControllerBase::print_help(vector<string> &args)
{
	/*for (size_t i = 0; i < this->actions_.size(); i++)
	{
		
	}*/
	return args[1];
}

CliControllerBase::CliAction::CliAction(string &helpdesc, string(CliControllerBase::*action) (vector<string> &args))
{
	this->helpdesc = helpdesc;
	this->action = action;
}

} // Namespace
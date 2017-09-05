#ifndef __CIRCUIT_SIM_UTILS_STRING_UTILS_H__
#define __CIRCUIT_SIM_UTILS_STRING_UTILS_H__

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace arschitek_utils
{

vector<string> split(string const &raw, char const *delimiter = " ")
{
	vector<string> retval;
	size_t part_begin = 0;

	for (size_t i = raw.find_first_of(delimiter); i != string::npos; i = raw.find_first_of(delimiter, part_begin))
	{
		retval.push_back(raw.substr(part_begin, i - part_begin));
		part_begin = i + 1;
	}
	if (raw[raw.size() - 1] != *delimiter)
	{
		retval.push_back(raw.substr(part_begin, raw.length() - part_begin));
	}

	return retval;
}

} // Namespace
#endif // Headerguard
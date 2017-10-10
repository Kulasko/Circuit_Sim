#ifndef __ARSCHITEK_UTILS_STRING_UTILS_H__
#define __ARSCHITEK_UTILS_STRING_UTILS_H__

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace arschitek_utils
{

vector<string> split(const string &raw, const char *delimiter = " ")
{
	vector<string> retval;
	size_t part_begin = 0;

	// Search next delimiter, add Substring from start/last found to next delimiter
	for (size_t i = raw.find_first_of(delimiter); i != string::npos; i = raw.find_first_of(delimiter, part_begin))
	{
		retval.push_back(raw.substr(part_begin, i - part_begin));
		part_begin = i + 1;
	}
	// Get substring from last delimiter to end if the delimiter isn't at the end
	if (raw[raw.size() - 1] != *delimiter)
	{
		retval.push_back(raw.substr(part_begin, raw.length() - part_begin));
	}

	return retval;
}

} // Namespace
#endif // Headerguard
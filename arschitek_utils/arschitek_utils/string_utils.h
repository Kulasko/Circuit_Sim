#ifndef __ARSCHITEK_UTILS_STRING_UTILS_H__
#define __ARSCHITEK_UTILS_STRING_UTILS_H__

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace arschitek_utils
{

vector<string> split(const string &raw, const char *delimiter = " ");

} // Namespace
#endif // Headerguard
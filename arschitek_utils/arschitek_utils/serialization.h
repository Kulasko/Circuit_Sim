#ifndef _ARSCHITEK_SERIALIZATION_H_
#define _ARSCHITEK_SERIALIZATION_H_

#include <iostream>
#include <sstream>

using std::istream;
using std::ostream;
using std::string;

namespace arschitek_utils
{

class SerializedString
{
public:
	inline string getdata_();
	inline size_t get_current_position();

	inline void append(const string &newData);
	inline void append(const SerializedString &newdata_);
	// special append to cut the shell
	inline void append(istream &stream);

	template<typename T>
	void append_flat(const T &newdata_)
	{
		_append((char*)&newdata_, sizeof(T));
	}

	template<class c>
	c request()
	{
		c *retval = (c*)(data_.c_str() + outpos_);
		outpos_ += sizeof(c);
		return *retval;
	}

	// retrieve serializedString that was stored by append(const SerializedString)
	inline SerializedString request();

private:
	string data_;
	size_t outpos_ = 0;

	inline void append_(char const *data, size_t size);
};

class serializable
{
	virtual SerializedString serialize() = 0;
	virtual void deserialize(SerializedString &data) = 0;
};

inline ostream& write(ostream &stream, SerializedString &serializeddata_);
inline istream& read(istream &stream, SerializedString &serialzeddata_);

} // Namespace

#endif // _CIRCUIT_SIM_SERIALIZATION_HPP_
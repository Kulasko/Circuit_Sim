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
	string getdata_()
	{
		return data_;
	}

	size_t get_current_position()
	{
		return outpos_;
	}

	void append(const string &newData)
	{
		size_t length = newData.size();
		append_flat(length);
		_append(newData.c_str(), length);
	}
	void append(const SerializedString &newdata_)
	{
		size_t length = newdata_.data_.size() - newdata_.outpos_;
		append_flat(length);
		_append(&newdata_.data_[newdata_.outpos_], length);
	}
	void append(istream &stream)
	{
		size_t length;
		stream.read((char*)&length, sizeof(length));
		data_.resize(data_.size() + length);
		stream.read(&data_[outpos_], length);
	}

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

	SerializedString request()
	{
		SerializedString retval;
		size_t length = request<size_t>();
		retval.data_ = data_.substr(outpos_, length);
		outpos_ += length;
		return retval;
	}

private:
	string data_;
	size_t outpos_ = 0;
	void _append(char const *data, size_t size)
	{
		data_.append(data, size);
	}
};

class serializable
{
	virtual SerializedString serialize() = 0;
	virtual void deserialize(SerializedString &data) = 0;
};

inline ostream& write (ostream &stream, SerializedString &serializeddata_)
{
	size_t length = serializeddata_.getdata_().size();
	stream.write((char*)&length, sizeof(length));
	stream.write(serializeddata_.getdata_().c_str(), length);
	return stream;
}

inline istream& read (istream &stream, SerializedString &serialzeddata_)
{
	serialzeddata_.append(stream);
	return stream;
}

} // Namespace

#endif // _CIRCUIT_SIM_SERIALIZATION_HPP_
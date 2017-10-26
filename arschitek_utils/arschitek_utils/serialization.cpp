#include "serialization.h"

namespace arschitek_utils
{

string SerializedString::getdata_()
{
	return data_;
}

size_t SerializedString::get_current_position()
{
	return outpos_;
}

void SerializedString::append(const string &newData)
{
	size_t length = newData.size();
	append_flat(length);
	append_(newData.c_str(), length);
}

void SerializedString::append(const SerializedString &newdata_)
{
	size_t length = newdata_.data_.size() - newdata_.outpos_;
	append_flat(length);
	append_(&newdata_.data_[newdata_.outpos_], length);
}

void SerializedString::append(istream &stream)
{
	size_t length;
	stream.read((char*)&length, sizeof(length));
	data_.resize(data_.size() + length);
	stream.read(&data_[outpos_], length);
}

SerializedString SerializedString::request()
{
	SerializedString retval;
	size_t length = request<size_t>();
	retval.data_ = data_.substr(outpos_, length);
	outpos_ += length;
	return retval;
}

void SerializedString::append_(char const *data, const size_t &size)
{
	data_.append(data, size);
}

inline ostream& write(ostream &stream, SerializedString &serializeddata_)
{
	size_t length = serializeddata_.getdata_().size();
	stream.write((char*)&length, sizeof(length));
	stream.write(serializeddata_.getdata_().c_str(), length);
	return stream;
}

inline istream& read(istream &stream, SerializedString &serialzeddata_)
{
	serialzeddata_.append(stream);
	return stream;
}

} // Namespace
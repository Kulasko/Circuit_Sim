#ifndef __ARSCHITEK_UTILS_INDEXED_VECTOR_H__
#define __ARSCHITEK_UTILS_INDEXED_VECTOR_H__

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::size_t;
using std::vector;

namespace arschitek_utils
{

template <typename T1, typename T2>
class IndexedVector
{
public:
	// numerical index
	T2 &at(const size_t &index)
	{
		return this->data_[index];
	}
	// key index
	T2 &at(const T1 &index)
	{
		if (this->indices_dirty_)
		{
			this->RebuildIndices_();
		}
		return this->data_[this->index_from_custom_[index]];
	}

	bool Exists(const T1 &index)
	{
		if (this->indices_dirty_)
		{
			this->RebuildIndices_();
		}
		return index_from_custom_.count(index);
	}
	// key at given numerical index
	T1 Index(const size_t &numerical_index)
	{
		return indices_[numerical_index];
	}
	// operator-extensions
	T2 &operator [](const size_t &index)
	{
		return this->at(index);
	}
	T2 &operator [](const T1 &index)
	{
		return this->at(index);
	}
	size_t size()
	{
		return this->data_.size();
	}

	// dirty indices for lazy index linking
	void Add(const T2 &data, const T1 &index)
	{
		this->data_.push_back(data);
		this->indices_.push_back(index);
		this->indices_dirty_ = true;
	}

	void Erase(const T1 &index)
	{
		if (this->indices_dirty_)
		{
			this->RebuildIndices();
		}
		this->Erase(this->index_from_custom_[index]);
	}
	// dirty indices for lazy index linking
	void Erase(const size_t &index)
	{
		this->data_.erase(this->data_.begin() + index);
		this->indices_.erase(this->indices_.begin() + index);
		this->indices_dirty_ = true;
	}

private:
	vector<T1> indices_;
	vector<T2> data_;
	unordered_map<T1, size_t> index_from_custom_;
	bool indices_dirty_;

	void RebuildIndices_()
	{
		this->index_from_custom_.clear();
		for (size_t i = 0; i < this->indices_.size(); i++)
		{
			this->index_from_custom_[this->indices_[i]] = i;
		}
		this->indices_dirty_ = false;
	}
};

} // Namespace
#endif // Headerguard
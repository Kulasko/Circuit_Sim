#ifndef __CIRCUIT_SIM_UTILS_INDEXED_VECTOR_H__
#define __CIRCUIT_SIM_UTILS_INDEXED_VECTOR_H__

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

namespace arschitek_utils
{

template <typename T1, typename T2>
class IndexedVector
{
public:
	T2 at(size_t index)
	{
		return this->data_[index];
	}
	T2 at(T1 index)
	{
		if (this->indices_dirty_)
		{
			this->RebuildIndices();
		}
		return this->data_[this->index_from_custom_[index]];
	}
	T2 operator [](size_t index)
	{
		return this->at(index);
	}
	T2 operator [](T1 index)
	{
		return this->at(index);
	}
	size_t size()
	{
		return this->indices_.size();
	}


	void Add(T2 data, T1 index)
	{
		this->data_.push_back(data);
		this->indices_.push_back(index);
		this->indices_dirty_ = true;
	}
	void Erase(size_t index)
	{
		if (this->indices_dirty_)
		{
			this->RebuildIndices();
		}
		this->Erase(this->index_from_custom_[index]);
	}
	void Erase(T1 index)
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
		for (size_t i = 0; i < this->indices.size(); i++)
		{
			this->index_from_custom_[this->indices_[i]] = this->data_[i];
		}
		this->indices_dirty_ = false;
	}
};

} // Namespace
#endif // Headerguard
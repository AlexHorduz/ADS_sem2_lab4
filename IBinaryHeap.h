#pragma once
#include <vector>

template <class T>
class IBinaryHeap {
public:
	virtual void insert(T value) = 0;
	virtual bool erase(T value) = 0;
	virtual bool contains(T value) = 0;
	virtual std::vector<T> getOrderedSequence() = 0;
};
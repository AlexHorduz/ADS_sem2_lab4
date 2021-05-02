#pragma once
#include <vector>
#include <exception>

template <class T>
class MaxBinaryHeap : public IBinaryHeap<T> {
private:
	std::vector<T> tree;
	int size;

	int getParent(int index) {
		return (index - 1) / 2;
	}

	int getLeft(int index) {
		return index * 2 + 1;
	}

	int getRight(int index) {
		return index * 2 + 2;
	}

	void heapify(int index) {
		int current = index;
		int parentInd = getParent(current);

		while (parentInd != -1 && tree[parentInd] < tree[current]) {
			T temp = tree[parentInd];
			tree[parentInd] = tree[current];
			tree[current] = temp;
			
			current = parentInd;
			parentInd = getParent(current);
		}
	}

	void heapDown(int index) {
		if (index >= size) {
			return;
		}
		int leftInd = getLeft(index);
		int rightInd = getRight(index);
		if (rightInd >= size && leftInd >= size) {
			return;
		}

		if (rightInd >= size) {
			if (tree[leftInd] > tree[index]) {
				T temp = tree[leftInd];
				tree[leftInd] = tree[index];
				tree[index] = temp;
				heapDown(leftInd);
				return;
			}
		}

		if (tree[leftInd] > tree[rightInd]) {
			if (tree[index] >= tree[leftInd]) {
				return;
			} else {
				T temp = tree[leftInd];
				tree[leftInd] = tree[index];
				tree[index] = temp;
				heapDown(leftInd);
			}
		} else {
			if (tree[index] >= tree[rightInd]) {
				return;
			} else {
				T temp = tree[rightInd];
				tree[rightInd] = tree[index];
				tree[index] = temp;
				heapDown(rightInd);
			}
		}
	}
public:

	MaxBinaryHeap() {
		this->tree.resize(15, 0);
		size = 0;
	}

	MaxBinaryHeap(int size) {
		this->tree.resize(size, 0);
		this->size = 0;
	}

	MaxBinaryHeap(const MaxBinaryHeap<T>& other) {
		this->tree = std::vector<T>(other.tree.begin(), other.tree.begin() + other.size);
		this->size = other.size;
	}

	T getMax() {
		if (size == 0) {
			throw std::logic_error("Heap is empty!");

		}
		return tree[0];
	}

	void insert(T value) override {
		if (size == tree.size()) {
			tree.resize(size * 2, 0);
		}
		tree[size++] = value;
		heapify(size - 1);
	}

	bool erase(T value) override {
		for (int i = 0; i < size; i++) {
			if (tree[i] == value) {
				tree[i] = tree[--size];
				heapDown(i);
				return true;
			}
		}
		return false;
		
	}

	bool contains(T value) override {
		for (int i = 0; i < size; i++) {
			if (tree[i] == value) {
				return true;
			}
		}
		return false;
	}

	std::vector<T> getOrderedSequence() override {
		MaxBinaryHeap<T>* copy = new MaxBinaryHeap<T>(*this);
		std::vector<T> sorted;
		for (int i = 0; i < size; i++) {
			sorted.push_back(copy->getMax());
			copy->erase(copy->getMax());
		}
		return sorted;
	}


};
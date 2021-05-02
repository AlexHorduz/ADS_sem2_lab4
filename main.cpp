#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include "IBinaryHeap.h"
#include "MaxBinaryHeap.h"


using namespace std;
using namespace std::chrono;

int main()
{
	IBinaryHeap<int>* heap = new MaxBinaryHeap<int>;

	auto start_time = high_resolution_clock::now();
	for (int i = 0; i < 10001; i++) {
		heap->insert(i);
	}
	auto end_time = high_resolution_clock::now();
	auto time = end_time - start_time;
	cout << "Insertion of 10.001K elements from 0 to 10000 takes " << (duration_cast<microseconds>(time).count() / 1000.0) << " ms\n";
	heap->clear();

	start_time = high_resolution_clock::now();
	for (int i = 10000; i >= 0; i--) {
		heap->insert(i);
	}
	end_time = high_resolution_clock::now();
	time = end_time - start_time;
	cout << "Insertion of 10.001K elements from 10000 to 0 takes " << (duration_cast<microseconds>(time).count() / 1000.0) << " ms\n";
	heap->clear();
	cout << "\n\n";

	for (int i = 0; i < 10001; i++) {
		heap->insert(i);
	}
	start_time = high_resolution_clock::now();
	for (int i = 0; i < 10001; i++) {
		heap->erase(i);
	}
	end_time = high_resolution_clock::now();
	time = end_time - start_time;
	cout << "Deletion of 10.001K elements from 0 to 10000 takes " << (duration_cast<microseconds>(time).count() / 1000.0) << " ms\n";
	heap->clear();


	for (int i = 0; i < 10001; i++) {
		heap->insert(i);
	}
	start_time = high_resolution_clock::now();
	for (int i = 10000; i >= 0; i--) {
		heap->erase(i);
	}
	end_time = high_resolution_clock::now();
	time = end_time - start_time;
	cout << "Deletion of 10.001K elements from 10000 to 0 takes " << (duration_cast<microseconds>(time).count() / 1000.0) << " ms\n";
	heap->clear();
	cout << "\n\n";

	for (int i = 0; i < 10001; i++) {
		heap->insert(i);
	}
	start_time = high_resolution_clock::now();
	for (int i = 10000; i >= 0; i--) {
		heap->contains(-1);
	}
	end_time = high_resolution_clock::now();
	time = end_time - start_time;
	cout << "10.001K searches of unexisting elements in 10.001K size heap takes " << (duration_cast<microseconds>(time).count() / 1000.0) << " ms\n";



	start_time = high_resolution_clock::now();
	for (int i = 10000; i >= 0; i--) {
		heap->contains(5000);
	}
	end_time = high_resolution_clock::now();
	time = end_time - start_time;
	cout << "10.001K searches of 5000 in 10.001K size heap takes " << (duration_cast<microseconds>(time).count() / 1000.0) << " ms\n";
	cout << "\n\n";

	start_time = high_resolution_clock::now();
	for (int i = 0; i >= 0; i--) {
		heap->getOrderedSequence();
	}
	end_time = high_resolution_clock::now();
	time = end_time - start_time;
	cout << "Getting sorted sequence from 10.001K size heap takes " << (duration_cast<microseconds>(time).count() / 1000.0) << " ms\n";
}

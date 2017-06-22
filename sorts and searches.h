#ifndef __sorts__
#define __sorts__

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;
namespace sortsAndSearches {
	class sorts {
		friend int partition(vector<int> &v1, int low, int high);
		friend int randomPartition(vector<int> &v1, int low, int high);
		friend void print(const vector<int> &v1);
	public:
		sorts() {}
		void countingSortA(vector<int> &v1);
		void radixSortLsdA(vector<int> &v1);
		void bucketSortA(vector<int> &v1);

		void countingSortD(vector<int> &v1);
		void radixSortLsdD(vector<int> &v1);
		void bucketSortD(vector<int> &v1);

		void quickSort(vector<int> &v1, int low, int high);
		void randomQuickSort(vector<int> &v1, int low, int high);

	};
	int partition(vector<int> &v1, int low, int high);
	int randomPartition(vector<int> &v1, int low, int high);
	void print(const vector<int> &v1);


	class searches {
	public:
		searches() {}

		int randomizedSelectMin(vector<int> &v1, int first, int last, int i);

		
	};


}
#endif
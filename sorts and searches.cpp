#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include "sorts and searches.h"

using namespace std;
using namespace sortsAndSearches;

void sortsAndSearches::print(const vector<int>& v1)
{
	for (auto q : v1)
		cout << q << " ";
	cout << endl;
}

void sortsAndSearches::sorts::countingSortA(vector<int>& v1)
{
	int min, max;
	min = *min_element(v1.begin(), v1.end());
	max = *max_element(v1.begin(), v1.end());
	vector<int> test(max - min + 1);
	for (int i = 0; i < v1.size(); ++i) {
		test[v1[i] - min]++;
	}
	cout << "Min " << min << " Max " << max << endl;
	int counter = 0;
	for (int i = min; i <= max; ++i) {
		for (int j = 0; j < test[i - min]; ++j)
		{
			v1[counter++] = i;
		}
	}
	print(v1);
}

void sortsAndSearches::sorts::radixSortLsdA(vector<int>& v1)
{
	vector<int> bucket(v1.size());
	int digitPosition = 1;
	int max = *max_element(v1.begin(), v1.end());
	int pass = 1;
	while (max / digitPosition > 0) {
		vector<int> digitCounter(v1.size());

		for (int i = 0; i <v1.size(); ++i)
			digitCounter[(v1[i] / digitPosition) % v1.size()]++;
		for (int i = 1; i <v1.size(); ++i)
			digitCounter[i] += digitCounter[i - 1];
		for (int i = v1.size() - 1; i >= 0; --i)
			bucket[--digitCounter[v1[i] / digitPosition % v1.size()]] = v1[i];
		for (int i = 0; i != v1.size(); ++i)
			v1[i] = bucket[i];

		cout << "pass # " << pass++ << ": ";
		print(v1);
		digitPosition *= v1.size();
	}
}

void sortsAndSearches::sorts::quickSort(vector<int> &v1, int first, int last) {
	int pivotPoint;
	if (first < last) {
		
		pivotPoint = partition(v1, first, last);
		cout << "Pivot Point <<  " << pivotPoint << endl;
		quickSort(v1, first, pivotPoint - 1);
		quickSort(v1, pivotPoint + 1, last);
	}
}

void sortsAndSearches::sorts::bucketSortA(vector<int> &v1) {
	int min = *min_element(v1.begin(),v1.end());
	int max  =* max_element(v1.begin(), v1.end());
	max++;
	vector<int> buckets(max);
	for (int i = 0; i < v1.size(); ++i) {
		++buckets[v1[i]];
	}

	for (int i = 0, j = 0; j < max; ++j) {
		for (int k = buckets[j]; k > 0; k--) {
			v1[i++] =j;
		}
	}
}

void sortsAndSearches::sorts::countingSortD(vector<int>& v1)
{
	countingSortA(v1);
	reverse(v1.begin(), v1.end());
}

void sortsAndSearches::sorts::radixSortLsdD(vector<int>& v1)
{
	countingSortA(v1);
	reverse(v1.begin(), v1.end());
}

void sortsAndSearches::sorts::bucketSortD(vector<int>& v1)
{
	countingSortA(v1);
	reverse(v1.begin(), v1.end());
}

int sortsAndSearches::randomPartition(vector<int> &v1, int first, int last) {
	int i = first +rand() % (last -first +1);
	swap(v1[last], v1[i]);
	return partition(v1, first, last);
}

void sortsAndSearches::sorts::randomQuickSort(vector<int> &v1, int first, int last) {
	int pivotPoint;
	if (first < last) {
		pivotPoint = randomPartition(v1, first, last);
		randomQuickSort(v1, first, pivotPoint - 1);
		randomQuickSort(v1, pivotPoint + 1, last);
	}
}

int sortsAndSearches::partition(vector<int> &v1, int first, int last) {
	int pivotVal = v1[last];
	int i = first - 1;
	for (int j = first; j < last ; ++j) {
		if (v1[j] <= pivotVal) {
			++i;
			swap(v1[i], v1[j]);
		}
	}
	swap(v1[i + 1], v1[last]);
	return i + 1;
}

int sortsAndSearches::searches::randomizedSelectMin(vector<int>& v1, int first, int last, int i)
{
	if (first == last)
		return v1[first];
	int q = randomPartition(v1, first, last);
	int k = q - first + 1;
	if (i == k)
		return v1[q];
	else if (i < k)
		return randomizedSelectMin(v1, first, q - 1, i);
	return randomizedSelectMin(v1, q+1, last, i-k);
}

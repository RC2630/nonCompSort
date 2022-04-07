#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> balancedTreeSort(const vector<int>& v) {
	map<int, int> freq;
	for (int n : v) {
		freq[n]++;
	}
	vector<int> sorted;
	for (const auto& [num, count] : freq) {
		for (int i = 0; i < count; i++) {
			sorted.push_back(num);
		}
	}
	return sorted;
}

vector<int> nonCompSort(const vector<int>& v) {
	int max = *max_element(v.begin(), v.end());
	int min = *min_element(v.begin(), v.end());
	vector<int> freq;
	for (int i = min; i <= max; i++) {
		freq.push_back(0);
	}
	for (int n : v) {
		freq.at(n - min)++;
	}
	vector<int> sorted;
	for (int i = 0; i < freq.size(); i++) {
		int currEl = i + min;
		for (int r = 0; r < freq.at(i); r++) {
			sorted.push_back(currEl);
		}
	}
	return sorted;
}

void disp(const vector<int>& v) {
	for (int n : v) {
		cout << " " << n;
	}
}

int randint(int a, int b) {
	return rand() % (b - a + 1) + a;
}

void bigTest(function<vector<int> (const vector<int>&)> sort, int size, int min, int max, bool nonComp) {
	vector<int> v;
	for (int i = 0; i < size; i++) {
		v.push_back(randint(min, max));
	}
	if (nonComp) {
		vector<int> sorted = sort(v);
	} else {
		std::sort(v.begin(), v.end());
	}
}

int main(int argc, char** argv) {
  if (argc == 1) {
		cout << "\nno arguments found\n\n";
		return 0;
	}
	auto sort = nonCompSort;
	if (argc == 5) {
		srand(time(nullptr));
		bigTest(sort, stoi(argv[1]), stoi(argv[2]), stoi(argv[3]), stoi(argv[4]));
		return 0;
	}
	vector<int> v;
	for (int i = 1; i < argc; i++) {
		v.push_back(stoi(argv[i]));
	}
	cout << "\noriginal:"; disp(v);
	vector<int> sorted = sort(v);
	cout << "\n  sorted:"; disp(sorted);
	cout << "\n\n";
}
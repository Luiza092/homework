#include <iostream>
#include <forward_list>

void print(const std::forward_list<int> &fl) {
	for (int x : fl) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

void insertionSort(std::forward_list<int> &fl) {
	if (fl.empty()) {
		return;
	}

	std::forward_list<int> sorted;

	for (int x : fl) {
		auto prev = sorted.before_begin();
		auto curr = sorted.begin();
		while (curr != sorted.end() && *curr < x) {
			++prev;
			++curr;
		}
		sorted.insert_after(prev, x);
	}

	fl = sorted;
}

int main() {
	std::forward_list<int> fl = {5, 2, 8, 1, 9};
	insertionSort(fl);
	print(fl);

	return 0;
}


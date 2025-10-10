#include <iostream>
#include <forward_list>

void print(const std::forward_list<int> &fl) {
	for(int x : fl) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
}

std::forward_list<int> mergeSortedLists(std::forward_list<int> &fl1, std::forward_list<int> &fl2) {
	auto prev = fl1.before_begin();
	auto it1 = fl1.begin();
	auto it2 = fl2.begin();

	while(it1 != fl1.end() && it2 != fl2.end()) {
		if(*it2 < *it1) {
			fl1.insert_after(prev, *it2);
			++it2;
			++prev;

		} else {
			++prev;
			++it1;
		}
	}
	if(it2 != fl2.end()) {
		fl1.insert_after(prev, it2, fl2.end());
	}
	fl2.clear();
	return fl1;
}


int main() {
	std::forward_list<int> fl1 = {1, 3, 5};
	std::forward_list<int> fl2 = {2, 4, 6};
	std::forward_list<int> result = mergeSortedLists(fl1, fl2);
	print(result);

	return 0;
}
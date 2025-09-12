#include <iostream>

bool isEven(const int& x) {
	return x % 2 == 0;
}

bool isSame(const std::string& x) {
	if(x == "r" || x == "a" || x == "u") {
		return true;
	}
	return  false;
}

bool isPositiv(const double& x) {
	return x > 0;
}

template <typename T, typename P>
void filter(T* array,int size, P pred) {
	T arr2[100] {};
	int j = 0;
	for(int i = 0; i < size; i++) {
		if(pred(array[i])) {
			arr2[j] = array[i];
			std::cout << arr2[j] << " ";
			j++;
		}
	}

}


int main()
{
	int arr[5] = {1, 2, 2, 5, 10};
	double arr1[2] = {15.2,-4.3};
	std::string arr2[3] = {"s", "u", "n"};
	filter<int>(arr,5,isEven);
	std::cout << std::endl;
	filter<std::string>(arr2, 3, isSame);
	std::cout << std::endl;
	filter<double>(arr1, 2, isPositiv);
    std::cout << std::endl;
	return 0;
}
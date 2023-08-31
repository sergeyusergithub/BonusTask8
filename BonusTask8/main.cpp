#include <iostream>

void print_arr(int arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

void index_equals(int arr1[],const int length1, int arr2[],const int length2) {
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++) {
			if (arr1[i] == arr2[j]) {
				std::cout << "Index array 1 = " << i << "\n";
				std::cout << "Index array 2 = " << j << "\n";
				std::cout << "-----------------------------\n";
			}
				
		}
	}
}



int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// ������ 1.������� ���������� ��� ������� � ������� ������� ������������� ���������
	
	const int size1 = 5;
	int arr1[size1]{1, 2, 3, 4, 5};

	const int size2 = 6;
	int arr2[size2]{ 3, 5, 2, 4, 8, 5 };


	std::cout << "������ 1.\n�������� ������1:\n";
	print_arr(arr1, size1);

	std::cout << "\n�������� ������2:\n";
	print_arr(arr2, size2);

	std::cout << std::endl;

	index_equals(arr1, size1, arr2, size2);



	return 0;
}
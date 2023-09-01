#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

void index_equals(int arr1[], const int length1, int arr2[], const int length2);

double randomiser();

template <typename T>
void mirr_arr(T arr[], const int length);

double distance(int x1, int y1, int z1, int x2, int y2, int z2);

bool palindrom(int n);

template <typename T>
void print_matrix(T arr[], const int rows, const int cols) {
	for (int i = 0; i < rows; i++) {
		std::cout << "{ ";
		for (int j = 0; j < cols; j++) {
			std::cout << arr[i][j] << ", ";
		}
		std::cout << "\b\b }\n";
	}
}
template <typename T>
void negatiation(T arr[], const int length);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Задача 1.Функция сравнивает два массива и выводит индексы повторяющихся элементов

	const int size1 = 5;
	int arr1[size1]{ 1, 2, 3, 4, 5 };

	const int size2 = 6;
	int arr2[size2]{ 3, 5, 2, 4, 8, 5 };


	std::cout << "Задача 1.\nИсходный массив1:\n";
	print_arr(arr1, size1);

	std::cout << "\nИсходный массив2:\n";
	print_arr(arr2, size2);

	std::cout << std::endl;

	index_equals(arr1, size1, arr2, size2);

	std::cout << "\n\n";

	// Задача 2. Функция выводящая случайное вещественное число.
	std::cout << "Задача 2.\n";

	srand(time(NULL));

	std::cout << "Вещественное случайное число [0..1): " << randomiser() << "\n\n";

	// Задача 3. Функция отражеия массива
	const int size3 = 6;
	const int size4 = 5;
	int arr3[size3]{ 1,2,3,4,5,6 };
	double arr4[size3]{ 1.1,1.2,1.3,1.4,1.5 };
	char arr5[size3]{ 'A','2','B','4','5','C' };

	std::cout << "Задача 3.\nИсходный массив:\n";
	print_arr(arr3, size3);

	std::cout << "Отраженный массив:\n";
	mirr_arr(arr3, size3);
	print_arr(arr3, size3);
	std::cout << std::endl;

	std::cout << "Исходный массив:\n";
	print_arr(arr4, size4);

	std::cout << "Отраженный массив:\n";
	mirr_arr(arr4, size4);
	print_arr(arr4, size4);
	std::cout << std::endl;

	std::cout << "Исходный массив:\n";
	print_arr(arr5, size3);

	std::cout << "Отраженный массив:\n";
	mirr_arr(arr5, size3);
	print_arr(arr5, size3);
	std::cout << std::endl;


	// Задача 4. Функция определяющая расстояние между двумя точками 3д
	std::cout << "Задача 4.\nВведите первую точку -> ";
	int x1, y1, z1;
	std::cin >> x1 >> y1 >> z1;
	std::cout << "Введите вторую точку -> ";
	int x2, y2, z2;
	std::cin >> x2 >> y2 >> z2;

	std::cout << "Расстояние между точками: " << distance(x1, y1, z1, x2, y2, z2) << "\n\n";

	// Задача 5. Функция определяющия является ли число палиндромом.
	std::cout << "Задача 5.\nВведите число -> ";
	std::cin >> n;

	if (palindrom(n))
		std::cout << "Число является палиндромом!\n\n";
	else
		std::cout << "Число не является палиндромом!\n\n";


	// Задача 6. Функция меняющая знаки в массиве.

	std::cout << "Задача 6.\nИзначальный массив:\n";
	const int rows = 4;
	const int cols = 3;

	int matrix[rows][cols]{ 1, 2, -3, 4, -5, 6, -7, 8, 9, -1, 2, 3 };

	print_matrix(matrix, rows, cols);

	for (int i = 0; i < rows; i++)
		negatiation(matrix[i], cols);

	std::cout << "Измененный массив:\n";
	print_matrix(matrix, rows, cols);




	return 0;
}

double randomiser() {
	return rand() / (double)(32767 + 1);
}

double distance(int x1, int y1, int z1, int x2, int y2, int z2)
{

	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));
}

bool palindrom(int n)
{
	int k = 1;
	int length = 0;
	int m = n;

	while (m > 10)
	{
		k *= 10;
		length++;

		m /= 10;
	}
	for (int i = 0; i <= length/2; i++) {
		if (n / k == n % 10) {
			n = n % k / 10;
			k /= 100;
		}
		else
			return false;
	}

	return true;
}


void index_equals(int arr1[], const int length1, int arr2[], const int length2) {
	std::cout << "Индексы одинаковых чисел в массивах.\n";
	for (int i = 0; i < length1; i++) {
		for (int j = 0; j < length2; j++) {
			if (arr1[i] == arr2[j]) {
				std::cout << "Индекс массива 1 = " << i << "\n";
				std::cout << "Индекс массива 2 = " << j << "\n";
				std::cout << "----------------------\n";
			}

		}
	}
}

template<typename T>
void mirr_arr(T arr[], const int length){
	for (int i = 0; i < length / 2; i++)
		std::swap(arr[i], arr[length - 1 - i]);
}

template<typename T>
void negatiation(T arr[], const int length)
{
	for (int i = 0; i < length; i++)
		arr[i] = -arr[i];
}

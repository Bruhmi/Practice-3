#include <iostream>
#include <windows.h>

void toShowArray(int arr[][6], int size){
	int* ptr = *arr;
	system("CLS");
	for (int i = 0; i <= size - 1; i++){
		for (int j = 0; j <= size - 1; j++){
			if (*(ptr + j + i * size) != 0){
				std::cout << *(ptr + j + i * size) << "\t";
			}
			else { std::cout << ' ' << "\t"; }
		}
		std::cout << "\n";
	}
	Sleep(10);
}

void task1(int array[][6]){
	const int size = 6;
	int* ptr1 = *array;
	int start = 0, end = size - 1, direction = 0;
	while (direction <= ((size / 2 * 3 + (size / 2 - 1) - 1))){
		if (direction % 4 == 0){
			start = direction / 4;
			int k = start;
			end = size - 1 - (direction / 4);
			while (k <= end){
				*(ptr1 + k + size * start) = rand() % (size * size) + 1;
				k++;
				toShowArray(array, size);
			}
		}
		if (direction % 4 == 1){
			start = direction / 4 + 1;
			int k = start;
			end = size - 1 - (direction / 4);
			while (k <= end){
				*(ptr1 + end + size * k) = rand() % (size * size) + 1;
				k++;
				toShowArray(array, size);
			}
		}
		if (direction % 4 == 2){
			start = size - 2 - (direction / 4);
			int k = start;
			end = direction / 4;
			while (k >= end){
				*(ptr1 + k + size * (start + 1)) = rand() % (size * size) + 1;
				k--;
				toShowArray(array, size);
			}
		}
		if (direction % 4 == 3){
			start = size - 2 - (direction / 4);
			int k = start;
			end = direction / 4 + 1;
			while (k >= end){
				*(ptr1 + (end - 1) + size * k) = rand() % (size * size) + 1;
				k--;
				toShowArray(array, size);
			}
		}
		direction++;
	}
}

void task2(int array[][6]){
	const int size = 6;
	int* ptr = *array;
	int start = 0, end = size - 1, direction = 0;
	for (int i = 0; i < size; i++){
		if (i % 2 == 0){
			for (int j = 0; j < size; j++){
				*(ptr + i + j * size) = rand() % (size * size) + 1;
				toShowArray(array, size);
			}
		}
		else{
			for (int j = size - 1; j >= 0; j--){
				*(ptr + i + j * size) = rand() % (size * size) + 1;
				toShowArray(array, size);
			}
		}
	}
}

void combSort(int array[][6], const int size){
	int dif = size - 1;
	int* ptr = *array;
	while (dif >= 1){
		for (int i = 0; i + dif < size; i++){
			if (*(ptr + i) > *(ptr + i + dif)){
				int c = *(ptr + i);
				*(ptr + i) = *(ptr + i + dif);
				*(ptr + i + dif) = c;
			}
		}
		dif /= 1.247;
	}
	while (true){
		int k = 0;
		for (int i = 0; i < size - 1; i++){
			if (*(ptr + i) > *(ptr + i + 1)){
				int c = *(ptr + i);
				*(ptr + i) = *(ptr + i + 1);
				*(ptr + i + 1) = c;
			}
			else { k++; }
		}
		if (k == size - 1) {
			break; 
		}
		else k = 0;
	}
}

void subtraction(int array[][6], int numb){
	int* ptr = *array;
	for (int i = 0; i < 6 * 6; i++){
		*(ptr + i) = *(ptr + i) - numb;
	}
}

void addition(int array[][6], int numb){
	int* ptr = *array;
	for (int i = 0; i < 6 * 6; i++){
		*(ptr + i) = *(ptr + i) + numb;
	}
}

void multiply(int array[][6], int numb){
	int* ptr = *array;
	for (int i = 0; i < 6 * 6; i++){
		*(ptr + i) = *(ptr + i) * numb;
	}
}

void divide(int array[][6], int numb){
	int* ptr = *array;
	for (int i = 0; i < 6 * 6; i++){
		*(ptr + i) = *(ptr + i) / numb;
	}
}

void newArr(int arr[][6], int size){
	int* ptr = *arr;
	for (int i = 0; i < size * size; i++){
		*(ptr + i) = rand() % (size * size) + 1;
	}
}

void arraySum(int arr1[][6], int arr2[][6], int arr3[][6], int size){
	int* ptr1 = *arr1;
	int* ptr2 = *arr2;
	int* ptr3 = *arr3;
	for (int i = 0; i < size * size; i++){
		*(ptr3 + i) = *(ptr1 + i) + *(ptr2 + i);
	}
}

int main(){
	setlocale(LC_ALL, "ru");
	const int size = 6;
	int array1a[size][size] = {};
	int array1b[size][size] = {};
	int arrayIhw1[size][size] = {};
	int arrayIhw2[size][size] = {};
	int arrayIhwSum[size][size] = {};
	int op = 0, numb = 0;
	bool rep;

	int task = 1;
	while (task != 0){
		std::cout <<
			"ДЕЙСТВИЯ:\n"
			"1. Показать заполнение массива по спирали.\n"
			"2. Показать заполнение массива змейкой.\n"
			"3. Отсортировать массив.\n"
			"4. Увеличить, уменьшить, умножить или поделить на введенное число\n"
			"5. Сложить две матрицы (идз).\n"
			"0. Завершить работу программы\n\n"

			"Введите номер действия: ";
		std::cin >> task;
		switch (task) {
		case 1:
			task1(array1a);
			break;
		case 2:
			task2(array1b);
			break;
		case 3:
			combSort(array1a, size * size);
			toShowArray(array1a, size);
			break;
		case 4:
			std::cout <<
				"Choose an operation:\n"
				"1) Decrease\n"
				"2) Increase\n"
				"3) Multiply\n"
				"4) Divide\n";

			rep = true;
			while (rep){
				std::cin >> op;
				switch (op) {
				case 1:
					std::cout << "Enter the number: ";
					std::cin >> numb;
					toShowArray(array1a, size);
					Sleep(1000);
					subtraction(array1a, numb);
					toShowArray(array1a, size);
					rep = 0;
					break;
				case 2:
					std::cout << "Enter the number: ";
					std::cin >> numb;
					toShowArray(array1a, size);
					Sleep(1000);
					addition(array1a, numb);
					toShowArray(array1a, size);
					rep = 0;
					break;
				case 3:
					std::cout << "Enter the number: ";
					std::cin >> numb;
					toShowArray(array1a, size);
					Sleep(1000);
					multiply(array1a, numb);
					toShowArray(array1a, size);
					rep = 0;
					break;
				case 4:
					std::cout << "Enter the number: ";
					std::cin >> numb;
					toShowArray(array1a, size);
					Sleep(1000);
					divide(array1a, numb);
					toShowArray(array1a, size);
					rep = 0;
					break;
				default:
					std::cout << "Try again.\n";
				}
			}
			break;
		case 5:
			newArr(arrayIhw1, size);
			toShowArray(arrayIhw1, size);
			std::cout << "First array.\n";
			Sleep(3000);
			newArr(arrayIhw2, size);
			toShowArray(arrayIhw2, size);
			std::cout << "Second array.\n";
			Sleep(3000);
			arraySum(arrayIhw1, arrayIhw2, arrayIhwSum, size);
			toShowArray(arrayIhwSum, size);
			std::cout << "Their summary.\n";
			Sleep(3000);
			break;
		case 0:
			break;
		default:
			std::cout << "Error! Try again.\n";
		}
	}
	return 0;
}

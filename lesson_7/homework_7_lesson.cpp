#include <iostream>

//Описать в коде улучшенный алгоритм быстрой сортировки

/*
Сортировать в массиве целых положительных чисел только чётные числа,
нечётные оставив на своих местах при помощи алгоритма блочной сортировки,
то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3]
превратить в [0 2 2 3 4 6 5 9 8 8 7 3]
*/


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortInserts(int* arr, int first, int len)
{
	//сортировка вставками нужна когда мало элементов в массиве или уже отсортированы
	int temp, pos;
	for (int i = first + 1; i <= len; i++)
	{
		temp = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > temp)
		{
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = temp;
	}
}


void quicksort(int* arr, int first, int last)
{
	int i = first;
	int j = last;
	//находим опорную точку
	int x = arr[(first + last) / 2];

	do
	{
		while (arr[i] < x)
		{
			i++;
		}

		while (arr[j] > x)
		{
			j--;
		}

		if (i <= j)
		{
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
	{
		quicksort(arr, i, last);
	}

	if (first < j)
	{
		quicksort(arr, first, j);
	}
}



int function_mediana(int* arr, int last)
{
	for (int i = 0; i < last; i++)
	{
		int max{ 0 }, min{ 0 };
		for (int j = 0; j < last; j++)
		{
			if (arr[j] != arr[i])
			{
				if (arr[j] > arr[i])
				{
					max++;
				}

				else
				{
					min++;
				}
			}
		}

		if (max == min)
		{
			return arr[i];
		}
	}

}


void improved_sort(int* arr, int first, int last)
{
	if (last - first > 10)
	{
		int mediana = function_mediana(arr, last);
		swap(&arr[mediana], &arr[(first + last) / 2]);
		int i = first;
		int j = last;
		int x = arr[(first + last) / 2];
		do
		{
			while (arr[i] < x)
			{
				i++;
			}
			while (arr[j] > x)
			{
				j--;
			}

			if (i <= j)
			{
				swap(&arr[i], &arr[j]);
				i++;
				j--;
			}
		} while (i <= j);

		quicksort(arr, first, last);
		quicksort(arr, first, j);
	}
	else
	{
		sortInserts(arr, first, last);
		return;
	}

}



int* sozdanie(int length)
{
	int* array;
	array = new int[length];
	return array;
}

void printIntArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << "\t";
	}
}

void delete_array(int* arr)
{
	delete[] arr;
}


void fillRandom(int* arr, int len, int border)
{
	for (int i = 0; i < len; ++i)
	{
		*(arr + i) = rand() % border;
	}
}


void bubbleSort(int* arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				if (arr[j] % 2 != 0 || arr[i] % 2 != 0)
				{
					break;
				}
				else
				{
					swap(&arr[j], &arr[j + 1]);
				}
			}

		}
	}

}


void bucketSort(int* arr, int len)
{
	
	const int max = 11;// константа для обозначения максимального кол - во элементов в каждой корзине
	const int b = 10; //кратное 10, делаем корзины

	int buckets[b][max + 1];//хранение в каждой корзине и счестчика заполнения
	for (int i = 0; i < b; ++i)
	{
		buckets[i][max] = 0;
	}

	for (int digit = 1; digit < 1'000'000'000; digit *= 10)
	{
		//внутри цикла делаем счетчик в корзине
		for (int i = 0; i < max; ++i)
			if (arr[i] % 2 == 0)
			{
				int d = (arr[i] / digit) % b;
								
				int counter = buckets[d][max];
				buckets[d][counter] = arr[i];
				counter++;
				buckets[d][max] = counter;
				
				arr[i] = -1;
			}
		
		//переберем все корзины и сложим их при помощи вспомогательной переменной
		//индексирующей элементы
		int idx = 0;
		for (int i = 0; i < b; ++i)
		{
			for (int j = 0; j < buckets[i][max]; ++j)
			{
				while (arr[idx] != -1)
				{
					idx++;
				}
				arr[idx++] = buckets[i][j];
			}
			buckets[i][max] = 0;

		}
	}
}




int main()
{
		setlocale(LC_ALL, "Rus");

		
		//task_1
		std::cout << "The number of elements in a massive: " << std::endl;
		int length;
		std::cin >> length;
		int* arr = sozdanie(length);
		fillRandom(arr, length, 20);
		printIntArray(arr, length);
		improved_sort(arr, 0, length);

		std::cout << std::endl;
		printIntArray(arr, length);
		delete_array(arr);

	

		
		//task_2
		int arr_2[] = { 0,2,8,3,4,6,5,9,8,2,7,3 };
		printIntArray(arr_2, 11);
		std::cout << "\n\n";
		bucketSort(arr_2, 11);
		printIntArray(arr_2, 11);
	
		return 0;
}
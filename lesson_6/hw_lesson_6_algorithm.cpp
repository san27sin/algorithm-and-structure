#include <iostream>
#include <cmath>


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int** initArray(int row, const int col)
{
	int** array;

	array = new int* [row];
	for (int i = 0; i < row; i++)
	{
		array[i] = new int[col];
	}
	return array;
}

void deleteArray(int** array, const int row, const int col)
{


	for (int i = 0;i < row;i++)
	{
		delete[]array[i];
	}

	delete[] array;
}


void fillArray(int** array, const int row, const int col, int broad)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			*((*(array + i)) + j) = rand() % broad;
		}
	}

}



void print2dIntArray(int** array, const int row, const int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			std::cout << *((*(array + i)) + j) << "\t";
		}
		std::cout << std::endl;
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
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

}

void bubbleSort(int** arr, const int col, const int row)
{
	for (int i = 0; i < (col * row); ++i)
	{
		for (int j = 0; j < (col * row)-1; ++j)
		{
			int cr = j / col;
			int cc = j % col;
			int nr = (j + 1) / col;
			int nc = (j + 1) % col;

			if (arr[cr][cc] > arr[nr][nc])
			{
				swap(&arr[cr][cc], &arr[nr][nc]);
			}
		}
	}
}

void fill_array_task_3(int* arr, int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		
		std::cout << "Enter number of an " << i << " element." << std::endl;
		std::cin >> arr[i];

	}
}

void change_array(int* arr, int SIZE)
{
	int r = SIZE - 1;
	for (int l = 0; l < SIZE/2; ++l)
	{
		swap(&arr[l], &arr[r]);
		--r;
	}

}

void printIntArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << "array ["<<i<<"] = "<<array[i] << "\t";
	}
}

void calculations(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int x = sqrt(fabs(array[i])) + 5 * pow(array[i], 3);
		if (x > 400)
		{
			std::cout << "Your calculation of the number " << array[i] << "  is more than 400" << std::endl;
		}

		else
		{
			std::cout << "Your calculation of the number" << array[i] << " is less than 400" << std::endl;
		}

	}
}


int main()
{
	//task_1
	const int col{ 3 }, row{ 3 };
	int** array;
	array = initArray(row, col);
	fillArray(array, row, col, 30);
	print2dIntArray(array, row, col);
	bubbleSort(array, row, col);
	std::cout << std::endl;
	print2dIntArray(array, row, col);

	deleteArray(array, row, col);


	//task_3
	const int SIZE = 11;
	int array2[SIZE];

	std::cout << std::endl;
	fill_array_task_3(array2, SIZE);
	printIntArray(array2, SIZE);
	std::cout << std::endl;
	change_array(array2, SIZE);
	printIntArray(array2, SIZE);
	std::cout << std::endl;
	calculations(array2, SIZE);


	return 0;
}


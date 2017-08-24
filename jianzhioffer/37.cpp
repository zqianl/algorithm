#include<iostream>
#include<vector>

using namespace std;

void PrintMatrixCircle(int **numbers, int rows, int columns, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;
	for (int i = start; i <= endX; ++i)
		cout << numbers[start][i] << " ";
	if (endY > start)
		for (int i = start + 1; i <= endY; ++i)
			cout << numbers[i][endX] << " ";
	if (endY > start && endX > start)
		for (int i = endX - 1; i >= start; --i)
			cout << numbers[endY][i] << " ";
	if (endY > start + 1 && endX > start)
		for (int i = endY -1 ; i >= start + 1; --i)
			cout << numbers[i][start] << " ";
}

void PrintMatrixClockwisely(int **numbers, int rows, int columns)
{
	if (numbers == NULL || rows <= 0 || columns == 0)
		return;
	int start = 0;
	while (rows > 2 * start&&columns > 2 * start)
	{
		PrintMatrixCircle(numbers, rows, columns, start);
		++start;
	}
}

int main(int argc, char **argv)
{
	int rows, columns;
	cin >> rows >> columns;
	int **numbers = new int*[rows];
	for (int i = 0; i < rows; ++i)
	{
		numbers[i] = new int[columns];
		for (int j = 0; j < columns; ++j)
		{
			numbers[i][j] = i*columns + j + 1;
		}
	}
	PrintMatrixClockwisely(numbers, rows, columns);
	for (int i = 0; i < rows; ++i)
		delete numbers[i];
	delete[] numbers;
	system("pause");
	return 0;
}


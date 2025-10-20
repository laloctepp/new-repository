#include <iostream>

int ** create (size_t r, size_t c)
{
	int ** result = new int * [r];
	size_t i = 0;
	try {
		for (; i < r; ++i) {
			result[i] = new int[c];
		}
	}
	catch (...) {
		remove (result, i);
		throw;
	}
}

void remove (int ** m, size_t rows)
{
	for (size_t i=0; i < rows; ++i) {
		delete[] m[i];
	}
	delete[] m;
}

void input (int ** m, size_t rows, size_t cols) 
{
	for (size_t i=0; i < rows && (std::cin); ++i) {
		for (size_t j=0; j < cols && (std::cin); ++j) {
			std::cin >> m[i][j];
		}
	}
}

void output (const int * const * m, size_t rows, size_t cols)
{
	std::cout << rows << " " << cols; 
	//
}

int main()
{
	size_t rows=0, cols=0;
	std::cin >> rows >> cols;
	if (!std::cin) {
		return 1;
	}
	int ** m = create (rows, cols);
	input (m, rows, cols);
	if (!std::cin) {
		remove (m, rows, cols);
		return 1;
	}
	output (m, rows, cols);
	remove (m, rows);
	std::cout << rows << " " << cols;
	std::cout << "\n";
}

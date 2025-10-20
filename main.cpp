#include <iostream>

void remove (int ** m, size_t rows)
{
	for (size_t i=0; i < rows; ++i) {
		delete[] m[i];
	}
	delete[] m;
}

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
	return result;
}

void input (int ** m, size_t rows, size_t cols) 
{
	for (size_t i=0; i < rows && (std::cin); ++i) {
		for (size_t j=0; j < cols && (std::cin); ++j) {
			std::cin >> m[i][j];
		}
	}
}

void output (const int * const * m, size_t rows, size_t cols) {
	std::cout << rows << " " << cols << "\n"; 
	for (size_t i=0; i < rows; ++i) {
		std::cout << m[i][0];
		for (size_t j=1; j < cols; ++j) {
			std::cout << " " << m[i][j]; 
		}
		std::cout << "\n";
	}
}

int ** convert (const int * t, size_t n, const size_t * lns, size_t rows) {
    int ** result = new int * [rows];
    size_t i = 0;
    try {
		for (size_t i=0; i < rows; ++i) {
			result[i] = new int[lns[i]];
		}
	}
	catch (...) {
		remove (result, i);
		throw;
	}
    size_t k = 0;
    for (size_t i =0; i < rows; ++i) {
        for (size_t j =0; j < lns[i]; ++j) {
            result[i][j] = t[k];
            ++k;
        }
    }
    return result;
}

int main()
{
	size_t rows=0, cols=0;
	std::cin >> rows >> cols;
	if (!std::cin) {
		return 1;
	}
	try {
		int ** m = create (rows, cols);
		input (m, rows, cols);
	    if (!std::cin) {
			remove (m, rows);
			return 1;
		}
		output (m, rows, cols);
		remove (m, rows);
		std::cout << "\n";
	}
	catch (...) {
		return 2;
	}
}

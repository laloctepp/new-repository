#include <iostream>

void remove (int ** m, size_t rows)
{
	for (size_t i=0; i < rows; ++i) {
		delete[] m[i];
	}
	delete[] m;
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

int main() {
    int t[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 10;
    size_t lns[4] = {1, 2, 4 , 3};
    int rows = 4;
    convert (t, n, lns, rows); 
    
    for (size_t i=0; i < rows; ++i) {
		std::cout << convert (t, n, lns, rows)[i][0];
		for (size_t j=1; j < lns[i]; ++j) {
			std::cout << " " << convert (t, n, lns, rows)[i][j]; 
		}
		std::cout << "\n";
	}
}
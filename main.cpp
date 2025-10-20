#include <iostream>

int ** create (size_t rows, size_t cols,)
void remove (int ** m, size_t rows, size_t cols)

int main()
{size_t rows=0, cols=0;
std::cin >> rows >> cols;
if (!std::cin) {
	return 1;
}
std::cout << rows << " " << cols;
std::cout << "\n";
int ** m = create (rows, cols);
}

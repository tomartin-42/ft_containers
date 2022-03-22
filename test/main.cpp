#include <cstddef>
#include <iostream>

int main(void)
{
	float* i = new float[10];
	int* h;
	std::ptrdiff_t diff;

	diff = (i + 9) - i;
	std::cout << diff << std::endl;
	diff = (i + 9) - (i + 1);
	std::cout << diff << std::endl;
	diff = (i + 9) - (h);
	std::cout << diff << std::endl;
}


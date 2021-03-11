#include <iostream>
using namespace std;

static int second[10];

void reverse() {
	int arrL[10] = { 21, 4, 3, 8, 2, 18, -30, 25, 1, 7 };
	_asm {
		mov ecx, 0
		mov edx, 9
		for:
		mov ebx, [arrL + 4 * edx]
			mov[second + 4 * ecx], ebx
			inc ecx
			dec edx
			cmp ecx, 9
			jle for
	}
}

void print_array(int* array, int length)
{
	for (int i = 0; i < length; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
}

int main() {

	reverse();
	print_array(second, 10);

	return 0;
}
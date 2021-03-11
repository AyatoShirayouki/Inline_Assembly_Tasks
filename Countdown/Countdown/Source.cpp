#include <iostream>
using namespace std;

static int arr[10];

void countdown() {
	_asm {
		mov eax, 10
		mov ecx, 0
		for:
		mov[arr + 4 * ecx], eax
			dec eax
			inc ecx
			cmp ecx, 10
			jl for
	}
}

void countup() {
	_asm {
		mov eax, 1
		mov ecx, 0
		for:
		mov[arr + 4 * ecx], eax
			inc eax
			inc ecx
			cmp ecx, 10
			jl for
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
	countdown();
	print_array(arr, 10);

	countup();
	print_array(arr, 10);
	return 0;
}
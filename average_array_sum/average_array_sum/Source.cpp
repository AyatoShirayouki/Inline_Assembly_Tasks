#include <iostream>
using namespace std;
int* fifth;

int avg(int n) {
	_asm {
		mov ebx, fifth;
		mov ecx, 0;
		mov eax, 0;
		for:
		add eax, [ebx + 4 * ecx];
		inc ecx;
		cmp ecx, n;
		jl for;
		mov edx, 0;
		div n;
	}
}

int main() {
	fifth = (int*)malloc(10 * sizeof(int));
	fifth[0] = 11;
	fifth[1] = 6;
	fifth[2] = 2;
	fifth[3] = 11;
	fifth[4] = 6;
	fifth[5] = 6;
	fifth[6] = 18;
	fifth[7] = 4;
	fifth[8] = -11;
	fifth[9] = -1;
	cout << avg(10) << endl;

	return 0;
}
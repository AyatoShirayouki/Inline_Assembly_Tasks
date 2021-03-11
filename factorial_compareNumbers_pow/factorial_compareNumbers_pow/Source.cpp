#include <iostream>
using namespace std;

static int arr[10];

int add2Numbers(int a, int b) {
	int res = 0;
	_asm {
		mov eax, a
		add eax, b
		mov res, eax
	}
	return res;
}

int trianglePerimeter(int a, int b, int c) {
	int res = 0;
	_asm {
		mov eax, a
		add eax, b
		add eax, c
		mov res, eax
	}
	return res;
}

int squarePerimeter(int a) {
	int res = 0;
	_asm {
		mov eax, a
		imul eax, 4
		mov res, eax
	}
	return res;
}

int sumDiv(int a, int b, int c) {
	int res = 0;
	_asm {
		mov eax, a
		add eax, b
		mov edx, 0
		div c
		mov res, eax
	}
	return res;
}

int aCompare(int a) {
	_asm {
		mov eax, 1
		cmp eax, a
		jle return
		mov eax, 0
		cmp eax, a
		je return
		mov eax, -1

		return:
	}
}

int cmp(int a, int b) {
	_asm {
		mov eax, a
		cmp eax, b
		je ravno
		jl malko
		mov eax, -1
		jmp return
		malko:
		mov eax, 1
			jmp return
			ravno :
			mov eax, 0
			return :
	}
}

int cmp2(int a, int b) {
	_asm {
		mov ebx, a
		cmp ebx, b
		mov eax, 0
		je return
		jl jump
		mov eax, 1
		jmp return
		jump:
		mov eax, -1
			return :
	}
}

int cmp3(int a, int b, int c) {
	_asm {
		mov eax, a
		cmp eax, b
		jg nextstep
		mov eax, b
		cmp eax, c
		jg return
		jmp cmax
		nextstep :
		cmp eax, c
			jg return
			cmax :
			mov eax, c
			return :
	}
}

int cmp4(int a, int b, int c) {
	_asm {
		mov eax, a
		cmp eax, b
		jg comparec
		mov eax, b
		comparec :
		cmp eax, c
			jg return
			mov eax, c
			return :
	}
}

int increment(int a) {
	_asm {
		mov eax, a
		mov ecx, 1
		for:
		inc eax
			inc ecx
			cmp ecx, 4
			jle for
	}
}

int fact(int n) {
	_asm {
		mov eax, 1
		mov ecx, 1
		for:
		imul eax, ecx
			inc ecx
			cmp n, ecx
			jge for
	}
}

int factnk(int n, int k) {
	_asm {
		mov eax, 1
		mov ecx, 1

		for:
		imul eax, ecx
			inc ecx
			cmp n, ecx
			jge for

			mov ebx, 1
			mov ecx, 1
			fork:
		imul ebx, ecx
			inc ecx
			cmp k, ecx
			jge fork

			mov edx, 0
			idiv ebx

	}
}

int factnk2(int n, int k) {
	_asm {
		mov ecx, n
		mov eax, 1
		for:
		mul ecx
			dec ecx
			cmp ecx, k
			jg for
	}
}

int PrintArr(int* array, int lenght) {
	for (int i = 0; i < lenght; i++) {
		cout << array[i] << ", ";
	}
	cout << endl;
	return 1;
}

int pow() {
	_asm {
		mov ecx, 0
		for:
		mov eax, [arr + 4 * ecx]
			mul eax
			mov[arr + 4 * ecx], eax
			inc ecx
			cmp ecx, 10
			jl for
	}
}

int main() {


	cout << "Add 2 numbers(2,3): " << add2Numbers(2, 3) << endl;
	cout << "Triangle perimeter(1,2,3): " << trianglePerimeter(1, 2, 3) << endl;
	cout << "Square Perimeter(2): " << squarePerimeter(2) << endl;

	cout << "(a + b) / c (4,6,2):  " << sumDiv(4, 6, 2) << endl;
	cout << "a compare: " << aCompare(0) << endl;
	cout << "cmp(a, b): " << cmp(2, 2) << endl;
	cout << "cmp2(a, b): " << cmp2(3, 2) << endl;
	cout << "cmp3(a, b, c): " << cmp3(3, 2, 1) << endl;
	cout << "cmp4(a, b, c): " << cmp4(2, 1, 3) << endl;
	cout << "increment(a): " << increment(3) << endl;
	cout << "factoriel(n):  " << fact(5) << endl;
	cout << "factoriel(n, k):  " << factnk(5, 3) << endl;
	cout << "factoriel2(n, k):  " << factnk2(5, 3) << endl;

	return 0;
}
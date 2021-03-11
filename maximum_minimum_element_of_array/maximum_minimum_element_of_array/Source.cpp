#include <iostream>
using namespace std;

int minimum() {
	int local[10] = { 10, 15, 1, 28, 16, -18, 5, 20, 1, 3 };
	_asm {
		movsx eax, [local];// this is the first element of the array // we need negative signed
		mov ecx, 0; // index
		for:
		cmp ecx, 10;
		jge return;
		mov edx, [local + 4 * ecx];
		inc ecx;
		cmp eax, edx;
		jle for;
		mov eax, edx;
		jmp for;
		return:
	}
}

int maximum() {
	int local[10] = { 10, 15, 1, 28, 16, -18, 5, 20, 1, 3 };
	_asm {
		movsx eax, [local];// this is the first element of the array // we need negative signed
		mov ecx, 0; // index
		for:
		cmp ecx, 10;
		jge return;
		mov edx, [local + 4 * ecx];
		inc ecx;
		cmp eax, edx;
		jge for;
		mov eax, edx;
		jmp for;
		return:
	}
}

int main() {
	cout << maximum() << endl;
	cout << minimum() << endl;

	return 0;
}
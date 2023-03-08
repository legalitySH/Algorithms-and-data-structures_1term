#include<iostream>
#include<ctime>

using namespace std;

unsigned long long Fib(int N)
{
	if (N == 0)
		return 0;
	if (N == 1)
		return 1;
	return Fib(N - 1) + Fib(N - 2);
}

int main() {
	setlocale(LC_ALL, "rus");
	int N = 0;
	cout << "Введите число N..." << endl;
	cin >> N;
	unsigned long long F0 = 0;
	unsigned long long F1 = 1;
	unsigned long long value = 0;
	clock_t start = clock();
	for (int i = 0; i < N; i++)
	{
		value = F0 + F1;
		F0 = F1;
		F1 = value;

	}
	clock_t finish = clock();
	cout << N << "-е число ряда Фибонначи = " << F1;
	cout << "\nВремя выполнения нахождения циклом :" << double(finish - start) / CLOCKS_PER_SEC;
	start = clock();
	Fib(N);
	finish = clock();
	cout << "\nВремя выполнения нахождения рекурсией :" << double(finish - start) / CLOCKS_PER_SEC;
	return 0;
	

}
#include <iostream>
#include <algorithm>
#include    <vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int N = 0;
	cout << "Введите количество призеров: "; cin >> N;
	vector<int> prizeWinners;
	srand(time(0));
	for (int i = 0; i < N; i++) {
		prizeWinners.push_back(rand() % 100 + 1);
	}

	sort(prizeWinners.begin(), prizeWinners.end());
	reverse(prizeWinners.begin(), prizeWinners.end());

	for (int i = 0; i < N; i++)
	{
		cout << prizeWinners[i] << " ";
	}
	int counter = 0;
	cout << endl;

	cout << "1 место - " << prizeWinners[0] << endl;
	int k = 1;
	while (prizeWinners[0] == prizeWinners[k]) {
		cout << "1 место - " << prizeWinners[0] << endl;
		counter++;
		k++;
	}

	cout << "2 место - " << prizeWinners[k] << endl;
	while (k < N && prizeWinners[k] == prizeWinners[k+1]) {
		cout << "2 место - " << prizeWinners[k] << endl;
		counter++;
		k++;
	}
	k++;
	if (k < N) {
		cout << "3 место - " << prizeWinners[k] << endl;
		k++;
		while (prizeWinners[k] == prizeWinners[k - 1] && k < N) {
			cout << "3 место - " << prizeWinners[k] << endl;
			counter++;
			k++;
		}
	}
	counter += 3;
	cout << "Количество призёров: " << counter << endl;
}
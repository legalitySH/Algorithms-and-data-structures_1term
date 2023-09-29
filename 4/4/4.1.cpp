#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int N, sum = 0;
    cout << "Введите количество товаров = ";
    cin >> N;
    vector<int> list_check;
    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        list_check.push_back(rand() % 100);

        cout << list_check[i] << " ";
    }
    cout << endl;

    sort(list_check.begin(), list_check.end());
    reverse(list_check.begin(), list_check.end());

    int N1 = N;
    vector<int> new_list_check;
    if (!(N % 2)) {
        N--;
        for (int i = 0; i < N; i++)
        {
            new_list_check.push_back(list_check[i]);
            sum += list_check[i];
            new_list_check.push_back(list_check[N]);
            N--;
        }

    }
    else {
        N--;
        int endElem = N - 1;
        for (int i = 0; i < N - 1; i++)
        {
            new_list_check.push_back(list_check[i]);
            sum += list_check[i];
            new_list_check.push_back(list_check[N]);
            N--;
        }
        new_list_check.push_back(list_check[N1 - 1]);
        sum += list_check[N1 - 1];
    }
    cout << endl;
    cout << "Чек: ";
    for (int i = 0; i < N1; i++)
    {
        cout << new_list_check[i] << " ";
    }
    cout << endl;
    cout << "Сумма чека: " << sum << endl;
}
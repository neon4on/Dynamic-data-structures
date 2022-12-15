#include <iostream>
#include <cstring>
using namespace std;

void check(int* i, int* steck) {
    setlocale(LC_ALL, "rus");
    cout << endl << "Это верхний элемент стека: " << steck[*i] << endl;
}

void deletee(int *i) {
    cout << "Удалили верхний элемент" << endl;
    i--;
}

void Vivod(int i, int* steck) {
    for (int j = 0; j < i; j++) {
        cout << steck[j] << " ";
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int n = 0;
    int k = 0; //Первоначально машин
    int i = -1; 
    int dj = 0;
    cout << "Введите количество машин: "; 
    cin >> k;
    int steck[20];

    for (int j = 0; j < k; j++) {
        int a;
        cin >> a;
        i++;  
        steck[i] = a;  // добавляем в стек элемент
    }

    if (i == -1) {
        cout << "Стек пуст";
    }
    else {
        do {
            cout << "Меню:" << endl;
            cout << "1. Приехала новая машина" << endl;
            cout << "2. Печатать гараж" << endl;
            cout << "3. Машина выезжает" << endl;
            cout << "0. Выход" << endl;
            cout << "\n\tЗадайте действие: ";
            cin >> n;
            switch (n)
            {
            case 1: cout << "Введите новое авто: "; vvod(x);
                dobavlenie(&u, x); cout << "\nАвто Добавлено!\a\n"; break;
            case 2: Print(u); break;
            case 3: Print(u); vyezjaet_iz_garaja(&u); break;
            case 0: Clear(&u); break;
            default:cout << "Такого выбора нет :) " << endl;
            }
    }
}
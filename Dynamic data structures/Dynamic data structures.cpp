#include <iostream>
#include <new>
using namespace std;

class Stack
{
public:
    Stack();
    ~Stack();

private:
    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data, Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
};
void main()
{

}
/*do {
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
            }*/
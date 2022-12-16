#include <iostream>
#include <new>
using namespace std;

template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();

    void pop_front();
    void push_back(T data); //Добавление элемента в конец списка

    int GetSize() //Возвращает количество элементов
    {
        return(Size);
    }

    T& operator[](const int index); //Перегружаем оператор

private:
     
    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node <T> *head;
};

template<typename T>
Stack<T>::Stack() {
    Size = 0;
    head = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{

}

template<typename T>
void Stack<T>::pop_front()
{
    Node<T> *temp = head;

    head = head->pNext;

    delete temp;

    Size--;
}

template<typename T>
void Stack<T>::push_back(T data) 
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;
        while (current ->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    Size++;
}

template<typename T>
T& Stack<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");

    Stack<int> lst;

    cout << "Write count: ";
    int numbersCount;
    cin >> numbersCount;
    cout << endl << "Elements: " << endl << endl;
    for (size_t i = 0; i < numbersCount; i++)
    {
        lst.push_back(rand() & 10);
    }

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << " ";
    }

    cout << endl << "Count: " << lst.GetSize() << endl << "Do delete head " << endl << endl;

    lst.pop_front();

    cout << endl << "Elements: " << endl << endl;
    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << " ";
    }


    cout << endl << "Count: " << lst.GetSize() << endl;
    return 0;
}

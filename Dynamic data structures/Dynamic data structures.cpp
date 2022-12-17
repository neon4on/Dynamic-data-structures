#include <iostream>
using namespace std;


/*
* односвязный список
* реализация
*/
int b = 1;

template<typename T>
class List
{
public:
	List();
	~List();

	//удаление первого элемента в списке
	void pop_front();

	//добавление элемента в конец списка
	void push_back(T data);

	// очистить список
	void clear();

	// получить количество елементов в списке
	int GetSize() { return Size; }

	// перегруженный оператор [] 
	T& operator[](const int index);

	//добавление элемента в начало списка
	void push_front(T data);

	//добавление элемента в список по указанному индексу
	void insert(T data, int index);

	//удаление элемента в списке по указанному индексу
	void removeAt(int index);

	//удаление последнего элемента в списке
	void pop_back();

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
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int index)
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

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}




int main()
{

	setlocale(LC_ALL, "ru");


	List<int> lst;
	int n = 1;
	while (n != 6) {
		cout << "Меню:" << endl;
		cout << "1. Приехала новая машина" << endl;
		cout << "2. Печатать гараж" << endl;
		cout << "3. Машина выезжает" << endl;
		cout << "0. Выход" << endl;
		cout << "\nЗадайте действие: ";
		cin >> n;
		cout << endl;
		switch (n)
		{
		case 1: cout << "Введите номер авто: ";
			int p;
			cin >> p;
			lst.push_front(p);
			cout << "\nАвто под номером " << p << " Добавлено" << endl << endl; break;
		case 2: for (int i = 0; i < lst.GetSize(); i++)
		{
			cout << lst[i] << " ";
		}; cout << endl << endl; break;
		case 3:
			cout << "Введите индекс позиции машины, который вы хотите удалить ";
			int k;
			cin >> k;
			cout << endl;
			lst.removeAt(k);
			cout << "\nАвто под индексом " << k << " Удалено" << endl << endl; break;
		case 0: lst.clear(); n = 6; break;
		default:cout << "Такого выбора нет " << endl;
		}
	}
}

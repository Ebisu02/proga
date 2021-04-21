#include "include.h"

struct info {
	string Surname;
	int Grades[4];
};

template <typename T>
class List_One_Link {

	public:

		List_One_Link();	// Конструктор (при создании данных такого типа)
		~List_One_Link();	// Деструктор (при завершении работы программы)

		void pop_front();		// Метод для удаления первого элемента списка (головы)
		void push_back(T data); // Метод для добавления элемента в конец списка
		int GetSize();			// Метод для получения размера списка
		void clear();			// Метод для очистки списка

		T& operator[](const int index); // Шаблон для работы с квадратными скобками (для индексов и т.п.)

	private:
	
		template <typename T> 
		class Node { // Вложенный класс Node(узел), т.е. по сути 1 из элементов списка
		
		public:
			Node* pNext;	// указатель на адрес в памяти следующего нашего элемента в списке
			T data;			// какие-то данные, которые хранятся в данном узле
			Node(T data = T(), Node* pNext = NULL) { // Конструктор класса Node
				// Параметр по умолчанию для data - 
				// она равна конструктуру по умолчанию (с помощью шабл. классов)
				// Параметр по умолчанию для pNext - он равен нулю
				this->data = data;		// Присваиваем входящие параметры
				this->pNext = pNext;	// Присваиваем входящие параметры
			}
		};
		int Size;		// Размер списка
		Node<T> *head;	// Указатель на голову списка
};

template <typename T>
List_One_Link<T>::List_One_Link() {
	Size = 0;		// Т.к. мы только создали список, то размер у него пока равен нулю
	head = nullptr; // Мы точно будем знать что на данный момент наш список пуст
}

template <typename T>
List_One_Link<T>::~List_One_Link() { // Деструктор, чтобы не было утечек памяти
	clear(); // Для того чтобы очистить память, когда закончится наша программа
}

template<typename T>
void List_One_Link<T>::pop_front() {
	Node<T> *Temp = head;	// Создадим указатель на ячейку памяти, где хранится голова списка
	head = head->pNext;		// Теперь голова списка - следующий элемент
	delete Temp;			// Очищаем ячейку памяти, где лежала старая голова списка
	--Size;					// Уменьшаем размер списка, т.к. мы уже стерли элемент
}

template<typename T>
void List_One_Link<T>::push_back(T data) {

	if (head == nullptr) {					// Если в списке еще нет элементов
		head = new Node<T>(data);			// Создаем новый элемент в списке
	}
	else {									// Если в списке уже есть элементы
		Node<T>* Current = this->head;		// Временная переменная, По умолчанию равна адресу головы списка
		
		while (Current->pNext != nullptr) { // Если Current != концу списка 
			Current = Current->pNext;		// Переходим к следубщему элементу
		}

		Current->pNext = new Node<T>(data); // Создаем новый элемент в списке

	}

	++Size;
}

template<typename T>
int List_One_Link<T>::GetSize() { // Функция возвращения размера списка
	return Size;
}

template<typename T>
void List_One_Link<T>::clear() { // Функция очистки списка

	while (Size) { // Пока Size > 0
		pop_front();
	}

}

template<typename T>
T& List_One_Link<T>::operator[](const int index) { // Для работы с индексами
											// Это все нам нужно чтобы обращаться к списку так List[0] и т.п.
	int counter = 0; 
	Node<T>* Current = this->head;			// Начинаем свой проход с головы списка

	while (Current != nullptr) {			// Пока это не конец списка
		if (counter == index) {				// Если мы попали в нужный элемент списка
			return Current->data;			// Возвращаем данные
		}
		Current = Current->pNext;			// Если не попали, то переходим к следующему
		++counter;							// Увеличиваем индекс на котором мы сейчас находимся на 1
	}
}

// Индексная сортировка для лабы 9.1 по фамилии
// TODO: трайнуть через обычные перестановки в списке
void IndexSort(List_One_Link<info>& arr, int indexArr[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			info buf = arr[indexArr[j]];
			info buf_plus = arr[indexArr[j + 1]];
			if (buf.Surname[0] > buf_plus.Surname[0]) {
				swap(indexArr[j], indexArr[j + 1]);
			}
		}
	}
}

void lab_9_1() {
	srand(time(nullptr));
	int size = 10;
	string exampleSurname[10] = { {"Guliev"}, {"Artemev"}, {"Shemenkov"}, {"Pletuhin"}, {"Pertsev"}, {"Ivanov"}, {"Petrov"}, {"Fedorov"}, {"Ososov"}, {"Pivchik"} };
	int exampleGrade[] = { {2}, {3}, {4}, {5} };
	List_One_Link<info> listOfStudents;
	// Заполняем наш список
	for (int i = 0; i < size; ++i) {
		info buf; // Временная переменная для занесения данных в список
		buf.Surname = exampleSurname[i];
		cout << "\n" << buf.Surname << " ";
		for (int j = 0; j < 4; ++j) {
			buf.Grades[j] = exampleGrade[rand() % 4];
			cout << buf.Grades[j] << " ";
		}
		listOfStudents.push_back(buf);
	}
	// Создадим индексный массив для сортировки которая будет далее
	int* arr;
	arr = new int[size];
	cout << "\n\nIndex array before:\n";
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
		cout << arr[i] << " ";
	}
	// Сортируем это дерьмо
	IndexSort(listOfStudents, arr, size);
	cout << "\n\nList after Sort:\n";
	// Вывод отсортированный список
	for (int i = 0; i < size; ++i) {
		info buf = listOfStudents[arr[i]];
		cout << "\n" << buf.Surname;
		for (int j = 0; j < 4; ++j) {
			buf.Grades[j] = exampleGrade[rand() % 4];
			cout << buf.Grades[j] << " ";
		}
	}
	// Индексный массив выводим
	cout << "\n\nIndex array after Sort:\n";
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	delete[] arr;
	cout << "\n\n";
	return;
} 

template<typename T>
class List
{
private :
	template <typename T>
	class Elem { // Вложенный класс Node(узел), т.е. по сути 1 из элементов списка

	public:
		Elem* next;	// указатель на адрес в памяти следующего нашего элемента в списке
		Elem* prev;
		T data;			// какие-то данные, которые хранятся в данном узле
		Elem(T data = T(), Elem* next = NULL, Elem* prev = NULL) { // Конструктор класса Node
			// Параметр по умолчанию для data - 
			// она равна конструктуру по умолчанию (с помощью шабл. классов)
			// Параметр по умолчанию для pNext - он равен нулю
			this->data = data;		// Присваиваем входящие параметры
			this->next = next;	// Присваиваем входящие параметры
			this->prev = prev;
		}
	};
	int Size;		// Размер списка
	Elem<T>* Head;	// Указатель на голову списка
	Elem<T>* Tail;
public:

    List();
    void push_back(T data);
    void pop_front();
    void clear();
	void pop(const int index);
    const T& operator [](const int);
    int getSize();
    ~List();
	void pop_back();
};

template<typename T>
List<T>::List()
{
    Head = NULL;
    Tail = NULL;
    Size = 0;
}

template<typename T>
void List<T>::push_back(T data)
{
    if (Head == NULL)
    {
        Head = Tail = new Elem<T>;
        Head->data = data;

        ++Size;

    }
    else
    {
        Elem<T>* it = new Elem<T>;
        it->data = data;
        it->next = NULL;
        it->prev = Tail;

        Tail->next = it;
        Tail = it;
        Size++;
    }
}

template<typename T>
void List<T>::pop_front()
{
    if (Head != NULL)
    {
        Elem<T>* it = Head;
        it->prev = NULL;
        Head->prev = NULL;
        Head = Head->next;
        delete it;
        --Size;
    }
}

template<typename T>
void List<T>::clear()
{
    while (Head != NULL)
    {
        pop_front();
    }
}

template<typename T>
const T& List<T>::operator [](const int k)
{
	int counter = 0;
	Elem<T>* Current = this->Head;			// Начинаем свой проход с головы списка

	while (Current != nullptr) {			// Пока это не конец списка
		if (counter == k) {				// Если мы попали в нужный элемент списка
			return Current->data;			// Возвращаем данные
		}
		Current = Current->next;			// Если не попали, то переходим к следующему
		++counter;							// Увеличиваем индекс на котором мы сейчас находимся на 1
	}
}

template<typename T>
int List<T>::getSize()
{
    return Size;
}

template<typename T>
void List<T>::pop_back()
{
	if (Size > 1) {
		Elem<T>* it1;
		Elem<T>* it2;
		for (it1 = Head, it2 = Head->next; it2->next != NULL;) {
			it1 = it2;
			it2 = it2->next;
		}
		Tail = it1;
		Tail = Tail->prev;
		delete it2;
		it1->next = NULL;
		--Size;
	}
}

template<typename T>
void List<T>::pop(const int index)
{
	Elem<T>* temp = new Elem<T>;
	temp = Head;
	int count = 0;
	if (Size >= index && index > 0)
	{
		while (temp != NULL)
		{
			if (index > 1 && index < Size)
			{
				if (count == index - 1)
				{
					Elem<T>* t = temp;

					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete t;
					break;
				}
				count++;
				temp = temp->next;
			}
		}
	}
	--Size;
	return;
}

template<typename T>
List<T>::~List()
{
	clear();
}

void lab_9_2() {
	srand(time(nullptr));
	int size = 10;
	string exampleSurname[10] = { {"Guliev"}, {"Artemev"}, {"Shemenkov"}, {"Pletuhin"}, {"Pertsev"}, {"Ivanov"}, {"Petrov"}, {"Fedorov"}, {"Ososov"}, {"Pivchik"} };
	int exampleGrade[4] = { {2}, {3}, {4}, {5} };
	List<info> listOfStudents;
	// Заполняем наш список
	for (int i = 0; i < size; ++i) {
		info buf; // Временная переменная для занесения данных в список
		buf.Surname = exampleSurname[i];
		cout << "\n" << buf.Surname << " ";
		for (int j = 0; j < 4; ++j) {
			buf.Grades[j] = exampleGrade[rand() % 4];
			cout << buf.Grades[j] << " ";
		}
		listOfStudents.push_back(buf);
	}

	int counter = 1;
	while (counter <= listOfStudents.getSize()) {
		info buf = listOfStudents[counter - 1];
		for (int i = 0; i < 4; ++i) {
			if (buf.Grades[i] == 2) {
				if (counter == 1) {
					listOfStudents.pop_front();
				}
				if (counter == listOfStudents.getSize()) {
					listOfStudents.pop_back();
				}
				if (counter > 1 && counter < listOfStudents.getSize()) {
					listOfStudents.pop(counter);
				}
				counter = 1;
				break;
			}
		}
		++counter;
	}
	info buf = listOfStudents[0];
	for (int z = 0; z < 4; ++z) {
		if (buf.Grades[z] == 2) {
			listOfStudents.pop_front();
		}
	}
	cout << "\n\nstudentov(pidarasov) BEZ DVOEK:";
	cout << "(Kol-vo = " << listOfStudents.getSize() << ")";
	for (int i = 0; i < listOfStudents.getSize(); ++i) {
		info buf1 = listOfStudents[i];
		cout << "\n" << buf1.Surname << " ";
		for (int j = 0; j < 4; ++j) {
			cout << buf1.Grades[j] << " ";
		}
	}
	return;
}

void lab_9() {
	cout << "\n\tEx. #1\n\n";
	lab_9_1();
	cout << "\n\tEx. #2\n\n";
	lab_9_2();
	return; 
}
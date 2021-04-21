#include "include.h"

struct info {
	string Surname;
	int Grades[4];
};

template <typename T>
class List_One_Link {

	public:

		List_One_Link();	// ����������� (��� �������� ������ ������ ����)
		~List_One_Link();	// ���������� (��� ���������� ������ ���������)

		void pop_front();		// ����� ��� �������� ������� �������� ������ (������)
		void push_back(T data); // ����� ��� ���������� �������� � ����� ������
		int GetSize();			// ����� ��� ��������� ������� ������
		void clear();			// ����� ��� ������� ������

		T& operator[](const int index); // ������ ��� ������ � ����������� �������� (��� �������� � �.�.)

	private:
	
		template <typename T> 
		class Node { // ��������� ����� Node(����), �.�. �� ���� 1 �� ��������� ������
		
		public:
			Node* pNext;	// ��������� �� ����� � ������ ���������� ������ �������� � ������
			T data;			// �����-�� ������, ������� �������� � ������ ����
			Node(T data = T(), Node* pNext = NULL) { // ����������� ������ Node
				// �������� �� ��������� ��� data - 
				// ��� ����� ������������ �� ��������� (� ������� ����. �������)
				// �������� �� ��������� ��� pNext - �� ����� ����
				this->data = data;		// ����������� �������� ���������
				this->pNext = pNext;	// ����������� �������� ���������
			}
		};
		int Size;		// ������ ������
		Node<T> *head;	// ��������� �� ������ ������
};

template <typename T>
List_One_Link<T>::List_One_Link() {
	Size = 0;		// �.�. �� ������ ������� ������, �� ������ � ���� ���� ����� ����
	head = nullptr; // �� ����� ����� ����� ��� �� ������ ������ ��� ������ ����
}

template <typename T>
List_One_Link<T>::~List_One_Link() { // ����������, ����� �� ���� ������ ������
	clear(); // ��� ���� ����� �������� ������, ����� ���������� ���� ���������
}

template<typename T>
void List_One_Link<T>::pop_front() {
	Node<T> *Temp = head;	// �������� ��������� �� ������ ������, ��� �������� ������ ������
	head = head->pNext;		// ������ ������ ������ - ��������� �������
	delete Temp;			// ������� ������ ������, ��� ������ ������ ������ ������
	--Size;					// ��������� ������ ������, �.�. �� ��� ������ �������
}

template<typename T>
void List_One_Link<T>::push_back(T data) {

	if (head == nullptr) {					// ���� � ������ ��� ��� ���������
		head = new Node<T>(data);			// ������� ����� ������� � ������
	}
	else {									// ���� � ������ ��� ���� ��������
		Node<T>* Current = this->head;		// ��������� ����������, �� ��������� ����� ������ ������ ������
		
		while (Current->pNext != nullptr) { // ���� Current != ����� ������ 
			Current = Current->pNext;		// ��������� � ���������� ��������
		}

		Current->pNext = new Node<T>(data); // ������� ����� ������� � ������

	}

	++Size;
}

template<typename T>
int List_One_Link<T>::GetSize() { // ������� ����������� ������� ������
	return Size;
}

template<typename T>
void List_One_Link<T>::clear() { // ������� ������� ������

	while (Size) { // ���� Size > 0
		pop_front();
	}

}

template<typename T>
T& List_One_Link<T>::operator[](const int index) { // ��� ������ � ���������
											// ��� ��� ��� ����� ����� ���������� � ������ ��� List[0] � �.�.
	int counter = 0; 
	Node<T>* Current = this->head;			// �������� ���� ������ � ������ ������

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
	// ��������� ��� ������
	for (int i = 0; i < size; ++i) {
		info buf; // ��������� ���������� ��� ��������� ������ � ������
		buf.Surname = exampleSurname[i];
		cout << "\n" << buf.Surname << " ";
		for (int j = 0; j < 4; ++j) {
			buf.Grades[j] = exampleGrade[rand() % 4];
			cout << buf.Grades[j] << " ";
		}
		listOfStudents.push_back(buf);
	}
	// �������� ��������� ������ ��� ���������� ������� ����� �����
	int* arr;
	arr = new int[size];
	cout << "\n\nIndex array before:\n";
	for (int i = 0; i < size; ++i) {
		arr[i] = i;
		cout << arr[i] << " ";
	}
	// ��������� ��� ������
	IndexSort(listOfStudents, arr, size);
	cout << "\n\nList after Sort:\n";
	// ����� ��������������� ������
	for (int i = 0; i < size; ++i) {
		info buf = listOfStudents[arr[i]];
		cout << "\n" << buf.Surname;
		for (int j = 0; j < 4; ++j) {
			buf.Grades[j] = exampleGrade[rand() % 4];
			cout << buf.Grades[j] << " ";
		}
	}
	// ��������� ������ �������
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
	class Elem { // ��������� ����� Node(����), �.�. �� ���� 1 �� ��������� ������

	public:
		Elem* next;	// ��������� �� ����� � ������ ���������� ������ �������� � ������
		Elem* prev;
		T data;			// �����-�� ������, ������� �������� � ������ ����
		Elem(T data = T(), Elem* next = NULL, Elem* prev = NULL) { // ����������� ������ Node
			// �������� �� ��������� ��� data - 
			// ��� ����� ������������ �� ��������� (� ������� ����. �������)
			// �������� �� ��������� ��� pNext - �� ����� ����
			this->data = data;		// ����������� �������� ���������
			this->next = next;	// ����������� �������� ���������
			this->prev = prev;
		}
	};
	int Size;		// ������ ������
	Elem<T>* Head;	// ��������� �� ������ ������
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
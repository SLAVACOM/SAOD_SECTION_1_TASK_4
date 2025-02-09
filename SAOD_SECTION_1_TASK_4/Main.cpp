#include <iostream>
#include <regex>
#include <Windows.h>

using namespace std;

int validIntegerInput(string message) {
	string input;
	regex valid("[1-9][0-9]*");
	do {
		cout << message;
		cin >> input;
	} while (!regex_match(input, valid));
	return stoi(input);
}


struct Stack {
	int data;
	Stack* next;
} *st, *st_second;

void initStack() {
	st = NULL;
	st_second = NULL;
}

bool isEmpty() { return st == NULL; }

bool isEmptySecond() { return st_second == NULL; }

void show_stack(Stack* steck) {
	if (steck != NULL) {
		Stack* p = steck;
		int count = 1;
		while (p != NULL) {
			cout << count++ << ":\t" <<p->data <<  endl;
			p = p->next;
		}
		cout << endl;
	}
	else cout << "Cтек пустой" << endl;
}

Stack* push(Stack* steck, int x) {
	Stack* p = new Stack;
	p->data = x;
	p->next = steck;
	steck = p;
	return steck;
}

void pushRandom() {
	int count = validIntegerInput("Введите количесво элментов: ");
	for (int i = 0; i < count; i++) st = push(st, rand() % 100);
}

void pop() {
	if (isEmpty()) cout << "Cтек пустой" << endl;
	else {
		Stack* p = st;
		st = st->next;
		delete p;
	}
}

void moveToSecondSteck() {
	if (isEmpty()) cout << "Cтек пустой" << endl;
	Stack* p = st;	
	st = st->next;
	p->next = st_second;
	st_second = p;
}

void moveFromSecondSteck() {
	if (isEmptySecond()) cout << "Cтек пустой" << endl;
	Stack* p = st_second;
	st_second = st_second->next;
	p->next = st;
	st = p;
}

void menu(bool &exit) {
	cout << "1. Добавить элементы в стек" << endl;
	cout << "2. Удалить элемент из стека" << endl;
	cout << "3. Переместить элемент из первого стека во второй" << endl;
	cout << "4. Переместить элемент из второго стека в первый" << endl;
	cout << "5. Показать стек" << endl;
	cout << "6. Показать второй стек" << endl;
	cout << "7. Выход" << endl;
	
	int choice = validIntegerInput("Выберите действие: ");
	switch (choice){
	case 1:
		pushRandom();
		break;
	case 2:
		pop();
		break;
	case 3:
		moveToSecondSteck();
		break;
	case 4:
		moveFromSecondSteck();
		break;
	case 5:
		show_stack(st);
		break;
	case 6:
		show_stack(st_second);
		break;
	case 7:
		exit = true;
		break;
	default:
		cout << "Неверный выбор" << endl;
	
	}
	
}

int main() {
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	initStack();
	srand(time(NULL));
	bool exit = false;
	while (!exit) {
		menu(exit);
	}
}
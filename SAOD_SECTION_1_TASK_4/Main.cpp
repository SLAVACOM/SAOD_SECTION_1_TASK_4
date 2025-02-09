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
	else cout << "C��� ������" << endl;
}

Stack* push(Stack* steck, int x) {
	Stack* p = new Stack;
	p->data = x;
	p->next = steck;
	steck = p;
	return steck;
}

void pushRandom() {
	int count = validIntegerInput("������� ��������� ��������: ");
	for (int i = 0; i < count; i++) st = push(st, rand() % 100);
}

void pop() {
	if (isEmpty()) cout << "C��� ������" << endl;
	else {
		Stack* p = st;
		st = st->next;
		delete p;
	}
}

void moveToSecondSteck() {
	if (isEmpty()) cout << "C��� ������" << endl;
	Stack* p = st;	
	st = st->next;
	p->next = st_second;
	st_second = p;
}

void moveFromSecondSteck() {
	if (isEmptySecond()) cout << "C��� ������" << endl;
	Stack* p = st_second;
	st_second = st_second->next;
	p->next = st;
	st = p;
}

void menu(bool &exit) {
	cout << "1. �������� �������� � ����" << endl;
	cout << "2. ������� ������� �� �����" << endl;
	cout << "3. ����������� ������� �� ������� ����� �� ������" << endl;
	cout << "4. ����������� ������� �� ������� ����� � ������" << endl;
	cout << "5. �������� ����" << endl;
	cout << "6. �������� ������ ����" << endl;
	cout << "7. �����" << endl;
	
	int choice = validIntegerInput("�������� ��������: ");
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
		cout << "�������� �����" << endl;
	
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
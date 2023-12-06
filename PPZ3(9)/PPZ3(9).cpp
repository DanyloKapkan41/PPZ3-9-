#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};

void add(Node*& head, int N, int j)
{
	if (N > j)
	{
		int n = rand() % 201 - 100;
		Node* cur = new Node(n);
		head->next = cur;
		j++;
		add(cur, N, j);
	}
}

void add(Node*& head, int o)
{
	Node* cur = new Node(o);
	cur->next = head;
	head = cur;
}

void show(Node* head)
{
	Node* current = head;
	while (current != nullptr) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

void deleteList(Node* head)
{
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void changing(Node*& head, int x)
{
	if (head == nullptr || head->next == nullptr) {
		return;
	}

	Node* lessThanX = new Node(0); // Допоміжний список для менших за x
	Node* greaterThanOrEqualX = new Node(0); // Допоміжний список для більших або рівних x
	Node* lessThanXCurrent = lessThanX;
	Node* greaterThanOrEqualXCurrent = greaterThanOrEqualX;

	Node* current = head;

	while (current != nullptr) {
		if (current->data < x) {
			lessThanXCurrent->next = current;
			lessThanXCurrent = lessThanXCurrent->next;
		}
		else {
			greaterThanOrEqualXCurrent->next = current;
			greaterThanOrEqualXCurrent = greaterThanOrEqualXCurrent->next;
		}
		current = current->next;
	}

	// З'єднати два списки
	lessThanXCurrent->next = greaterThanOrEqualX->next;
	greaterThanOrEqualXCurrent->next = nullptr;

	head = lessThanX->next;

	// Звільнення пам'яті
	delete lessThanX;
	delete greaterThanOrEqualX;
}

int main()
{
	int N = -1, x;
	Node* head = new Node(1);
	srand(time(NULL));

	do {
		cout << "Count of elements (0 <= N <= 200): ";
		cin >> N;
	} while (N > 201 || N < -1);

	add(head, N, 0);
	head = head->next;

	do {
		cout << "X: ";
		cin >> x;
	} while (N > 201 || N < -201);

	cout << "Original List: ";
	show(head);

	changing(head, x);

	cout << "Modified List: ";
	show(head);

	deleteList(head);
	return 0;
}


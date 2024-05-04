#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    char* key;
    Node* next;
    Node* prev;
};

// Функция для создания нового узла
Node* createNode(const char* key) {
    Node* newNode = new Node;
    newNode->key = new char[strlen(key) + 1];
    int i = 0;
    while (key[i] != '\0') {
        newNode->key[i] = key[i];
        i++;
    }
    newNode->key[i] = '\0'; // добавляем нулевой символ в конце строки

    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;
}

// Функция для добавления K элементов перед элементом с заданным номером
void insert_k(Node*& head, int position, int K) {
    Node* current = head;

    for (int i = 0; i < K; i++) {
        char key[50];
        cout << "Введите ключ нового элемента:" << endl;
        cin >> key;

        Node* newNode = createNode(key);

        if (position == 1) {
            newNode->next = current;
            current->prev = newNode;
            head = newNode;
        }
        else {
            for (int j = 1; j < position - 1; j++) {
                if (current == nullptr) {
                    cout << "Неверный номер позиции" << endl;
                    return;
                }
                current = current->next;
            }

            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            current = current->next;
        }
    }
}

// Функция для удаления элемента с заданным ключом
void deleteNode(Node*& head, const char* key) {
    Node* current = head;

    while (current != nullptr) {
        if (strcmp(current->key, key) == 0) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }

            delete[] current->key;
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        else {
            current = current->next;
        }
    }

    cout << "Элемент с ключом " << key << " удален" << endl;
}

// Функция для вывода элементов списка
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->key << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");
    Node* head = nullptr;

    int n;
    cout << "Введите количество элементов в списке: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        char key[50];
        cout << "Введите ключ элемента " << i + 1 << ":" << endl;
        cin >> key;

        Node* newNode = createNode(key);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    cout << "Исходный список:" << endl;
    printList(head);

    // Удаление элемента с заданным ключом
    char keyToDelete[50];
    cout << "Введите ключ элемента для удаления: ";
    cin >> keyToDelete;

    deleteNode(head, keyToDelete);

    cout << "Список после удаления элемента с ключом '" << keyToDelete << "':" << endl;
    printList(head);

    // Добавление K элементов перед элементом с заданным номером
    int position, K;
    cout << "Введите номер элемента, перед которым добавить элементы:" << endl;
    cin >> position;
    cout << "Сколько элементов добавить перед элементом:" << endl;
    cin >> K;

    insert_k(head, position, K);

    cout << "Список после добавления " << K << " элементов перед элементом с номером " << position << ":" << endl;
    printList(head);

    return 0;
}


#include <iostream>

using namespace std;

struct Node {
    char key;
    Node* next;

    Node(char k) : key(k), next(nullptr) {} // создание нового узла 
};

// Функция для вставки нового элемента после определенного ключа
void insertAfter(Node*& head, char prev_key, char new_key) {
    Node* new_node = new Node(new_key);
    if (head == nullptr) {
        head = new_node;
    }
    else {
        Node* current = head;
        while (current) {
            if (current->key == prev_key) {
                new_node->next = current->next;
                current->next = new_node;
                break;
            }
            current = current->next;
        }
    }
}

// Функция для удаления узла с определенным ключом
void deleteNode(Node*& head, char del_key) {
    if (head == nullptr) {
        return;
    }
    if (head->key == del_key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next) {
        if (current->next->key == del_key) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            break;
        }
        current = current->next;
    }
}

// Функция для печати связанного списка
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->key << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");
    Node* head = nullptr;

    char prev_key, new_key;
    int n;
    cout << "Введите количество элементов в списке: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введите ключ, после которого вставить новый элемент: ";
        cin >> prev_key;
        cout << "Введите новый элемент: ";
        cin >> new_key;
        insertAfter(head, prev_key, new_key);
    }

    cout << "Список: :" << endl;
    printList(head);

    char del_key;
    cout << "Введите ключ для удаления: ";
    cin >> del_key;
    deleteNode(head, del_key);
    cout << "Список после удаления элемента '" << del_key << "':" << endl;
    printList(head);

    int k;
    cout<< "Введите количество элементов на добавление: ";
    cin >> k;

    char prev_key_new, new_key_new;
    for (int i = 0; i < k; i++) {
        cout << "Введите ключ, после которого вставить еще один элемент: ";
        cin >> prev_key_new;
        cout << "Введите новый ключ: ";
        cin >> new_key_new;
        insertAfter(head, prev_key_new, new_key_new);
    }

    cout << "Получившийся список: " << endl;
    printList(head);

    return 0;
}

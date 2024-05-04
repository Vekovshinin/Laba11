#include <iostream>

using namespace std;

// объявление структуры
template <typename T>
struct Node {
    T data; // данные
    Node<T>* next; // указатель на следующий элемент
};

template <typename T>
struct Queue {
    int size; // размер
    Node<T>* head; // указатель на голову
    Node<T>* tail;// указатель на хвост
};

// функция инициализация очереди
template <typename T>
void init_queue(Queue<T>& q, const T& val) {
    Node<T>* new_node = new Node<T>();
    new_node->data = val;
    q.head = new_node;
    q.tail = new_node;
    q.size = 1;
}

// функция добавления элемента в очередь
template <typename T>
void push(Queue<T>& q, const T& val) {
    Node<T>* new_node = new Node<T>();
    q.size++;
    new_node->data = val;
    new_node->next = nullptr;
    q.tail->next = new_node;
    q.tail = new_node;
}

//функция создания очереди
template <typename T>
void new_queue(Queue<T>& q, int n) {
    T a;
    cout << "Введите элемент: ";
    cin >> a;
    init_queue(q, a);
    for (int i = 1; i < n; i++) {
        cout << "Введите элемент: ";
        cin >> a;
        push(q, a);
    }
}

// функция вывода очереди 
template <typename T>
void print_queue(Queue<T>& q) {
    Node <T>* tmp = q.head;
    cout << "начало ->";
    while (tmp != nullptr) {
        cout << tmp->data << "->";
        tmp = tmp->next;

    }
    cout << "конец" << endl;

}

// функция удаления элементов
template <typename T>
void pop(Queue<T>& q) {
    Node<T>* tmp = q.head;
    q.head = q.head->next;
    q.size--;
    delete(tmp);
}

//функция на удаление элеменов с заданным ключом
template <typename T>
void delete_k(Queue<T>& q, T k) {
    int i = 1;
    while (i <= q.size) {
        if (q.head->data == k) {
            pop(q);
        }
        else {
            push(q, q.head->data);
            pop(q);
            i++;
        }
    }
}

// функция на добавления элементов 
template <typename T>
void insert(Queue<T>& q, int count, int num) {
    int i = 1;
    while (i < num) {
        push(q, q.head->data);
        pop(q);
        i++;
    }
    T a;
    for (int j = 0; j < count; j++) {
        cout << "Введите элемент для добавления";
        cin >> a;
        push(q, a);
    }
    for (i; i < q.size - count; i++) {
        push(q, q.head->data);
        pop(q);
    }
}

// функция очищения динамической памяти
template <typename T>
void delete_queue(Queue<T>& q) {
    while (q.head->next != nullptr) {
        pop(q);
    }
    Node<T>* tmp = q.head;
    q.head = nullptr;
    q.size--;
    delete tmp;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    Queue<char> q;
    int n;
    cout << "Введите количество элементов в очереди: ";
    cin >> n;
    new_queue(q, n);
    cout << endl;
    print_queue(q);

    char k;
    cout << "Введите ключ элемента, который необходимо удалить: ";
    cin >> k;
    delete_k(q, k);
    cout << endl;
    print_queue(q);

    int num, count;
    cout << "Введите номер элемента перед которым нужно встатить элементы: ";
    cin >> num;

    cout << "Введите количество элементов, которых нужно вставить: ";
    cin >> count;
    insert(q, count, num);
    cout << endl;
    print_queue(q);
    cout << endl << "Очищение динамической памяти: ";
    delete_queue(q);
    print_queue(q);
    return 0;
}

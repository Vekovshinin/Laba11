#include <iostream>
#include <queue>

using namespace std;

// функция инициализация очереди
void new_queue(queue<char>& q, const int& n) {
    char a;
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент: ";
        cin >> a;
        q.emplace(a); // вводим элемент и вставляем в конец очереди
    }
}

// фукция вывода очереди 
void print_queue(queue<char>& q) {
    cout << "начало ->";
    for (int i = 0; i < q.size(); i++) {
        cout << q.front() << "->"; // выводим первый элемент
        q.emplace(q.front()); // перемещаем первый элемент в конец
        q.pop(); // удаляем элемент
    }
    cout << "конец" << endl;
}

//функция удаления элементов из очереди
void delete_k(queue<char>& q, const int& k) {
    int i = 1;
    while (i <= q.size()) {
        if (q.front() == k) { // проверяем если верхний элемент в очереди равен нужному
            q.pop(); // если да, то удаляем его(счетчик увеличивать не надо, так как при удалении элемента очередь уже уменьшилась
        }
        else {
            q.emplace(q.front()); // иначе добавляем его в конец очереди
            q.pop(); // удаляем его из начала, так как он уже в конце
            i++; // увеличиваем счетчик на один 
        }
    }
}

//функция добавления элементов в очередь
void insert(queue<char>& q, const int& count, const int& num) {
    int i = 1;
    while (i <= num) {
        q.emplace(q.front()); // переставляем элементы с головы в хвост очереди, пока не дойдем до нужного элемента 
        q.pop(); // удаляем элемент в начале
        i++;
    }
    char a;
    for (int j = 0; j < count; j++) { // добавляем нужное количество элементов в начало очереди
        cout << "Введите элемент для добавления: ";
        cin >> a;
        q.emplace(a);
    }
    for (i; i <= q.size() - count; i++) { // переставляем элементы из начала очереди в конец, чтобы она снова стала такой же
        q.emplace(q.front());
        q.pop();
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    queue<char> q; // объявление очереди
    int n;
    cout << "Введите количество элементов в очереди: ";
    cin >> n;
    new_queue(q, n); // инициализация очереди
    cout << endl;
    print_queue(q);// вывод очереди на экран
    cout << endl;
    char k;
    cout << "Введите ключ элемента, который необходимо удалить: ";
    cin >> k;
    delete_k(q, k); // удаление 
    cout << endl;
    print_queue(q);

    int num, count;
    cout << "Введите номер элемента после которого надо вставить: ";
    cin >> num;
    cout << "Введите количество элементов для добавления: ";
    cin >> count;
    insert(q, count, num); // вставка
    cout << endl;
    print_queue(q);
    return 0;
}

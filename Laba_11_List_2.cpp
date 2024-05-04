#include <iostream>
#include <list>

using namespace std;

// функция инициализации списка
void new_list(list<char>& lst, const int& n) {
    char a;
    cout << "Введите элементы списка: ";
    for (int i = 0; i < n; i++) {
        cin >> a;
        lst.push_front(a);
    }
}

// функция для вывода списка без удаления элементов
void print_list(const list<char>& lst) {
    list<char> tmp_lst = lst; // создаем копию списка
    cout << "Список: ";
    while (!tmp_lst.empty()) {
        cout << tmp_lst.front() << ' ';
        tmp_lst.pop_front();
    }
    cout << endl;
}

// функция для удаления элементов из списка
void delete_k(list<char>& lst, const char& k) {
    int i = 1;
    int p = lst.size();
    while (i <= p) {
        if (lst.front() == k) {
            lst.pop_front();
        }
        else {
            lst.push_back(lst.front());
            lst.pop_front();
        }
    }
}

// Функция для добавления К элементов перед элементом с заданным номером
void insert_k(list<char>& lst, list<char>& lst2, const int& count, const int& num) {
    int i = 1;
    while (i < num) {
        lst2.push_back(lst.front());
        lst.pop_front();
        i++;
    }
    char a;
    for (int j = 0; j < count; j++) {
        cout << "Введите элемент для добавления: ";
        cin >> a;
        lst.push_front(a);
    }
    while (!lst2.empty()) {
        lst.push_front(lst2.back());
        lst2.pop_back();
    }
}

int main() {
    setlocale(LC_ALL, "Ru");
    list<char> lst;
    int n;
    cout << "Введите количество элементов в списке: ";
    cin >> n;
    new_list(lst, n); // инициализация очереди
    cout << endl;
    print_list(lst);// вывод очереди на экран
    cout << endl;
    char k;
    cout << "Введите ключ элемента, который необходимо удалить: ";
    cin >> k;
    delete_k(lst, k); // удаление 
    cout << endl;
    print_list(lst);

    int num, count;
    cout << "Введите номер элемента перед которым надо вставить: ";
    cin >> num;
    cout << "Введите количество элементов для добавления: ";
    cin >> count;
    list<char> lst2;
    insert_k(lst, lst2, count, num);
    cout << endl;
    print_list(lst);

    return 0;
}

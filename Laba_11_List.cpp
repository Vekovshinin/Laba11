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
    for (char elem : tmp_lst) {
        cout << elem << ' ';
    }
    cout << endl;
}

// функция для удаления элементов из списка
void delete_k(list<char>& lst, const char& k) {
    list<char> tmp_lst;
    while (!lst.empty()) {
        if (lst.front() == k) {
            lst.pop_front();
        }
        else {
            tmp_lst.push_back(lst.front());
            lst.pop_front();
        }
    }
    lst = tmp_lst;
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
        lst2.push_back(a);
    }
    while (!lst.empty()) {
        lst2.push_back(lst.front());
        lst.pop_front();
    }
    lst = lst2;
}

int main() {
    setlocale(LC_ALL, "Ru");
    list<char> lst;
    int n;
    cout << "Введите количество элементов в списке: ";
    cin >> n;
    new_list(lst, n); // инициализация списка
    cout << endl;
    print_list(lst); // вывод списка на экран
    cout << endl;

    char k;
    cout << "Введите ключ элемента, который необходимо удалить: ";
    cin >> k;
    delete_k(lst, k); // удаление элементов
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

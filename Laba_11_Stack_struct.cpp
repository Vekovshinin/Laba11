#include <iostream>

using namespace std;
char a;
// структура
struct Stack {
    char data; // данные
    Stack* prev; // указатель
};

//функция создания стека
Stack* make_stack(int n) {
    if (n == 0) {
        return NULL;
    }
    else {
        Stack* top, * p;
        top = NULL;
        p = new Stack;
        cin >> a;
        p->data = a;
        p->prev = NULL;
        top = p;
        for (int i = 1; i < n; i++) {
            Stack* h = new Stack;
            cin >> a;
            h->data = a;
            h->prev = top;
            top = h;
        }
        return top;
    }
}

//функция вывода стека
void print_stack(Stack* top) {
    if (top == 0) {
        cout << "Стек пуст" << endl;
    }
    else {
        Stack* p = top;
        while (p != NULL) {
            cout << p->data << ' ';
            p = p->prev;
        }
        cout << endl;
    }
}

//функция удаления элемента
char pop(Stack*& top) {
    Stack* p = top;
    int k = 0;
    while (p != NULL) {
        k++;
        p = p->prev;
    }
    p = top;
    if (k == 1) {
        char t = top->data;
        delete p;
        top = NULL;
        return t;
    }
    else {
        Stack* t = p->prev;
        char u = p->data;
        top = t;
        delete p;
        return u;
    }
}

// функция добавления элемента в стек
Stack* push(Stack*& top, char val) {
    Stack* p = new Stack;// выделение памяти для нового элемента 
    p->data = val; // присваивание нового элемента
    p->prev = top;// новый элемент указывает на следующий(нижний) элемент
    top = p; // новый элемент стает первым элементов стека
    return top;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int n;
    cout << "Введите количество элементов стека: ";
    cin >> n;
    cout << "Введите элементы стека: ";
    Stack* st = make_stack(n); //создание стека
    cout << "Стек: ";
    print_stack(st); //печать стека
    char b;
    cout << "Введите ключ для удаления элемента из стека: ";
    cin >> b;
    int k;
    k = 0;
    Stack* st2 = make_stack(0); //создаем пустой стек st2
    //перенос всех элементов стека st в стек st2
    for (int i = 0; i < n; i++) {
        char t = pop(st);
        if (t != b) {
            push(st2, t);
        }
        else { k++; }
    }
    n = n - k;
    for (int i = 0; i < n; i++) {
        char t = pop(st2);
        push(st, t);
    }
    cout << "Стек после удаления: ";
    print_stack(st);
    k = 0;
    cout << "Введите количество элементов на добавление: ";
    cin >> k;
    int num;
    cout << "Введите номер элемента, перед которым нужно вставить: ";
    cin >> num;
    //перенос всех элементов стека до элемента num включительно
    for (int i = 0; i < n - num + 1; i++) {
        char t = pop(st);
        push(st2, t);
    }
    //добавление новых элементов в стек
    cout << "Введите элементы: ";
    for (int i = 0; i < k; i++) {
        cin >> a;
        push(st, a);
    }
    //перенос всех элементов второго стека в начальный стек
    for (int i = 0; i < n - num + 1; i++) {
        char t = pop(st2);
        push(st, t);
    }
    print_stack(st);
}

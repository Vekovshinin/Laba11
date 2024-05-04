#include <iostream>
#include <stack>

using namespace std;
char a, b;

// функция для вывода стека
void print(stack<char> st) {
    int n = st.size();
    if (n == 0) {
        cout << "Стек пуст";
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << st.top() << ' '; // вывод верхнего элемента стека
            st.pop(); // удаление элемента вершины стека
        }
    }
    cout << endl;
}
int main()
{
    setlocale(LC_ALL, "Ru");
    stack <char> st;
    int n;
    cout << "Введите количество элементов стека: ";
    cin >> n;
    cout << "Введите элементы стека: ";
    for (int i = 0; i < n; i++) {
        cin >> a;
        st.push(a);
    }
    cout << "Стек: ";
    print(st);
    // задача удалить элементы из стека по заданному ключу

    stack <char> st2;

    cout << "Введите ключ для удаления: ";
    cin >> b;

    for (int i = 0; i < n; i++) {
        if (st.top() != b) {
            st2.push(st.top()); // заносим во второй стек нужные элементы, но они будут в противоположном порядке, поэтому надо еще раз перенести
        }
        st.pop();
    }
    // задача: перенести из второго стека в начальный с удалением 
    n = st2.size();
    for (int i = 0; i < n; i++) {
        st.push(st2.top());
        st2.pop();
    }
    cout << "Стек после удаления: ";
    print(st);
    int k = 0; // количество элементов на добавление
    int num = 0; // номер с которого надо добавлять
    cout << "Введите количество элементов на добавление: ";
    cin >> k;
    cout << "Введите номер с которого надо добавлять: ";
    cin >> num;
    // переносим элементы из первого стека во второй до num включительно
    for (int i = 0; i < n - num + 1; i++) {
        st2.push(st.top());
        st.pop();
    }
    cout << "Введите элементы: ";
    // вносим в первый стек нужное количество новых символов
    for (int i = 0; i < k; i++) {
        cin >> a;
        st.push(a);
    }
    // переносим элементы из второго стека обратно в первый
    for (int i = 0; i < n - num + 1; i++) {
        st.push(st2.top());
        st2.pop();
    }
    print(st);
    return 0;
}

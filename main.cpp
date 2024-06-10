#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>
#include <numeric>
#include <queue>

void ejemplo_stack() {
    std::stack<int> s1; // Es un adaptador de un deque
    s1.push(1);
    s1.push(3);
    s1.push(5);
    std::cout << s1.top() << std::endl;
    s1.top() = 7; // Reemplazar el valor del top (valor =5) por el valor = 7
    std::cout << s1.top() << std::endl;
    std::cout << "size: " << s1.size() << std::endl;
    s1.pop();
    std::cout << "size: " << s1.size() << std::endl;
    std::cout << s1.top() << std::endl;
    s1.pop();
    std::cout << "size: " << s1.size() << std::endl;
    std::cout << s1.top() << std::endl;
    s1.pop();
    std::cout << "size: " << s1.size() << std::endl;
    if (!s1.empty()) {
        std::cout << s1.top() << std::endl;
        s1.pop();
    }
}

void ejemplo_stack_2() {
    std::vector<int> v1 = {1, 2, 3, 5, 6, 7, 8};
    std::stack<int, std::vector<int>> s1(v1);
    std::deque<int> d1 = {1, 2, 3, 5, 6, 7, 8};
    std::stack<int> s2(d1);
    std::stack<int> s3;
    for (const auto& item: v1)
        s3.push(item);

    while (!s3.empty()) {
        std::cout << s3.top() << " ";
        s3.pop();
    }
}

template <typename T, typename Container=std::deque<T>>
class Pila {
    Container cnt;
public:
    Pila() = default;
    explicit Pila(Container cnt): cnt(std::move(cnt)) {}
    template <typename Iterator>
    Pila(Iterator start, Iterator stop) {
        std::copy(start, stop, std::back_inserter(cnt));
    }
    void push(T value) { cnt.push_back(value); }
    template <typename ... Params>
    void emplace(Params... params) { cnt.emplace_back(params...); }
    void pop() { cnt.pop_back(); }
    T& top() { return cnt.back(); }
    size_t size() { return cnt.size(); }
    bool empty() { return cnt.size() == 0; }
    void swap(Pila other) { std::swap(this->cnt, other.cnt); }
};

void ejemplo_stack_3() {
    std::vector<int> v1 = {1, 2, 3, 5, 6, 7, 8};
    Pila<int, std::vector<int>> s1(v1);
    std::deque<int> d1 = {1, 2, 3, 5, 6, 7, 8};
    Pila<int> s2(d1);
    Pila<int> s3(v1.begin(), v1.end());
    // for (const auto& item: v1)
    //     s3.push(item);

    while (!s3.empty()) {
        std::cout << s3.top() << " ";
        s3.pop();
    }
}

void ejemplo_queue() {
    std::queue<int> q1;
    q1.push(1);
    q1.push(3);
    q1.push(5);
    q1.push(6);
    while (!q1.empty()) {
        std::cout << q1.front() << " ";
        q1.pop();
    }
    std::cout << std::endl;
    std::deque<int> d1 = {10, 20, 30, 40, 50, 60};
    std::queue<int> q2(d1);
    while (!q2.empty()) {
        std::cout << q2.front() << " ";
        q2.pop();
    }
}

template <typename T, template <typename...> class ContainerType = std::deque>
class Cola {
    ContainerType<T> cnt;
public:
    Cola() = default;
    explicit Cola(ContainerType<T> cnt): cnt(std::move(cnt)) {}
    template <typename Iterator>
    Cola(Iterator start, Iterator stop) {
        std::copy(start, stop, std::back_inserter(cnt));
    }
    void push(T value) { cnt.push_back(value); }
    template <typename ... Params>
    void emplace(Params... params) { cnt.emplace_back(params...); }
    void pop() { cnt.pop_front(); }
    T& front() { return cnt.front(); }
    T& back() { return cnt.back(); }
    size_t size() { return cnt.size(); }
    bool empty() { return cnt.size() == 0; }
    void swap (Cola other) { std::swap(this->cnt, other.cnt); }
};

template <typename Cola>
void imprimir_cola(Cola q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

void ejemplo_queue_2() {
    Cola<int> q1;
    q1.push(1);
    q1.push(3);
    q1.push(5);
    q1.push(6);
    imprimir_cola(q1);
    std::deque<int> d1 = {10, 20, 30, 40, 50, 60};
    Cola<int> q2(d1);
    imprimir_cola(q2);
    std::list<int> l1 = {100, 200, 300, 400, 500};
    Cola<int, std::list> q3(l1);
    imprimir_cola(q2);

}

int main() {
    // ejemplo_stack();
    // ejemplo_stack_2();
    // ejemplo_stack_3();
    // ejemplo_queue();
    ejemplo_queue_2();

    return 0;
}

#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Priority {
public:
    Priority(size_t capacity = 10, size_t grow = 5);
    bool isEmpty() const;
    bool isFull() const;
    void InsertWithPriority(const T& value, int priority);
    void PullHighestPriorityElement();
    T Peek() const;
    void Show() const;
    ~Priority();

private:
    struct QueueElement {
        T value;
        int priority;

        QueueElement() : value(T()), priority(0) {}
        QueueElement(const T& value, int priority) : value(value), priority(priority) {}
    };

    QueueElement* queue;
    size_t capacity;
    size_t grow;
    size_t size;

    void reserve();
};

template<typename T>
Priority<T>::Priority(size_t capacity, size_t grow)
    : capacity(capacity), grow(grow), size(0) {
    queue = new QueueElement[capacity];
}

template<typename T>
bool Priority<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
bool Priority<T>::isFull() const {
    return size >= capacity;
}

template<typename T>
void Priority<T>::InsertWithPriority(const T& value, int priority) {
    if (isFull()) {
        reserve();
    }

    int i;
    for (i = size - 1; i >= 0 && queue[i].priority < priority; --i) {
        queue[i + 1] = queue[i];
    }
    queue[i + 1] = QueueElement(value, priority);
    ++size;

    cout << "Додано елемент " << value << " з пріоритетом " << priority << endl;
}

template<typename T>
void Priority<T>::PullHighestPriorityElement() {
    if (!isEmpty()) {
        for (size_t i = 1; i < size; ++i) {
            queue[i - 1] = queue[i];
        }
        --size;
        cout << "Елемент з найвищим пріоритетом видалено." << endl;
    }
    else {
        cout << "Черга пуста. Немає елементів для видалення." << endl;
    }
}

template<typename T>
T Priority<T>::Peek() const {
    if (!isEmpty()) {
        return queue[0].value;
    }
    cout << "Черга пуста. Немає елементів для перегляду." << endl;
    return T();
}

template<typename T>
void Priority<T>::Show() const {
    if (isEmpty()) {
        cout << "Черга пуста." << endl;
        return;
    }
    cout << "Елементи в черзі (значення->пріоритет): ";
    for (size_t i = 0; i < size; ++i) {
        cout << queue[i].value << ":" << queue[i].priority << " ";
    }
    cout << endl;
}

template<typename T>
Priority<T>::~Priority() {
    delete[] queue;
}

template<typename T>
void Priority<T>::reserve() {
    capacity += grow;
    QueueElement* newQueue = new QueueElement[capacity];

    for (size_t i = 0; i < size; ++i) {
        newQueue[i] = queue[i];
    }
    delete[] queue;
    queue = newQueue;
}

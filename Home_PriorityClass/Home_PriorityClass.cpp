#include <iostream>
#include "Priority.h"
#include <Windows.h>

using namespace std;

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

  
    Priority<int> priorityQueue(5, 3);

    if (priorityQueue.isEmpty()) {
        cout << "Черга пуста." << endl;
    }

    priorityQueue.InsertWithPriority(10, 2);
    priorityQueue.InsertWithPriority(20, 5);
    priorityQueue.InsertWithPriority(30, 3);
    priorityQueue.InsertWithPriority(40, 4);
    priorityQueue.InsertWithPriority(50, 1);

    cout << "=============== Елементи черги після вставки: ===============" << endl;
    priorityQueue.Show();

    cout << "Найвищий пріоритет у черзі: " << priorityQueue.Peek() << endl;

    priorityQueue.PullHighestPriorityElement();
    cout << "========== Елементи черги після видалення елемента з найвищим пріоритетом: ==========" << endl;
    priorityQueue.Show();
    cout << "============= Перевірка чи черга заповнена: =============" << endl;
    if (priorityQueue.isFull()) {
        cout << "Черга заповнена." << endl;
    }
    else {
        cout << "Черга ще не заповнена." << endl;
    }

    priorityQueue.InsertWithPriority(60, 6);

    cout << "================= Елементи черги після додавання нового елемента з пріоритетом 6: =============" << endl;
    priorityQueue.Show();

    
}

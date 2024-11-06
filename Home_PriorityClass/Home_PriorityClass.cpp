#include <iostream>
#include "Priority.h"
#include <Windows.h>

using namespace std;

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

  
    Priority<int> priorityQueue(5, 3);

    if (priorityQueue.isEmpty()) {
        cout << "����� �����." << endl;
    }

    priorityQueue.InsertWithPriority(10, 2);
    priorityQueue.InsertWithPriority(20, 5);
    priorityQueue.InsertWithPriority(30, 3);
    priorityQueue.InsertWithPriority(40, 4);
    priorityQueue.InsertWithPriority(50, 1);

    cout << "=============== �������� ����� ���� �������: ===============" << endl;
    priorityQueue.Show();

    cout << "�������� �������� � ����: " << priorityQueue.Peek() << endl;

    priorityQueue.PullHighestPriorityElement();
    cout << "========== �������� ����� ���� ��������� �������� � �������� ����������: ==========" << endl;
    priorityQueue.Show();
    cout << "============= �������� �� ����� ���������: =============" << endl;
    if (priorityQueue.isFull()) {
        cout << "����� ���������." << endl;
    }
    else {
        cout << "����� �� �� ���������." << endl;
    }

    priorityQueue.InsertWithPriority(60, 6);

    cout << "================= �������� ����� ���� ��������� ������ �������� � ���������� 6: =============" << endl;
    priorityQueue.Show();

    
}

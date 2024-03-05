/*
��������� ������ � ���.
���������� ���� �������� ����������� �����. ������� �� ����
��������, ������� ������ ������� �����. ����������� �� � �������
����������. � �������� ��������������� ��������� ������ ����� � �����
������������ ������ ���. ���������� �����������, ��������� ������
����������� �������� ������ � �����.
*/
#include <iostream>
#include <random>
#include "deque.h"
#include "list_deque.h"
#include "menu.h"
#include "simple_vector_deque.h"
#include "vector_deque.h"

// �������� ��������� ����� [l; r]
int getRandom(int l, int r) {
    static std::mt19937 gen(0);
    return std::uniform_int_distribution<int>(l, r)(gen);
}

enum IMPLEMENTATION { SIMPLE_VECTOR, VECTOR, LIST };

Deque *newDeque(IMPLEMENTATION impl) {
    switch (impl) {
        case SIMPLE_VECTOR:
            return new SimpleVectorDeque();
        case VECTOR:
            return new VectorDeque(1000);
        case LIST:
            return new ListDeque();
        default:
            return nullptr;
    }
}

bool isPrime(int x) {
    if (x <= 1) {
        return false;
    }
    int d;
    for (d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    // �������� ������ ��� ����, ����� char ��� ������� ���������
    const char *loc = std::setlocale(LC_ALL, "Russian");
    if (loc == nullptr) {
        std::cout << "Error while setting locale\n";
        return 0;
    }
    std::cout << "New locale: " << loc << '\n';
    // ������ ��������� � ���������, ����� ��������� ��������� ������������
    system("chcp 1251");

    IMPLEMENTATION impl = VECTOR;
    {
        Menu menu(
            [&]() {
            std::cout << "����� ������������� ������������?\n\n";
        },
            true, false);
        menu.items.push_back({"�� ������� (����������� ����������)", [&impl]() {
            impl = SIMPLE_VECTOR;
        }});

        menu.items.push_back({"�� ������� (����������� ����������)", [&impl]() {
            impl = VECTOR;
        }});

        menu.items.push_back({"�� ������", [&impl]() {
            impl = LIST;
        }});

        menu.start();
    }

    Deque *deque = newDeque(impl);

    Menu mainMenu([]() {
        std::cout << "\t������� ����\n\n";
    });

    mainMenu.items.push_back({"��������� ���������� �������", [&deque]() {
        int n = Menu::getInt(0, 100, "���������� ����������");
        for (int i = 0; i < n && !deque->isFull(); ++i) {
            int x = getRandom(1, 500);
            deque->push_back(x);
        }
    }});

    mainMenu.items.push_back({"������� ���", [&]() {
        Deque *copy = newDeque(impl);

        while (!deque->isEmpty()) {
            int x = deque->front();
            deque->pop_front();
            copy->push_back(x);
            std::cout << x << ' ';
        }
        std::cout << '\n';

        std::swap(copy, deque);
        delete copy;

        Menu::awaitExit();
    }});

    mainMenu.items.push_back({"�������� ������ ������� � �������������", [&]() {
        Deque *sorted = newDeque(impl);
        while (!deque->isEmpty()) {
            int x = deque->back();
            deque->pop_back();

            if (!isPrime(x)) {
                continue;
            }

            // ����� �������� x � other
            // ��� ����� ������ �������-�� �������, ������� x, ������ �������
            // �������.
            // ����� ������� � ������� 1 ��� �� �������
            Deque *upper = newDeque(impl);
            while (!sorted->isEmpty() && sorted->back() > x) {
                int y = sorted->back();
                sorted->pop_back();
                upper->push_front(y);
            }

            sorted->push_back(x);

            // ������ ������� �������� �� �����
            while (!upper->isEmpty()) {
                int y = upper->front();
                upper->pop_front();
                sorted->push_back(y);
            }

            upper->isEmpty();
            sorted->isEmpty();
            deque->isEmpty();

            delete upper;
        }

        std::swap(sorted, deque);
        delete sorted;
    }});

    mainMenu.start();

    return 0;
}

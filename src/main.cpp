/*
—труктура данных Ц дек.
Ёлементами дека €вл€ютс€ натуральные числа. ”далите из дека
элементы, оставив только простые числа. –асположите их в пор€дке
неубывани€. ¬ качестве вспомогательной структуры данных можно и нужно
использовать второй дек. —ортировку производить, использу€ только
стандартные операции работы с деком.
*/
#include <iostream>
#include <random>
#include "deque.h"
#include "list_deque.h"
#include "menu.h"
#include "simple_vector_deque.h"
#include "vector_deque.h"

// получить случайное число [l; r]
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
    // измен€ем локаль дл€ того, чтобы char мог хранить кириллицу
    const char *loc = std::setlocale(LC_ALL, "Russian");
    if (loc == nullptr) {
        std::cout << "Error while setting locale\n";
        return 0;
    }
    std::cout << "New locale: " << loc << '\n';
    // мен€ем кодировку в терминале, чтобы кириллица корректно отображалась
    system("chcp 1251");

    IMPLEMENTATION impl = VECTOR;
    {
        Menu menu(
            [&]() {
            std::cout << " акую имплементацию использовать?\n\n";
        },
            true, false);
        menu.items.push_back({"Ќа векторе (тривиальна€ реализаци€)", [&impl]() {
            impl = SIMPLE_VECTOR;
        }});

        menu.items.push_back({"Ќа векторе (циклическа€ реализаци€)", [&impl]() {
            impl = VECTOR;
        }});

        menu.items.push_back({"Ќа списке", [&impl]() {
            impl = LIST;
        }});

        menu.start();
    }

    Deque *deque = newDeque(impl);

    Menu mainMenu([]() {
        std::cout << "\t√лавное меню\n\n";
    });

    mainMenu.items.push_back({"«аполнить случайными числами", [&deque]() {
        int n = Menu::getInt(0, 100, "количество добавлений");
        for (int i = 0; i < n && !deque->isFull(); ++i) {
            int x = getRandom(1, 500);
            deque->push_back(x);
        }
    }});

    mainMenu.items.push_back({"¬ывести дек", [&]() {
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

    mainMenu.items.push_back({"ќставить только простые и отсортировать", [&]() {
        Deque *sorted = newDeque(impl);
        while (!deque->isEmpty()) {
            int x = deque->back();
            deque->pop_back();

            if (!isPrime(x)) {
                continue;
            }

            // нужно вставить x в other
            // дл€ этого уберем сколько-то верхних, положим x, вернем верхние
            // обратно.
            // ћожно создать и удалить 1 раз за функцию
            Deque *upper = newDeque(impl);
            while (!sorted->isEmpty() && sorted->back() > x) {
                int y = sorted->back();
                sorted->pop_back();
                upper->push_front(y);
            }

            sorted->push_back(x);

            // кладем большие элементы на место
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

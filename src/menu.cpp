#include "menu.h"
#include <iomanip>
#include <iostream>
#include <string>

Menu::Menu(std::function<void()> beforeStart, bool clr, bool withExit)
    : beforeStart{beforeStart}, clr{clr}, withExit{withExit} {
}

void Menu::clearScreen() const {
    if (clr)
        system("cls");
}

int Menu::getInt(int l, int r, const std::string &str) {
    // пытаемся ввести число от l до r
    int res;
    while (true) {
        std::string line = Menu::getString(str);
        try {
            res = std::stoi(line);
        } catch (...) {
            std::cout << "Попробуйте еще раз.\n";
            continue;
        }
        if (res < l || res > r) {
            std::cout << "Нужно число [" << l << "; " << r << "]\n";
            continue;
        }
        return res;
    }
}

void Menu::awaitExit() {
    Menu menu(
        []() {
    },
        false);
    menu.start();
}

void Menu::start() const {
    while (true) {
        clearScreen();
        beforeStart();
        std::cout << "Выберите действие:\n";
        for (int i = 0; i < items.size(); ++i) {
            const MenuItem &item = items[i];
            std::cout << std::setw(2) << (i + 1) << ". " << item.name << '\n';
        }
        if (withExit)
            std::cout << " 0. Выход\n\n";
        int res = getInt((withExit ? 0 : 1), items.size());
        if (res == 0) {
            return;
        }
        res--;
        clearScreen();
        std::cout << "\t" << items[res].name << "\n\n";
        items[res].action();
        if (!withExit) {
            return;
        }
    }
}

std::string Menu::getString(const std::string &str) {
    if (!str.empty())
        std::cout << "Введите " << str << '\n';
    std::cout << "> ";
    std::string line;
    std::getline(std::cin, line);
    while (line.empty())
        std::getline(std::cin, line);
    return line;
}

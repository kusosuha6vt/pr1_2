#ifndef MENU_H
#define MENU_H

#include <functional>
#include <string>
#include <vector>

// Пункт меню
struct MenuItem {
    std::string name;  // имя пункта
    std::function<void()>
        action;  // функция, вызывающаяся при выборе пункта меню
};

// Меню
struct Menu {
    Menu(std::function<void()> beforeStart,  // функция, выполняющаяся до начала
         bool clr = true,  // нужно ли очищать экран
         bool withExit = true);  // нужно ли добавлять пункт "выход"

    // очистка экрана
    void clearScreen() const;

    // ввод числа от l до r. str - подсказка
    static int getInt(int l, int r, const std::string &str = "");

    // ввод строки. str - подсказка
    static std::string getString(const std::string &str = "");

    // вывод меню из единственного пункта - выход
    static void awaitExit();

    // запустить меню
    void start() const;

    std::vector<MenuItem> items;
    std::function<void()> beforeStart;
    bool clr, withExit;
};

#endif

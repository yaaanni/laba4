#include <iostream>
#include <limits>
#include <cstdlib> // для rand()

int menu() {
    std::cout << "Выберите интересующий пункт меню: \n";
    std::cout << "1. Кто выполнил задание\n";
    std::cout << "2. Результат программы\n";
    std::cout << "3. Суть задания\n";
    std::cout << "4. Выход из программы\n";
    std::cout << "5. Вариант\n";
    std::cout << ">>>\n";
    int n;
    while (!(std::cin >> n) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите значение повторно: ";
    }
    return n;
}

void program() {
    int number;
    std::cout << "Введите количество чисел массива: ";
    while (!(std::cin >> number) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверно, введите значение заново: ";
    }

    const int SIZE = number;
    double arrNumber[SIZE] = {};
    for (int i = 0; i < SIZE; i++) {
        double element;
        std::cout << "Введите " << i << " элемент первоначального массива: " << std::endl;
        std::cin >> element;
        while (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите значение повторно:";
        std::cin >> element;
    }
        arrNumber[i] = element;
    }

    for (int i = 0; i < SIZE; i++) {
        std::cout << arrNumber[i] << std::endl;
    }

    int step;
    std::cout << "Введите число, на сколько позиций хотите сдвинуть массив вправо: ";
    while (!(std::cin >> step) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверно, введите значение заново: ";
    }

    const int STEP = step;
    double arrNew[SIZE + STEP] = {};

    for (int i = 0; i < STEP; i++) {
        double element2;
        std::cout << "Введите новый элемент массива: " << std::endl;
        std::cin >> element2;
        while (std::cin.fail()){
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите значение повторно:";
        std::cin >> element2;
    }
        arrNew[i] = element2;
    }
    for (int i = 0; i < SIZE; i++) {
        arrNew[i + STEP] = arrNumber[i];
    }

    for (int i = 0; i < SIZE + STEP; i++) {
        std::cout << arrNew[i] << std::endl;
    }
}

int main() {
    while (true) {
        int number = menu();
        if (number == 1) {
            std::cout << "Попова Яна\n";
        } else if (number == 2) {
            program();
        } else if (number == 3) {
            std::cout << "Ввести статический одномерный массив из k чисел и сдвинуть элементы массива циклически на п позиций вправо\n";
        } else if (number == 4) {
            std::cout << "Выход выполнен успешно!\n";
            return 0;
        } else if (number == 5) {
            std::cout << "Вариант: 6\n";
        } else {
            std::cout << "Неверно ввели значение, попробуйте еще раз: \n";
            continue;
        }
        std::cout << ">>>\n";
    }
}

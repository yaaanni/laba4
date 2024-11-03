#include <iostream>
#include <limits>

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
    int rows, cols;
    std::cout << "Введите количество строк массива: ";
    while (!(std::cin >> rows) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите значение повторно: ";
    }
    std::cout << "Введите количество столбцов массива: ";
    while (!(std::cin >> cols) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите значение повторно: ";
    } 
    double** arr = new double*[rows];
    
    for (int i = 0; i < rows; i++) {
        arr[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double element;
            std::cout << "Введите элемент массива, находящийся в " << i << " строке " << j << " столбце: ";
            std::cin >> element;
            while (std::cin.fail()){
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите значение повторно:";
            std::cin >> element;
    }
            arr[i][j] = element;
        }
    }

    // Поиск элементов, которые являются минимальными в своей строке и максимальными в своем столбце, или наоборот
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool isMinInRow = true;
            bool isMaxInRow = true;
            bool isMinInCol = true;
            bool isMaxInCol = true;
            
            // Проверка строки
            for (int k = 0; k < cols; k++) {
                if (arr[i][k] < arr[i][j]) {
                    isMinInRow = false;
                }
                if (arr[i][k] > arr[i][j]) {
                    isMaxInRow = false;
                }
            }
            
            // Проверка столбца
            for (int k = 0; k < rows; k++) {
                if (arr[k][j] < arr[i][j]) {
                    isMinInCol = false;
                }
                if (arr[k][j] > arr[i][j]) {
                    isMaxInCol = false;
                }
            }
            
            // Вывод индексов элементов, которые соответствуют условиям
            if ((isMinInRow && isMaxInCol) || (isMaxInRow && isMinInCol)) {
                std::cout << "Элемент с индексами (" << i << ", " << j << ") удовлетворяет условиям." << std::endl;
            }
        }
    }

    // Вывод элементов массива
    std::cout << "Элементы массива:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    while (true) {
        int number = menu();
        if (number == 1) {
            std::cout << "Попова Яна\n";
        } else if (number == 2) {
            program();
        } else if (number == 3) {
            std::cout << "Создать динамический двумерный массив и определить индекс элемента, если он \nнаименьший в своей строке и наибольший (одновременно) в своём столбце (или \nнаоборот, наибольший в своей строке и наименьший в своём столбце)\n";
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
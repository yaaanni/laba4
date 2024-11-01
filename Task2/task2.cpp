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
    int rows;
    std::cout << "Введите количество строк массива: ";
    while (!(std::cin >> rows) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверно, введите значение заново: ";
    }
    const int ROWS = rows;
    int columns;
    std::cout << "Введите количество столбцов массива: ";
    while (!(std::cin >> columns) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверно, введите значение заново: ";
    }
    const int COLUMNS = columns;

    int arrFirst[ROWS][COLUMNS] = {};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int element;
            std::cout << "Введите элемент, находящийся в " << i << " строке и " << j << " столбце: "; 
            while (!(std::cin >> element) || (std::cin.peek() != '\n')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверно, введите значение заново: ";
        }
            arrFirst[i][j] = element; 
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            std::cout << arrFirst[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    int amountChetnMain = 0;
    int amountChetnPoboch = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (i == j) {
                int amountMain = arrFirst[i][j];
                if (amountMain%2 == 0) {
                    amountChetnMain++;
                }
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        int numberRows = i;
        int numberColumns = COLUMNS - 1 - i;
        int elementPoboch = arrFirst[numberRows][numberColumns];
        
        if (elementPoboch % 2 == 0) {
            amountChetnPoboch++;
        }
    }

    std::cout << "Количество четных элементов на главной диагонали матрицы равно: " << amountChetnMain << std::endl;
    std::cout << "Количество четных элементов на побочной диагонали матрицы равно: " << amountChetnPoboch << std::endl;
} 


int main() {
    while (true) {
        int number = menu();
        if (number == 1) {
            std::cout << "Попова Яна\n";
        } else if (number == 2) {
            program();
        } else if (number == 3) {
            std::cout << "Ввести статический двумерный массив размером m*n и определить \nколичество четных элементов, расположенных на главной и побочной \nдиагонали матрицы \n";
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

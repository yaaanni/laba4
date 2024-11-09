#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

std::string program(int rows, int cols, const std::vector<std::vector<int>> &arrNumber) {
    std::ostringstream output;
    int** arrNew = new int*[rows];
    for (int i = 0; i < rows; i++){
        arrNew[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arrNew[i][j] = arrNumber[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool isMinInRow = true;
            bool isMaxInRow = true;
            bool isMinInCol = true;
            bool isMaxInCol = true;
            
            // Проверка строки
            for (int k = 0; k < cols; k++) {
                if (arrNew[i][k] < arrNew[i][j]) {
                    isMinInRow = false;
                }
                if (arrNew[i][k] > arrNew[i][j]) {
                    isMaxInRow = false;
                }
            }
            
            // Проверка столбца
            for (int k = 0; k < rows; k++) {
                if (arrNew[k][j] < arrNew[i][j]) {
                    isMinInCol = false;
                }
                if (arrNew[k][j] > arrNew[i][j]) {
                    isMaxInCol = false;
                }
            }
            
            // Вывод индексов элементов, которые соответствуют условиям
            if ((isMinInRow && isMaxInCol) || (isMaxInRow && isMinInCol)) {
                output << i << " " << j << " ";
            }
        }
    }

    for (int i = 0; i < rows; i++){
        delete[] arrNew[i];
    }
    delete[] arrNew;
    return output.str();
}

TEST(SampleTest, Example) {
    std::vector<std::vector<int>> arrNumber = {{4, 5, 6}, {7, 8, 9}};
    EXPECT_EQ(program(2, 3, arrNumber), "0 2 1 0 ");
}

TEST(SampleTest, Example2) {
    std::vector<std::vector<int>> arrNumber = {{2, 3}, {4, 5}, {6, 7}, {8, 9}};
    EXPECT_EQ(program(4, 2, arrNumber), "0 1 3 0 ");
}

TEST(SampleTest, Example3) {
    std::vector<std::vector<int>> arrNumber = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}};
    EXPECT_EQ(program(2, 6, arrNumber), "0 5 1 0 ");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
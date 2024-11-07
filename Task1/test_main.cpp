#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <string>

// Обновленная функция program, которая принимает аргументы и возвращает результат в виде строки
std::string program(int a, const std::vector<double>& arrNumber, int c, const std::vector<double>& newElements) {
    std::ostringstream output;

    const int SIZE = a;
    const int STEP = c;
    std::vector<double> arrNew(SIZE + STEP);

    // Заполнение нового массива
    for (int i = 0; i < STEP; i++) {
        arrNew[i] = newElements[i];
    }
    for (int i = 0; i < SIZE; i++) {
        arrNew[i + STEP] = arrNumber[i];
    }

    // Формирование строки результата
    for (int i = 0; i < SIZE + STEP; i++) {
        output << arrNew[i] << std::endl;
    }

    return output.str();
}

// Тестовый случай
TEST(SampleTest, Example) {
    std::vector<double> arrNumber = {1};
    std::vector<double> newElements = {2};
    EXPECT_EQ(program(1, arrNumber, 1, newElements), "2\n1\n");
}

TEST(SampleTest, Example2) {
    std::vector<double> arrNumber = {1};
    std::vector<double> newElements = {2,3};
    EXPECT_EQ(program(1, arrNumber, 2, newElements), "2\n3\n1\n");
}

TEST(SampleTest, Example3) {
    std::vector<double> arrNumber = {1,2};
    std::vector<double> newElements = {3,4};
    EXPECT_EQ(program(2, arrNumber, 2, newElements), "3\n4\n1\n2\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
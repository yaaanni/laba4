#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

std::string program(int rows, int cols, const std::vector<std::vector<int>> &arrNumber) {
    std::ostringstream output;
    std::vector<std::vector<int>> arrNew(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arrNew[i][j] = arrNumber[i][j];
        }
    }

    int amountChetnMain = 0;
    int amountChetnPoboch = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                int amountMain = arrNew[i][j];
                if (amountMain % 2 == 0) {
                    amountChetnMain++;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        int numberRows = i;
        int numberColumns = cols - 1 - i;
        int elementPoboch = arrNew[numberRows][numberColumns];
        
        if (elementPoboch % 2 == 0) {
            amountChetnPoboch++;
        }
    }

    output << amountChetnMain << " " << amountChetnPoboch;
    return output.str();
}

TEST(SampleTest, Example) {
    std::vector<std::vector<int>> arrNumber = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(program(2, 3, arrNumber), "0 0");
}

TEST(SampleTest, Example1) {
    std::vector<std::vector<int>> arrNumber = {{2, 3, 4, 5}};
    EXPECT_EQ(program(1, 4, arrNumber), "1 0");
}

TEST(SampleTest, Example2) {
    std::vector<std::vector<int>> arrNumber = {{1,2}, {3,4}, {5,6}};
    EXPECT_EQ(program(3, 2, arrNumber), "1 2");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

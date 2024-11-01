#include <iostream>
#include <sstream>
#include <string>
#include <gtest/gtest.h>
TEST(Array1ToStringTest, ConvertArray1ToString) {
    std::string stroka;
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::ostringstream arr_str;
    for (int i = 0; i < n; i++) {
        arr_str << arr[n-i-1] << " ";
    }
    stroka = arr_str.str();
    ASSERT_EQ("5 4 3 2 1 ", stroka);
}
TEST(Array2ToStringTest, ConvertArray2ToString) {
    std::string stroka;
    int arr[] = {5,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::ostringstream arr_str;
    for (int i = 0; i < n; i++) {
        arr_str << arr[n-i-1] << " ";
    }
    stroka = arr_str.str();
    ASSERT_EQ("9 8 6 5 ", stroka);
}
TEST(Array3ToStringTest, ConvertArray3ToString) {
    std::string stroka;
    int arr[] = {17,33,99,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::ostringstream arr_str;
    for (int i = 0; i < n; i++) {
        arr_str << arr[n-i-1] << " ";
    }
    stroka = arr_str.str();
    ASSERT_EQ("1 99 33 17 ", stroka);
}
TEST(Array4ToStringTest, ConvertArray4ToString) {
    std::string stroka;
    int arr[] = {6,17,8,25,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::ostringstream arr_str;
    for (int i = 0; i < n; i++) {
        arr_str << arr[n-i-1] << " ";
    }
    stroka = arr_str.str();
    ASSERT_EQ("2 3 25 8 17 6 ", stroka);
}
TEST(Array5ToStringTest, ConvertArray5ToString) {
    std::string stroka;
    int arr[] = {4,5,6,7,12,1,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::ostringstream arr_str;
    for (int i = 0; i < n; i++) {
        arr_str << arr[n-i-1] << " ";
    }
    stroka = arr_str.str();
    ASSERT_EQ("6 5 4 1 12 7 6 5 4 ", stroka);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
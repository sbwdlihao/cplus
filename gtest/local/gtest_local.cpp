//
// Created by bencong on 2017/9/28.
//

#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    std::cout << "This is gtest local!" << std::endl;
    return RUN_ALL_TESTS();
}
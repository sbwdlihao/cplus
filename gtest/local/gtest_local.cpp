//
// Created by bencong on 2017/9/28.
//

#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    testing::InitGoogleMock(&argc, argv);
    std::cout << "This is gtest local!" << std::endl;
    return RUN_ALL_TESTS();
}
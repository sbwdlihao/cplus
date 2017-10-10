//
// Created by bencong on 2017/9/28.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mock_turtle.h"

using ::testing::AtLeast;
using ::testing::Return;

TEST(simple, equal) {
    ASSERT_EQ(1, 1);
}

TEST(simple, mock) {
    MockTurtle turtle;
    EXPECT_CALL(turtle, Add(1, 1))
                .Times(AtLeast(1))
            .WillOnce(Return(2));
    int a = turtle.Add(1, 1);
    EXPECT_EQ(2, a);
}
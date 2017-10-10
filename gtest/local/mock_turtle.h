//
// Created by bencong on 2017/10/9.
//

#include "turtle.h"
#include "gmock/gmock.h"

class MockTurtle: public Turtle {
public:
    MOCK_METHOD2(Add, int(int, int));
};

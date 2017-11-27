//
// Created by bencong on 2017/11/7.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <unordered_map>
#include <map>
#include "protocol.h"

using namespace std;

struct S0 {
    uint32_t a;
    uint32_t b;
    uint32_t c;
};

bool operator==(const S0& lhs, const S0& rhs) {
    return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c;
}

namespace std {
    template<> struct hash<S0> {
        typedef S0 argument_type;
        typedef size_t result_type;
        result_type operator()(argument_type const& s) const noexcept
        {
            std::size_t seed = 0;
            hash_combine(seed, s.a);
            hash_combine(seed, s.b);
            hash_combine(seed, s.c);
            return seed;
        }
    };
}

struct S1 {
    uint32_t a;
    uint32_t b;
};

TEST(unordered_map, construct) {
    unordered_map<uint32_t, uint32_t> um = {{1,2}, {3,4}};
    ASSERT_EQ(2, um.at(1));
    ASSERT_EQ(4, um.at(3));

    unordered_map<S0, S1> s01 = {
            {
                    {1,2,3},{3,4}
            }
    };
    ASSERT_EQ(1, s01.size());
    s01[{1,2,3}] = {3,4};
    ASSERT_EQ(1, s01.size());
}


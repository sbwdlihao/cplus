//
// Created by bencong on 2017/12/8.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

TEST(string, stringstream) {
  std::stringstream ss;

  uint64_t seq = 10;
  ss << 10;

  while(!ss.eof()) {
    uint64_t seq1 = 0;
    ss >> seq1;
    cout << "seq1 = " << seq1;
  }
}
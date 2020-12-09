//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(TestCase1, TwoPlusTwo) {
  ASSERT_EQ(2 + 2, Add(2, 2));
}

TEST(TestCase1, TwoPlusThree) {
  ASSERT_EQ(5, Add(2, 3));
}

TEST(TestCase1, BigNums) {
  ASSERT_EQ(100, Add(10, 90));
}

TEST(TestCase1, ZeroTest) {
  ASSERT_EQ(10, Add(10, 0));
}
//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST(TestCase1, Casual2020) {
  ASSERT_EQ(true, IsLeap(2020));
}

TEST(TestCase1, Unusual2000) {
  ASSERT_EQ(true, IsLeap(2000));
}

TEST(TestCase1, Medieval1700) {
  ASSERT_EQ(false, IsLeap(1700));
}

TEST(TestCase1, Hope2021) {
  ASSERT_EQ(false, IsLeap(2021));
}

TEST(TestCase1, Cool2014) {
  ASSERT_EQ(false, IsLeap(2014));
}

TEST(TestCase1, ZeroTimes) {
  ASSERT_THROW(IsLeap(0), std::invalid_argument);
}
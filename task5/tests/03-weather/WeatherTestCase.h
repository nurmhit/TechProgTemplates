
#pragma once

#include <gtest/gtest.h>
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
public:
  WeatherMock *fake_weather;
  void SetUp() {
    fake_weather = new WeatherMock;
    cpr::Response America;
    cpr::Response Russia;
    cpr::Response Italy;

    America.status_code = 404;
    Russia.status_code = 200;
    Italy.status_code = 200;

    Russia.text = R"({"list" : [{"main": {"temp": -25}}]})";
    Italy.text = R"({"list" : [{"main": {"temp": 25}}]})";

    EXPECT_CALL(*fake_weather, Get("New York")).WillRepeatedly(testing::Return(America));
    EXPECT_CALL(*fake_weather, Get("Moscow")).WillRepeatedly(testing::Return(Russia));
    EXPECT_CALL(*fake_weather, Get("Rome")).WillRepeatedly(testing::Return(Italy));
  }
  void TearDown() {
    delete fake_weather;
  }
};




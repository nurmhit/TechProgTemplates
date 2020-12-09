//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST_F(WeatherTestCase, ApiTest) {
  ASSERT_NO_THROW(fake_weather->SetApiKey("Just_Test"));
}

TEST_F(WeatherTestCase, MoscowTest) {
  ASSERT_EQ(fake_weather->GetTemperature("Moscow"), -25);
}

TEST_F(WeatherTestCase, US) {
  ASSERT_THROW(fake_weather->GetTemperature("New York"), std::invalid_argument);
}

TEST_F(WeatherTestCase, DifferenceTest) {
  ASSERT_NO_THROW(fake_weather->GetDifferenceString("Moscow", "Rome"));
}

TEST_F(WeatherTestCase, ReverseDifferenceTest) {
  ASSERT_NO_THROW(fake_weather->GetDifferenceString("Rome", "Moscow"));
}
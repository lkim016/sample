/**
 * Generate test data.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#include <cstdint>
#include "data/data.h"

enum HOURS {
  OPEN = 8, CLOSE = 17
};

std::map<CarKind, double> PRICES = {
  {FERRARI, 256550},
  {LAMBORGHINI, 203295},
  {MCLAREN, 288845},
  {PORSCHE, 294250}
};

time_t update(time_t time, uint32_t inc) {
  /**
   * Increment time, reset to opening time if inc = 0.
   * - time: Time in seconds since epoch.
   * - inc: Increment in seconds.
   */
  time += inc;
  std::tm *tm = std::localtime(&time);
  if (tm->tm_hour > CLOSE) {
    tm->tm_yday++;
  }
  if (tm->tm_hour > CLOSE || inc == 0) {
      tm->tm_hour = OPEN;
      tm->tm_min = tm->tm_sec = 0;
  }

  return std::mktime(tm);
}

std::vector<AgentInfo> agentInfos(uint16_t count) {
  std::vector<AgentInfo> av;

  for (uint16_t i = 0; i < count; ++i) {
    av.push_back({
      std::rand() % 900000 + 100000,
      []() {
        std::map<CarKind, uint8_t> expertise;
        for (auto c : PRICES) {
          expertise[c.first] = std::rand() % PRICES.size();
        }

        return expertise;
      }(),
      static_cast<uint8_t>(std::rand() % 3 + 3),
      static_cast<double>(std::rand()) / RAND_MAX
    });
  }

  return av;
}

std::vector<CustomerInfo> customerInfos(uint16_t count) {
  std::vector<CustomerInfo> cv;

  // Start with today, randomly schedule each 2 hours.
  time_t next = update(std::time(NULL), 0);
  for (uint16_t i = 0; i < count; ++i) {
    cv.push_back({
      next = update(next, std::rand() % 2 * 3600),
      static_cast<CarKind>(std::rand() % PRICES.size()),
      std::rand() > 0.7 * RAND_MAX
    });
  }

  return cv;
}

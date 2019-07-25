/**
 * Agent declarations.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#ifndef DEALER_AGENT_H_
#define DEALER_AGENT_H_

#include <cstdint>
#include "data/data.h"

class Agent {
 private:
  uint32_t close;
  double commission; // might need to change this data type
  
 public:
  AgentInfo info;  // const AgentInfo info;
  // this is a member variable that I have to assign that's class AgentInfo
  uint32_t closes();  // this calculates how many closes he makes in a calendar week ; increment the closes by checking if the agent closed
  double revenue();
  uint16_t bonuses();
};

#endif  // DEALER_AGENT_H_

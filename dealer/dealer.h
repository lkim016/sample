/**
 * Dealer declarations.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#ifndef DEALER_DEALER_H_
#define DEALER_DEALER_H_

#include <vector>
#include "data/data.h"
#include "dealer/agent.h"

class Dealer {
 private:
  std::vector<AgentInfo>agent;
 public:
  explicit Dealer(const std::vector<AgentInfo> &);
  // constructor that passes a vector of <AgentInfo> by ref.
  uint32_t assign(const CustomerInfo &);
  // public member function that assigns an agent to a customer based on the criterias
  const std::vector<Agent> agents();
  // returns vectors of class Agent
};

#endif  // DEALER_DEALER_H_

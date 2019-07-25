/**
 * Description: dealer implementation.
 *
 * Copyright (c) 2019, Lori Kim.
*/

#include "data/data.h"
#include "dealer/dealer.h"

Dealer::Dealer(const std::vector<AgentInfo> &a) {
  // this function stores randomly generated agents from data.cpp
  // each time I call vector<AgentInfo> I instantiate a new AgentInfo
  for (auto ai : a) {
    agent.push_back(ai);
  }
}

uint32_t Dealer::assign(const CustomerInfo &ci) {
  // get customer info and match with the highest expertise
  int counter = 0;
  for (auto a : agent) {
    a.expertise[ci.interest];
    
  }
  a.info = ; // this is class AgentInfo
  return ; // return 32 bit long unsigned int
}

const std::vector<Agent> Dealer::agents() {
  
}
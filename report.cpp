#include <cstdio>
#include "dealer/agent.h"
#include "dealer/dealer.h"
#include "data/data.h"

int main() {
  uint16_t c = 5;
  Dealer dealer(agentInfos(c));  // agentInfos(int): int changes

  /*std::vector<CustomerInfo>customer = customerInfos(5);
  for (auto ci : customer) {
    dealer.assign(ci); // send customer info to assign()
  }*/
}
#include <iostream>
#include <cmath>
#include <bitset>
#include <cstdint>
#include <cstring>

#ifndef PACK

#define PACK

void number9(uint64_t number, int bite);
void number15(uint64_t number, int bite, char* argv[]);
bool isGreaterThanMax(const char* numStr);

namespace pack{
  const int ERROR = -1;
  const int SUCCESS = 0;
}

#endif
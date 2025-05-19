#include "lab6_bits.h"

void number9(uint64_t number, int bite) {
  using namespace std;
  uint64_t mask = 0;
  mask |= number;
  number = number << bite;
  uint64_t mask2 = mask >> (64 - bite % 64);
  number |= mask2;
  cout << "Number : " << bitset<64>(number);
  cout << "\n" << number;
}

void number15(uint64_t number, int bite, char* argv[]) {
  using namespace std;
  char* endptr;
  int one_bite = strtol(argv[3], &endptr, 10);
  if (*endptr != '\0' || bite > 63 || bite < 0 || one_bite > 1 || one_bite < 0) {
    cout << "ERROR with get the number\n";
    return;
  }
  uint64_t mask;
  if (one_bite == 1) mask = 1ULL << bite;
  else mask = 0ULL << bite; 
  number &= (~mask);
  number |= mask;
  cout <<  bitset<64>(number);
  cout << "\n" << number;
}
#include "lab6_bits.h"

void number9(uint64_t number, int bite);
void number15(uint64_t number, int bite, char* argv[]);

int main(int argc, char* argv[]) {
  using namespace std;
  if (argc < 3 || argc > 4) {
    cerr << "ERROR with count argumnets\n";
    return pack::ERROR;
  }
  char* endptr;
  uint64_t number = strtoull(argv[1], &endptr, 10);
  if (*endptr != '\0') {
    cout << "ERROR with get the number\n";
    return pack::ERROR;
  }
  endptr = nullptr;
  int bite = strtol(argv[2], &endptr, 10);
  if (*endptr != '\0') {
    cout << "ERROR with get the number\n";
    return pack::ERROR;
  }
  if (argc == 3) number9(number, bite);
  else number15(number, bite, argv);
}





#include <iostream>
#include <cmath>
#include <string>

#define ERROR -1
#define SUCCESS 0

bool approximatelyEqual(float a, float b, float epsilon);
bool approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon);
void test_approximatelyEqual(float a, float b, float epsilon);
void test_approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon);
int check(char* str, size_t& pos);

int main(int argc, char* argv[]) {
  using namespace std;
  if (argc < 5 || argc > 6) {
    cerr << "ERROR with count of arguments\n";
    return ERROR;
  }

  try {
    string name_of_functions = argv[1];
    size_t pos;
    float a = stof(argv[2], &pos);
    if (check(argv[2], pos) == ERROR) return ERROR;
    float b = stof(argv[3], &pos);
    if (check(argv[3], pos) == ERROR) return ERROR;
    if (name_of_functions == "approximatelyEqual" && argc == 5) {
      float epsilon = stof(argv[4], &pos);
      if (check(argv[4], pos) == ERROR) return ERROR;
      test_approximatelyEqual(a, b, epsilon);
    }
    else if (name_of_functions == "approximatelyEqualAbsRel" && argc == 6){
      float absEpsilon = stof(argv[4], &pos);
      if (check(argv[4], pos) == ERROR) return ERROR;
      float relEpsilon = stof(argv[5], &pos);
      if (check(argv[5], pos) == ERROR) return ERROR;
      test_approximatelyEqualAbsRel(a, b, absEpsilon, relEpsilon);
    }
    else {
      cerr << "ERROR with name of functions\n";
      return ERROR;
    }
  }
  catch (const invalid_argument& error) {
    cerr << "ERROR: Cannot be converted to a number\n";
    return ERROR;
  }
  catch (const out_of_range& error) {
    cerr << "ERROR: Argument is out of range for a float\n";
    return ERROR;
  }
  catch (...) {
    cerr << "ERROR: Unknown error\n";
    return ERROR;
  }
}


void test_approximatelyEqual(float a, float b, float epsilon) {
  using namespace std;
  cout << "approximatelyEqual:" << endl;
  // сравниваем "a" с b
  if (approximatelyEqual(a, b, epsilon)) cout << a << " = " << b << "\t\ta = b" << endl;
  else cout << a << " != " << b << "\t\ta != b" << endl; 

  float copy_a = a;
  for (int i{}; i < 10; i++) {
    if (a != 0.0)
      copy_a -= (fabs(a)/10.0);
  }
  // сравниваем "почти a-1.0" с 0.0
  if (approximatelyEqual(copy_a, 0.0, epsilon)) cout << copy_a << " = 0.0\t\t" << "~0.0 = 0.0" << endl;
  else cout << copy_a << " != 0.0\t\t" << "~0.0 != 0.0" << endl;
}


void test_approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon) {
  using namespace std;
  cout << "approximatelyEqualAbsRel:" << endl;
  // сравниваем "a" с b
  if (approximatelyEqualAbsRel(a, b, absEpsilon, relEpsilon)) cout << a << " = " << b << "\t\ta = b" << endl;
  else cout << a << " != " << b << "\t\ta != b" << endl; 

  float copy_a = a;
  for (int i{}; i < 10; i++) {
    if (a != 0.0)
      copy_a -= (fabs(a)/10.0);
  }
  // сравниваем "почти 0.0" с 0.0
  if (approximatelyEqualAbsRel(copy_a, 0.0, absEpsilon, relEpsilon)) cout << copy_a << " = 0.0\t\t" << "~0.0 = 0.0" << endl;
  else cout << copy_a << " != 0.0\t\t" << "~0.0 != 0.0" << endl;
}


bool approximatelyEqual(float a, float b, float epsilon) {
  return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}


bool approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon) {
  float diff = fabs(a - b);
  if (diff <= absEpsilon)
    return true;
  return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}

int check(char* str, size_t& pos) {
  std::string input = str;
  while (pos < input.size() && std::isspace(input[pos])) {
    pos++;
  }
  if (pos != input.size()) {
    std::cerr << "ERROR: Extra characters in input\n";
    return ERROR;
  }
  return SUCCESS;
}
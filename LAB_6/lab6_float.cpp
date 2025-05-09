#include <iostream>
#include <cmath>
#include <string>

#define ERROR -1
#define SUCCESS 0

bool approximatelyEqual(float a, float b, float epsilon);
bool approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon);

int main(int argc, char* argv[]) {
  using namespace std;
  if (argc < 5 || argc > 6) {
    cerr << "ERROR with count of arguments\n";
    return ERROR;
  }

  try {
    string name_of_functions = argv[1];
    float a = stof(argv[2]);
    float b = stof(argv[3]);
    if (name_of_functions == "approximatelyEqual" && argc == 5) {
      float epsilon = stof(argv[4]);
      if (approximatelyEqual(a, b, epsilon)) cout << a << " == " << b << endl;
      else cout << a << " != " << b << endl;
    }
    else if (name_of_functions == "approximatelyEqualAbsRel" && argc == 6){
      float absEpsilon = stof(argv[4]);
      float relEpsilon = stof(argv[5]);
      if (approximatelyEqualAbsRel(a, b, absEpsilon, relEpsilon)) cout << a << " == " << b << endl;
      else cout << a << " != " << b << endl;
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


bool approximatelyEqual(float a, float b, float epsilon) {
  return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}


bool approximatelyEqualAbsRel(float a, float b, float absEpsilon, float relEpsilon) {
  float diff = fabs(a - b);
  if (diff <= absEpsilon)
    return true;
  return diff <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}
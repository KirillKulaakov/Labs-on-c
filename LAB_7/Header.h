#ifndef HEADER
#define HEADER

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


//// цветной вывод
#define RESET     "\033[0m"
#define RED       "\033[31m"
#define GREEN     "\033[32m"
#define YELLOW    "\033[33m"
#define BLUE      "\033[34m"
#define BOLD      "\033[1m"
#define UNDERLINE "\033[4m"
#define WHITE     "\033[37m"



//// сама структура
template <typename T>
struct Node{
  T value;
  Node* next;
  Node* prev;

  Node() : next(nullptr), prev(nullptr) {}
};


namespace pack{
  extern const int ERROR;
  extern const int SUCCESS;
  extern const std::string PATH_OF_FILE;
  extern const std::string PATH_OF_FILE_UPLOAD;
}


void menu(int count);
int choose(int a, int b);
int check_invalide();
void menu_for_actions();
void menu_the_pole();
std::vector<std::string> split(const std::string& line, char delimiter);
void clear_screen();
void erase_line();
void animations(int time, unsigned count);

#endif

#ifndef HEADER
#define HEADER

#include <iostream>
#include <list>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>


// цветной вывод
#define RESET     "\033[0m"
#define RED       "\033[31m"
#define GREEN     "\033[32m"
#define YELLOW    "\033[33m"
#define BLUE      "\033[34m"
#define BOLD      "\033[1m"
#define UNDERLINE "\033[4m"
#define WHITE     "\033[37m"


struct Node{
  std::string surname;
  std::string name;
  std::string middle_name;
  std::string post;
  std::string country;
  std::string region;
  std::string city;
  std::string street;
  std::string house;
  std::string room;
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


int data_reading(std::list<Node>& l);
void check_the_element(std::list<Node>& l);
std::string center(const std::string& text, int width);
void print(const std::list<Node>& l);
int actions(std::list<Node>& l, int choose_user, int& exit);

#endif

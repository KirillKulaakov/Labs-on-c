#include "Header.h"
#include "Template.h"


//- разделение строки по разделителю ;
std::vector<std::string> split(const std::string& line, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(line);
  while (getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
  }
  return tokens;
}

//- вывод меню
void menu(int count) {
  using namespace std;
  cout << YELLOW  << BOLD << "Count the element: " << RED << count << RESET <<endl;
  cout << YELLOW << "PLZ Choose the actions: " << RESET << endl;
  cout << RED << BOLD << "1)" << RESET << GREEN << "Delete the specified element.The element is set by the field value; all such elements are deleted" << endl;
  cout << RED << BOLD << "2)" << RESET << GREEN << "Print all items in sorted form (for example, by full name)" << endl;
  cout << RED << BOLD << "3)" << RESET << GREEN << "Resetting the values of all elements (for example, zeroing)" << endl;
  cout << RED << BOLD << "4)" << RESET << GREEN << "Exit" << endl;
  cout << YELLOW << BOLD << "Your answer: " << RED;
}


//- выбор пользователя в пределах от a до b
int choose(int a, int b) {
  int choose;
  if(!(std::cin >> choose) || choose < a || choose > b) {
    std::cout << RED << BOLD << UNDERLINE<< "ERROR with convert to int or incorrenct number" << RESET << std::endl;
    return pack::ERROR;
  }
  std::cout << RESET;
  return (check_invalide() == pack::SUCCESS) ? choose : pack::ERROR;
}


//- проверка на валидность введенных данных
int check_invalide() {
  char ch;
  std::cin.get(ch);
  while(ch != '\n') {
    if (ch != ' ') return pack::ERROR;
    std::cin.get(ch);
  }
  return pack::SUCCESS;
}


//- вывод меню при выборе полей
void menu_for_actions() {
  std::cout << "Choose one of these options:" << std::endl;
  menu_the_pole();
}


//- вывод меню полей
void menu_the_pole() {
  std::cout << "Surname - 1\nName - 2\nMiddle name - 3\nPost - 4\nCountry - 5\n";
  std::cout << "Region - 6\nCity - 7\nStreet- 8\nHouse - 9\nApartment - 10" << std::endl;
}


//- типо очистка экрана
void clear_screen() {
  std::cout << "\033[2J\033[1;1H";  // Очистка экрана + перемещение курсора
  std::cout.flush();  // Гарантируем немедленный вывод
}


//- очищение строки
void erase_line() {
  // Переместить курсор на одну строку вверх и очистить текущую строку
  std::cout << "\033[1A"  // Вверх на 1 строку
            << "\033[2K"  // Очистить текущую строку
            << "\r";      // Вернуть курсор в начало строки
  std::cout.flush();      // Сбросить буфер вывода
}


//- анимация загрузки
void animations(int time, unsigned count) {
  using namespace std;
  for (unsigned i{}; i < count; i++) {
    cout << "." << endl;
    this_thread::sleep_for(chrono::milliseconds(time));
    erase_line();
    cout << ".." << endl;
    this_thread::sleep_for(chrono::milliseconds(time));
    erase_line();
    cout << "..." << endl;
    this_thread::sleep_for(chrono::milliseconds(time));
    erase_line();
  }
}
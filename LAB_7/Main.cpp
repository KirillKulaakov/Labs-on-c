#include "Header.h"
#include "Template.h"

namespace pack{
  const int ERROR = -1;
  const int SUCCESS = 0;
  const std::string PATH_OF_FILE = "BD.txt";
  const std::string PATH_OF_FILE_UPLOAD = "Upload.text";
}

int main() {
  using namespace std;
  using namespace pack;
  //// инициализация head списка
  Node<vector<string>>* head = initialization<vector<string>>();
  if (head == nullptr) {
    cerr << RED << BOLD << UNDERLINE << "ERROR with initialization" << RESET <<endl;
    return ERROR;
  }
  //// прошло ли успешно считывание данных
  if (data_reading<vector<string>>(head) != ERROR) {
    //// цикл программы
    int exit = SUCCESS;
    while (!exit) {
      menu(count_element(head));
      int choose_user = choose(1, 4);
      if (choose_user == ERROR) {
        cout << RED << BOLD << UNDERLINE << "ERROR with user`s choose" << RESET << endl;
        exit = ERROR;
      }
      if (exit == SUCCESS) {
        if (actions(head, choose_user, exit) == ERROR) 
          exit = ERROR;
        else clear_screen();
      } 
    }
  } 
  destroy<vector<string>>(head);
  return SUCCESS;
}
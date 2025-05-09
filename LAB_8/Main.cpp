#include "Header.h"


namespace pack{
  const int ERROR = -1;
  const int SUCCESS = 0;
  const std::string PATH_OF_FILE = "BD.txt";
  const std::string PATH_OF_FILE_UPLOAD = "Upload.txt";
}


int main() {
  using namespace std;
  using namespace pack;
  list<Node> l;
  if (data_reading(l) != ERROR) {
    int exit = SUCCESS;
    while(!exit) {
      menu(l.size());
      int choose_user = choose(1, 4);
      if (choose_user == ERROR) {
        cout << RED << BOLD << "ERROR with user`s choose" << RESET << endl;
        exit = ERROR;
      }
      if (exit == SUCCESS) {
        if (actions(l, choose_user, exit) == ERROR) 
          exit = ERROR;
        else clear_screen();
      }
    }
  }

  return 0;
}


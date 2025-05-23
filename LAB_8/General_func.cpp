#include "Header.h"


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

int data_reading(std::list<Node>& l) {
  using namespace std;
  using namespace pack;

  int flag = SUCCESS;
  ifstream file(PATH_OF_FILE);
  string line;
  if (file.is_open()) {

    while(getline(file, line) && !flag) {
      vector<string> vector_value = split(line, ';');

      if (vector_value.size() < 10) {
        cerr << RED << BOLD << "ERROR with count read data" << RESET << endl;
        flag = ERROR;
      } 
      else {
        l.push_back(Node({vector_value[0], vector_value[1], vector_value[2], vector_value[3], vector_value[4], vector_value[5], 
          vector_value[6], vector_value[7], vector_value[8], vector_value[9]}));
      }
    }
    file.close();
  } 
  else {
    cerr << RED << BOLD <<"ERROR with open the file" << RESET << endl;
    flag = ERROR;
  }
  return flag;
}


void check_the_element(std::list<Node>& l) {
  using namespace std;
  using namespace pack;
  string line;
  int check = 0;
  cout << YELLOW <<  "\nEnter a element(surname;name;middle name;post;...)" << RESET << endl << BOLD << ": ";
  getline(cin, line);
  cout << RESET;
  vector<string> vector_value = split(line, ';');

  if (vector_value.size() < 10) {
    cerr << RED << BOLD <<"\nERROR with count input id\n" << RESET << endl ;
    animations(110, 7);
  } 
  else {
    int count = 0;
    for (int i{}; i < 10; i++) {
      if (vector_value[i].empty()) vector_value[i] = "NULL";
      else count++;
    }

    if (!l.empty()) {

      for (const auto& element: l) {
        if ((vector_value[0] != "NULL" && vector_value[0] == element.surname) +
            (vector_value[1] != "NULL" && vector_value[1] == element.name) +
            (vector_value[2] != "NULL" && vector_value[2] == element.middle_name) +
            (vector_value[3] != "NULL" && vector_value[3] == element.post) +
            (vector_value[4] != "NULL" && vector_value[4] == element.country) +
            (vector_value[5] != "NULL" && vector_value[5] == element.region) +
            (vector_value[6] != "NULL" && vector_value[6] == element.city) +
            (vector_value[7] != "NULL" && vector_value[7] == element.street) +
            (vector_value[8] != "NULL" && vector_value[8] == element.house) +
            (vector_value[9] != "NULL" && vector_value[9] == element.room) >= count) check = 1;
      }

      if (check == 1)
        cout << GREEN << BOLD << "\nCongratulations" << RED "!!!" << GREEN "\nthere is such an item in the list" << RESET << endl;
      else 
        cout << YELLOW << BOLD <<"\no_O\tThis element was not found" << RESET << endl;
    }
    else cout << YELLOW << BOLD <<"\nLIST IS EMPTY :-|" << RESET << endl;

    char ch;
    cout <<  BOLD <<"\nPLZ Enter any simbol: ";
    cin.get(ch);
    while (ch != '\n')  
      cin.get(ch);
    cout << RESET << endl;
    animations(105, 3);
  }
}


std::string center(const std::string& text, int width) {
  std::string trimmed;
  if (text.length() > static_cast<size_t>(width)) {
    trimmed = text.substr(0, width -3) + "...";
  } else 
    trimmed = text;
  
  int text_len = trimmed.length();
  int left_pad = (width - text_len) / 2;
  int right_pad = width - text_len - left_pad;
  
  return std::string(left_pad, ' ') + trimmed + std::string(right_pad, ' ');
}


void print(const std::list<Node>& l) {
  using namespace std;
  if (!l.empty()) {
    cout << endl << BOLD;
    for (int i{}; i < 154; i++) {
      if (i == 0 || i == 153) cout << "*";
      else cout << "-";
    }
    cout << endl;
    cout << BOLD << "|" << YELLOW <<center("surname", 18) << RESET;
    cout << BOLD <<"|" << YELLOW <<center("name", 14) << RESET;
    cout << BOLD <<"|" << YELLOW << center("middle name", 20) << RESET;
    cout << BOLD <<"|" << YELLOW << center("post", 16) << RESET;
    cout << BOLD <<"|" << YELLOW << center("country", 14) << RESET;
    cout << BOLD <<"|" << YELLOW << center("region", 14) << RESET;
    cout << BOLD <<"|" << YELLOW << center("city", 14) << RESET;
    cout << BOLD <<"|" << YELLOW << center("street", 20) << RESET;
    cout << BOLD <<"|" << YELLOW << center("house", 7) << RESET;
    cout << BOLD <<"|" << YELLOW << center("room", 6) << RESET << BOLD << "|" << endl << RESET;
    for (const auto& element: l) {
      cout << BOLD <<"|" << BLUE << center(element.surname, 18) << RESET;
      cout << BOLD <<"|" << BLUE << center(element.name, 14) << RESET;
      cout << BOLD <<"|" << BLUE << center(element.middle_name, 20) << RESET;
      cout << BOLD <<"|" << BLUE << center(element.post, 16) << RESET;
      cout << BOLD <<"|" << BLUE << center(element.country, 14) << RESET;
      cout << BOLD <<"|" << BLUE << center(element.region, 14) << RESET;
      cout << BOLD <<"|" << BLUE << center(element.city, 14) << RESET;
      cout << BOLD <<"|" << BLUE << center(element.street, 20) << RESET;
      cout << BOLD <<"|" << BLUE << center(element.house, 7) << RESET;
      cout << BOLD <<"|" << BLUE << center(element.room, 6) << RESET << BOLD << "|" << endl << RESET;
    }
  }
  char ch;
  cout << BOLD << "\nPLZ Enter any simbol: ";
  cin.get(ch);
  while (ch != '\n')  
      cin.get(ch);
  cout << RESET << endl;
  animations(150, 4);
}



void default_values(std::list<Node>& l) {
  const Node array[5] {{"Kulakov", "Kirill", "Dmitrievich", "student", "Russia", "Tatarstan", "Kazan", "kirpichnilova", "11", "534"},
                        {"Gubaidullin", "Shamil", "ildarovich", "prepod", "Russia", "Udmurtia", "Izhevsk", "baranova", "998", "50"},
                        {"Vinogradov", "Ilya", "Aleksandrovich", "voditel", "Russia", "Moscow", "Moscow", "autoprospect", "100", "456"},
                        {"Chinazes", "Gubka", "Bob", "cook", "Ocean", "beach", "Bikini Bottom", "street 5", "1", "1"},
                        {"Cherpak", "Sanya", "Sanich", "fireman", "Kazakhstan", "NULL", "Astana", "cherpakova", "12", "999"}};
  int id = 0;
  for (auto& element: l) {
    element.surname = array[id].surname;
    element.name = array[id].name;
    element.middle_name = array[id].middle_name;
    element.post = array[id].post;
    element.country = array[id].country;
    element.region = array[id].region;
    element.city = array[id].city;
    element.street = array[id].street;
    element.house = array[id].house;
    element.room = array[id].room;
    ++id;
    id %= 5;
  }
  std::cout << GREEN << BOLD << "\nSUCCESS" << RESET << BOLD << " change velaus in list\n" << RESET <<std::endl;
  animations(115, 5);
}


int upload_data(std::list<Node>& l) {
  using namespace pack;
  using namespace std;
  int flag = SUCCESS;
  ofstream file(PATH_OF_FILE_UPLOAD);
  if (file.is_open()) {
    for (const auto& el: l) {
      string str = el.surname + ";" + el.name + ";" + el.middle_name + ";" + el.post + ";" + el.country + ";" + el.region + ";" + el.city + ";" + el.street + ";" + el.house + ";" + el.room + "\n";
      file << str;
    }
    file.close();
  } else {
    cout << RED << BOLD << "ERROR with open the file" << RESET << endl;
    flag = ERROR;
  }
  return flag;
}



int actions(std::list<Node>& l, int choose_user, int& exit) {
  using namespace std;
  using namespace pack;
  int flag = SUCCESS;
  // если пользователь выбрал 1)  или 2)  или 3) 
  if (choose_user == 1 || choose_user == 2 || choose_user == 3) {
    if (choose_user == 1) { // если 1)
      check_the_element(l);
    }
    else if (choose_user == 2) { // если 2)
      print(l);
    }
    else {
      default_values(l);
    }
  } else if (choose_user == 4) {
    exit = 1;
    cout << WHITE << BOLD << "\n\nWait for a while..." << RESET << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(1300));
    cout << WHITE << BOLD << "uploading the data..." << RESET << endl << endl;

    if (upload_data(l) == ERROR)
      flag = ERROR;
    if (!flag) {
      this_thread::sleep_for(chrono::milliseconds(1300));
      cout << WHITE << BOLD << "You have" << GREEN << " success " << WHITE << "logged out of the program." << RESET << endl;
      this_thread::sleep_for(chrono::milliseconds(1500));
    }
  }
  if (flag == ERROR) cout << RED << BOLD << "ERROR with user`s choose" << RESET << endl;

  return flag;
}
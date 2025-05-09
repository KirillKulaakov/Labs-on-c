#ifndef TEMPLATE

#define TEMPLATE

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Header.h"
#include <chrono>
#include <thread>


//- инициализация head у списка
template <typename T>
Node<T>* initialization() {
    Node<T>* head = new(std::nothrow) Node<T>();
    if (head == nullptr) 
        return nullptr;
    return head;
}


//- добавление элемента в список
template <typename T>
Node<T>* add_element(Node<T>* head) {
    Node<T>* ptr = new(std::nothrow) Node<T>;
    if (ptr == nullptr)  
      return nullptr;
    ptr->next = nullptr;
    ptr->prev = nullptr;
    if (head == nullptr) 
      return ptr;
    Node<T>* current = head;
    while (current->next != nullptr) {
      current = current->next; 
    }
    current->next = ptr; 
    ptr->prev = current; 
    return head; 
}


//- удаление элемениа из списка
template <typename T>
Node<T>* delete_element(Node<T>* head, Node<T>* element) {
  if (head == nullptr || element == nullptr) 
    return head; 
  if (head == element) {
    Node<T>* ptr = head->next; 
    if (ptr != nullptr)
      ptr->prev = nullptr; 
    delete head; 
    head = ptr; 
  } else {
    Node<T>* prev = element->prev;
    Node<T>* next = element->next;
    if (prev != nullptr) 
      prev->next = next; 
    if (next != nullptr) 
      next->prev = prev;
    delete element; 
  }
  return head; 
}


//- полное очищение узла
template <typename T>
void destroy(Node<T>* head) {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current; 
        current = next; 
    }
}


//- считывание с файла данные, разделенные ; и \n
template <typename T>
int data_reading(Node<T>* head) {
  using namespace std;
  using namespace pack;

  int flag = SUCCESS;
  Node<T>* current = head;
  ifstream file(PATH_OF_FILE);
  string line;
  if (file.is_open()) {

    ////  заполнение head
    getline(file, line);
    current->value = split(line, ';');
    if (current->value.size() < 10) {
      cerr << "ERROR with count read data" << endl;
      flag = ERROR;
    }

    ////  заполнение всех остальных элементов списка
    while(getline(file, line) && !flag) {
      head = add_element(head); 
      if (head == nullptr) return ERROR;
      current = current->next;
      current->value = split(line, ';');
      if (current->value.size() < 10) {
        cerr << "ERROR with count read data" << endl;
        flag = ERROR;
      }
    } 
  } else {
    cerr << "ERROR with open the file" << endl;
    flag = ERROR;
  }
  file.close();
  return flag;
}


//- удаление всех нужных элементов
template <typename T>
Node<T>* delete_the_all_need(Node<T>*& head, int id, const std::string& coincidences) {
  Node<T>* current = head;
  Node<T>* to_delete = nullptr;
  //// проходимся по списку и ищем совпадения
  while (current != nullptr) {
    Node<T>* next = current->next;
    if (current->value[id].find(coincidences) != std::string::npos) {
      head = delete_element(head, current); 
      to_delete = current; 
    }
    current = next; 

    if (to_delete != nullptr) {
      current = next; 
      to_delete = nullptr; 
    }
  }
  return head;
}


//- поменять местами элементы в списке
template <typename T>
void swap(std::vector<T>& arr, int index1, int index2) {
  T a = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = a;
}


//- вывести отсортированные значения
template <typename T>
void sort_to_console(std::vector<T>& arr) {
  int count{};
  for (size_t i{}; i < arr.size(); i++) {
    std::cout << ++count << ") "; 
    for (int j{}; j < 10; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


//- количество элементов в списке
template <typename T>
int count_element(Node<T>*& head) {
  int count{};
  Node<T>* current = head;
  while(current != nullptr) {
    ++count;
    current = current->next;
  }
  return count;
}


//- действия пользователя
template <typename T>
int actions(Node<T>*& head, int choose_user, int& exit) {
  using namespace std;
  using namespace pack;
  int flag = SUCCESS;
  //// если пользователь выбрал 1) УДалить все удовлетворяющие условию или 2) вывести значения отсортированными или 3) обнуление
  if (choose_user == 1 || choose_user == 2 || choose_user == 3) {
    menu_for_actions(); // вывод меню
    cout << "Enter a choose: ";
    int id = choose(1, 10); // выбор категории
    if (choose_user == 1) { //// если 1)
      if (head != nullptr) {
        if (id != ERROR) {
          string search;
          cout << "Enter a str search: ";
          getline(cin, search); // строка поиска для удаления
          head = delete_the_all_need(head, id-1, search);
        } else flag = ERROR;
      } else {
        cout << endl << "THE LIST IS EMPTY" << endl;
      }
      if (!flag) animations(180, 7);
    } 
    else if (choose_user == 2) { //// если 2)
      if (id != ERROR) {
        if (head != nullptr) {
          vector<T> list_of_value; // vector для хранения значений
          Node<T>* current = head;
          while (current != nullptr) {
            list_of_value.push_back(current->value);
            current = current->next;
          }
          //// сортировка пузырьком
          for (size_t i{}; i < list_of_value.size() - 1; i++) { 
            if (list_of_value[i][id-1] > list_of_value[i+1][id-1]) {
              swap<vector<string>>(list_of_value, i, i+1); 
            }
          }
          //// вывод на экран значения
          sort_to_console<vector<string>>(list_of_value);
        } else cout << endl << "THE LIST IS EMPTY" << endl;
        if (!flag) animations(200, 7);
      } else flag = ERROR;
    }
    else {
      if (id != ERROR) {
        if (head != nullptr) {
          Node<T>* current = head;
          //// замена значений на NULL
          while (current != nullptr) {
            current->value[id-1] = "NULL";
            current = current->next;
          }
          animations(125, 6);
        }
      } else flag = ERROR;
    }
  } else if (choose_user == 4) { //// выход из программы
    exit = 1;
    cout << "Wait for a while..." << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(1300));
    cout << "uploading the data..." << endl << endl;
    //// выгрузка в файл остаточные данные
    if (upload_data(head) == ERROR)
      flag = ERROR;
    if (!flag) {
      this_thread::sleep_for(chrono::milliseconds(1300));
      cout << "You have success logged out of the program." << endl;
      this_thread::sleep_for(chrono::milliseconds(1500));
    }
  }
  if (flag == ERROR) cout << "ERROR with user`s choose" << endl;
  return flag;
}


//- выгрузка в файл остаточные данные перед завершением программы
template <typename T>
int upload_data(Node<T>*& head) {
  using namespace pack;
  using namespace std;
  int flag = SUCCESS;
  ofstream file(PATH_OF_FILE_UPLOAD);
  if (file.is_open()) {
    Node<T>* current = head;
    vector<T> list;
    //// добавляем значения в список значений
    while(current != nullptr) {
      list.push_back(current->value);
      current = current->next;
    }
    //// Объединяем все значения в один string и записываем его в файл
    for (size_t i{}; i < list.size(); i++) {
      string str;
      for (int j = 0; j < 10; j++) {
        str += list[i][j];
        str += ";";
      }
      if (i != list.size() - 1) {
        str += "\n";
      }
      file << str;
    }
    file.close();
  } else {
    cout << "ERROR with open the file" << endl;
    flag = ERROR;
  }
  return flag;
}


#endif
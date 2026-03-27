#include <iostream>
#include <cstring>

using namespace std;

// Tree node
struct Node {

  int value;
  Node* left;
  Node* right;
  Node* parent;
  
};

void print();
void insertion();
void fixInsert();

void leftRotate();
void rightRotate();

int main() {

  // Program variables
  Node* root = NULL;

  bool run = true;
  char input[99] = "";
  int num = 0;
  
  // const char* SEARCH = "SEARCH";
  const char* INS = "INSERT";
  //  const char* DEL = "DELETE";
  const char* PRINT = "PRINT";
  const char* QUIT = "QUIT";

  // Command loop
  while (run == true) {

    cout << "Enter command: ";
    cin >> input;
    cout << endl;

    if (strcmp(input, INS) == 0) { // Insert value
    } else if (strcmp(input, PRINT) == 0) { // Print tree
    } else if (strcmp(input, QUIT) == 0) { // Quit
      run = false;
    }
  }
}

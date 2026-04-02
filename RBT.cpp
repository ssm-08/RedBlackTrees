#include <iostream>
#include <cstring>

using namespace std;

// Tree node
struct Node {

  int value;
  bool red;
  Node* left;
  Node* right;
  Node* parent;
  
};

void print(Node* c, int depth);
Node* search(Node* c, int n);
void insertion(Node*& r, Node* c, Node* n);

void fixInsert();
void leftRotate(Node*& r, Node* x);
void rightRotate(Node*& r, Node* x);

int main() {

  // Program variables
  Node* root = NULL;

  bool run = true;
  char input[99] = "";
  int num = 0;
  
  // const char* SEARCH = "SEARCH";
  const char* INS = "INSERT";
  const char* ROT = "ROTATE";
  //  const char* DEL = "DELETE";
  const char* PRINT = "PRINT";
  const char* QUIT = "QUIT";

  // Command loop
  while (run == true) {

    cout << "Enter command: ";
    cin >> input;
    cout << endl;

    if (strcmp(input, INS) == 0) { // Insert value
      cout << "Enter number: ";
      cin >> num;
      cout << endl;

      if (!search(root, num)) {
	Node* data = new Node{num, true, NULL, NULL, NULL};
	insertion(root, root, data);
      }
    } else if (strcmp(input, PRINT) == 0) { // Print tree
      if (root) {
	print(root, 0);
      }
    } else if (strcmp(input, ROT) == 0) {
      cout << "Enter number: ";
      cin >> num;
      cout << endl;

      leftRotate(root, search(root, num));
    } else if (strcmp(input, QUIT) == 0) { // Quit
      run = false;
    }
  }
}

void leftRotate(Node*& r, Node* x) {

  Node* y = x->right;

  if (y == NULL) {
    return;
  }
  
  // Handle sub-trees
  x->right = y->left;
  
  if (y->left) {
    y->left->parent = x;
  }

  // Handle node relationships
  y->parent = x->parent;

  if (x->parent == NULL) {
    r = y;
  } else if (x->parent->left == x) {
    x->parent->left = y;
  } else if (x->parent->right == x) {
    x->parent->right = y;
  }

  x->parent = y;
  y->left = x;
}

void rightRotate(Node*& r, Node* x) {

  Node* y = x->left;

  if (y == NULL) {
    return;
  }
  
  // Handle sub-trees
  x->left = y->right;

  if (y->right) {
    y->right->parent = x;
  }

  // Handle node relationships

  y->parent = x->parent;

  if (x->parent == NULL) {
    r = y;
  } else if (x->parent->left == x) {
    x->parent->left = y;
  } else if (x->parent->right == x) {
    x->parent->right = y;
  }

  x->parent = y;
  y->right = x;
}

void print(Node* c, int depth) {

  Node* left = c->left;
  Node* right = c->right;

  if (right != NULL) {
    print(right, depth + 1);
  }
  
  for (int i = 0; i < depth; i++) {
    cout << "\t";
  }
  
  cout << c->value << endl;

  if (left != NULL) {
    print(left, depth + 1);
  }
}

Node* search(Node* c, int n) {

  // End or no node
  if (c == NULL) {
    return c;
  }

  // Search and return
  if (n < c->value) {
    return search(c->left, n);
  } else if (n > c->value) {
    return search(c->right, n);
  } else {
    return c;
  }
}

void insertion(Node*& r, Node* c, Node* n) {

  if (r == NULL) {
    r = n;
    // insert fix
  } else if (n->value < c->value) {
    n->parent = c;

    if (c->left == NULL) {
      c->left = n;
    } else {
      insertion(r, c->left, n);
    }
  } else if (n->value > c->value) {
    n->parent = c;

    if (c->right == NULL) {
      c->right = n;
    } else {
      insertion(r, c->right, n);
    }
  }
}

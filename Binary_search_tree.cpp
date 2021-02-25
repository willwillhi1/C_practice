#include <iostream>
using namespace std;

struct Node
{
  Node *Left = NULL;
  Node *Right = NULL;
  int value;
};

void insert(Node *ptr, int value)
{
  if(ptr->value >= value)
  {
    if(ptr->Left == NULL)
    {
      Node *n = new Node;
      n->value = value;
      ptr->Left = n;
      return;  
    }
    else if(ptr->Left != NULL)
    {
      insert(ptr->Left, value);
    }
  }
  else if(ptr->value < value)
  {
    if(ptr->Right == NULL)
    {
      Node *n = new Node;
      n->value = value;
      ptr->Right = n;
      return;  
    }
    else if(ptr->Right != NULL)
    {
      insert(ptr->Right, value);
    }
  }
}

Node* search(Node *ptr,int value)
{
  if(ptr == NULL)
  {
    return NULL;
  }
  else if(ptr->value == value)
  {
    return ptr;
  }
  else if(ptr->value < value)
  {
    search(ptr->Right, value);
  }
  else if(ptr->value >= value)
  {
    search(ptr->Left, value);
  }
}

void Inorder(Node *ptr)
{
  if(ptr == NULL)
  {
    return;
  }
  Inorder(ptr->Left);
  cout << ptr->value << " ";
  Inorder(ptr->Right);
}

Node* delete_node(Node *ptr, int value)   
{
  if(ptr == NULL)
  {
    return NULL;
  }
  //move to deleted node
  if(value < ptr->value)
  {
    ptr->Left = delete_node(ptr->Left, value);
  }

  else if(value > ptr->value)
  {
    ptr->Right = delete_node(ptr->Right, value);
  }
  //find the deleted node
  else
  {
    if(ptr->Left == NULL)
    {
      Node* t = ptr->Right;
      delete ptr;
      return t;
    }
    else if(ptr->Right == NULL)
    {
      Node* t = ptr->Left;
      delete ptr;
      return t;
    }
    else
    {
      Node* t = ptr->Right;             //replace by rigth-subtree's smallest node
      while(t->Left != NULL)
      {
        t = t->Left;
      }
      ptr->value = t->value;
      ptr->Right = delete_node(ptr->Right, t->value);
    }
    return ptr;
  }
}

int main()
{
  //initial the BST
  Node *root = NULL;
  Node *n = new Node;
  cout << "Please enter the first value to initial: ";
  cin >> n->value;
  root = n;
  bool flag = true;
  //cout << ptr->value << endl;
  while(flag)
  {
    int op_num;
    cout << "-----------------------------------------" << endl;
    cout << "Please enter the opertation by number: " << endl;
    cout << "(1) insert\n(2) search\n(3) Inorder\n(4) delete_node\n(5) Exit\n";
    cin >> op_num;
    int value;
    Node *t = NULL;
    switch(op_num)
    {
      case 1:
        cout << "Please enter value of insertion: ";
        cin >> value;
        insert(root, value);
        cout << "insert success!" << endl;
        break;

      case 2:
        cout << "Please enter value of search: ";
        cin >> value;
        t = search(root, value);
        if(t == NULL)
          cout << "The Node is not in the BST" << endl;
        else if(t != NULL)
          cout << "The Node is in the BST" << endl;
        break;
      
      case 3:
        cout << "The BST's Inorder traversal is: ";
        Inorder(root);
        cout << endl;
        break;
      
      case 4:
        cout << "Please enter the node value to deleted: ";
        cin >> value;
        cout << endl;
        t = search(root, value);
        if(t == NULL)
        {
          cout << "No such Node to delete" << endl;
          break;
        }
        root = delete_node(root, value);
        cout << "delete success!" << endl;
        break;

      case 5:
        flag = false;
        break;

      default:
        break;
    }
  }
}

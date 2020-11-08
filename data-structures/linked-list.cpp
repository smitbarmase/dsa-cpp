// Linked List operations in C++

#include <stdlib.h>
#include <iostream>

using namespace std;

// Create a node
class Node
{
public:
  int data;
  Node *next;
};

void insertAtBeginning(Node **head_ref, int new_data)
{
  Node *new_node = new Node();
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int new_data)
{
  if (prev_node == NULL)
  {
    cout << "the given previous node cannot be NULL";
    return;
  }

  Node *new_node = new Node();
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void insertAtEnd(Node **head_ref, int new_data)
{
  Node *new_node = new Node();
  Node *last = *head_ref;
  new_node->data = new_data;
  new_node->next = NULL;
  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }

  while (last->next != NULL)
    last = last->next;

  last->next = new_node;
  return;
}

void deleteNode(Node **head_ref, int key)
{
  Node *temp = *head_ref;
  Node *prev = NULL;

  if (temp != NULL && temp->data == key)
  {
    *head_ref = temp->next;
    delete temp;
    return;
  }

  while (temp != NULL && temp->data != key)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return;

  prev->next = temp->next;
  delete temp;
}

void printList(Node *node)
{
  while (node != NULL)
  {
    cout << " " << node->data;
    node = node->next;
  }
}

// Driver program
int main()
{
  Node *head = NULL;

  insertAtEnd(&head, 6);
  insertAtBeginning(&head, 7);
  insertAtBeginning(&head, 1);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 8);
  deleteNode(&head, 1);

  cout << "Created Linked list is: ";
  printList(head);

  return 0;
}
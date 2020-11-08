// Stack implementation in C++

#include <iostream>
using namespace std;

#define SIZE 10

// Creating a stack
class Stack
{
private:
  int items[SIZE];
  int top;

public:
  Stack()
  {
    top = -1;
  }

  bool isFull()
  {
    if (top == SIZE - 1)
      return true;
    else
      return false;
  }

  bool isEmpty()
  {
    if (top == -1)
      return true;
    else
      return false;
  }

  void push(int newitem)
  {
    if (isFull())
    {
      printf("STACK FULL");
    }
    else
    {
      top++;
      items[top] = newitem;
    }
  }

  void pop()
  {
    if (isEmpty())
    {
      printf("\n STACK EMPTY \n");
    }
    else
    {
      printf("Item popped = %d", items[top]);
      top--;
    }
    cout << endl;
  }

  void print()
  {
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
    {
      cout << items[i] << " ";
    }
    cout << endl;
  }
};

int main()
{
  Stack s;

  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);

  s.print();

  s.pop();

  cout << "\nAfter popping out\n";
  s.print();
}
#include <iostream>
#include <stack>
using namespace std;

int toBinary(int n)
{
  stack<int> s;
  while (n > 0)
  {
    s.push(n % 2);
    n = n / 2;
  }

  int result = 0;

  while (!s.empty())
  {
    result += s.top();
    result *= 10;
    s.pop();
  }

  result /= 10;

  return result;
}

int main()
{
  int x;
  cin >> x;
  cout << x << " to binary is: " << toBinary(x) << endl;
}
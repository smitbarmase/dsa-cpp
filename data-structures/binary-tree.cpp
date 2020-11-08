#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

class Tree
{
  Node *root;

public:
  Tree() { root = NULL; }
  void CreateTree();
  void Preorder() { Preorder(root); }
  void Preorder(Node *p);
  void Postorder() { Postorder(root); }
  void Postorder(Node *p);
  void Inorder() { Inorder(root); }
  void Inorder(Node *p);
  void Levelorder() { Levelorder(root); }
  void Levelorder(Node *p);
  int Height() { return Height(root); }
  int Height(Node *root);
};

void Tree::CreateTree()
{
  Node *p, *t;
  int x;
  queue<Node *> q;

  printf("Eneter root value ");
  scanf("%d", &x);
  root = new Node;
  root->data = x;
  root->left = root->right = NULL;
  q.push(root);

  while (!q.empty())
  {
    p = q.front();
    q.pop();
    printf("Enter left child of %d ", p->data);
    scanf("%d", &x);
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->left = t->right = NULL;
      p->left = t;
      q.push(t);
    }
    printf("eneter right child of %d ", p->data);
    scanf("%d", &x);
    if (x != -1)
    {
      t = new Node;
      t->data = x;
      t->left = t->right = NULL;
      p->right = t;
      q.push(t);
    }
  }
}

void Tree::Preorder(struct Node *p)
{
  if (p)
  {
    printf("%d ", p->data);
    Preorder(p->left);
    Preorder(p->right);
  }
}

void Tree::Inorder(struct Node *p)
{
  if (p)
  {
    Inorder(p->left);
    printf("%d ", p->data);
    Inorder(p->right);
  }
}

void Tree::Postorder(struct Node *p)
{
  if (p)
  {
    Postorder(p->left);
    Postorder(p->right);
    printf("%d ", p->data);
  }
}

// void Tree::Levelorder(struct Node *root)
// {
//   Queue q(100);

//   printf("%d ", root->data);
//   q.enqueue(root);

//   while (!q.isEmpty())
//   {
//     root = q.dequeue();
//     if (root->lchild)
//     {
//       printf("%d ", root->lchild->data);
//       q.enqueue(root->lchild);
//     }
//     if (root->rchild)
//     {
//       printf("%d ", root->rchild->data);
//       q.enqueue(root->rchild);
//     }
//   }
// }

int Tree::Height(struct Node *root)
{
  int x = 0, y = 0;
  if (root == 0)
    return 0;
  x = Height(root->left);
  y = Height(root->right);
  if (x > y)
    return x + 1;
  else
    return y + 1;
}

int main()
{
  Tree t;
  t.CreateTree();
  cout << "Preorder ";
  t.Preorder();
  cout << endl;

  cout << "Inorder ";
  t.Inorder();
  cout << endl;

  cout << "Postorder ";
  t.Postorder();
  cout << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *prev;
  Node(int val = NULL, Node *next = NULL, Node *prev = NULL)
  {
    this->val = val;
    this->next = next;
    this->prev = prev;
  }
};

class LinkedList
{
private:
  Node *_empty_node()
  {
    return new Node(-1);
  }
  void _handle_node_print(Node *curr)
  {
    if (!curr->next)
    {
      cout << "[" << curr->val << "] <- Tail\n";
      return;
    }

    if (curr == head)
      cout << "Head ->";

    cout << "[" << curr->val << "],";
  }

public:
  Node *head;
  Node *tail;
  int length;

  LinkedList(Node *head)
  {
    this->head = head;
    this->tail = head;
    length = 1;
  }

  void insert_at_the_beginning(int val)
  {
    Node *curr = head;
    Node *new_node = new Node(val, NULL);
    new_node->next = curr;
    curr->prev = new_node;
    head = new_node;
    ++length;
  }

  void insert_at_the_end(int val)
  {
    Node *new_node = new Node(val, NULL);
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
    ++length;
  }

  void insert_after(int before_val, int val)
  {
    Node *new_node = new Node(val, NULL);

    Node *before_node = find(before_val);

    Node *save = before_node->next;

    before_node->next = new_node;
    new_node->prev = before_node;
    new_node->next = save;
    save->prev = new_node;
    ++length;
  }

  void print_list()
  {
    Node *curr = head;
    if (!curr)
      cout << "[]\n";
    while (curr)
    {
      _handle_node_print(curr);
      curr = curr->next;
    }
  }

  void deallocate_list()
  {
    Node *curr = head;
    while (curr)
    {
      Node *temp = curr->next;
      delete curr;
      curr = temp;
    }
    length = 0;
    head = NULL;
    tail = NULL;
    cout << "---Memory freed successfully---\n";
  }

  Node *find(int val)
  {
    Node *curr = head;
    while (curr)
    {
      if (curr->val == val)
        return curr;
      curr = curr->next;
    }
    return nullptr;;
  }

  void delete_front()
  {
    Node *new_head = head->next;
    head->next = NULL;
    delete head;
    head = new_head;
    new_head->prev = NULL;
  }

  void delete_end()
  {
    if (!tail)
      return;

    Node *to_be_deleted = tail;

    tail = tail->prev;

    if (tail)
      tail->next = NULL;
    else
      head = NULL;

    delete to_be_deleted;
    --length;
  }

  void delete_node(int val)
  {

    insert_at_the_beginning(NULL);
    insert_at_the_end(NULL);

    Node *to_be_deleted = find(val);

    Node *to_be_del_prev = to_be_deleted ? to_be_deleted->prev : NULL;

    if (to_be_del_prev)
    {
      if (to_be_deleted->next)
      {
        to_be_del_prev->next = to_be_deleted->next;
        (to_be_deleted->next)->prev = to_be_del_prev;
        delete to_be_deleted;
      }
      else
        to_be_del_prev->next = NULL;
    }
    else
      delete to_be_deleted;
    delete_front();
    delete_end();
    --length;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  LinkedList list = LinkedList(new Node(2, NULL));

  list.insert_at_the_beginning(1);
  cout << "Before adding 3 to the end\n";
  list.print_list();

  list.insert_at_the_end(3);
  cout << "After adding 3 to the end\n";
  list.print_list();

  list.insert_after(2, 10);
  cout << "After adding 10 after 2\n";
  list.print_list();

  list.delete_node(10);
  cout << "After Deleting 10\n";
  list.print_list();

  list.deallocate_list();

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
  T val;
  Node<T> *next;
  Node<T> *prev;

  Node(T val = NULL, Node<T> *next = NULL, Node<T> *prev = NULL)
  {
    this->val = val;
    this->next = next;
    this->prev = prev;
  }
};

template <typename T>
class clsDblLinkedList
{
private:
  T _length;
  void _print_header()
  {
    cout << left;
    cout << setw(15) << "[Prev]" << setw(15) << "[Current]" << setw(15) << "[Next]" << "\n\n";
  }

  void _handle_node_print(Node<T> *curr)
  {
    cout << left;

    string prev_str = (curr->prev) ? "[" + to_string(curr->prev->val) + "]" : "[NULL]";
    cout << setw(15) << prev_str;

    string curr_str = "[" + to_string(curr->val) + "]";
    cout << setw(15) << curr_str;

    string next_str = (curr->next) ? "[" + to_string(curr->next->val) + "]" : "[NULL]";
    cout << setw(15) << next_str;

    cout << endl;
  }

  void _handle_node_print_next_path(Node<T> *curr)
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

  void _handle_node_print_prev_path(Node<T> *curr)
  {
    if (!curr->prev)
    {
      cout << "[" << curr->val << "] <- Head\n";
      return;
    }

    if (curr == tail)
      cout << "Tail ->";

    cout << "[" << curr->val << "],";
  }

  void _DeallocateList()
  {
    while (_length > 0)
      DeleteFirstNode();
  }

public:
  Node<T> *head;
  Node<T> *tail;

  clsDblLinkedList(Node<T> *head)
  {
    this->head = head;
    this->tail = head;
    if (head)
      _length = 1;
    else
      _length = 0;
  }

  ~clsDblLinkedList()
  {
    _DeallocateList();
    cout << "---Memory freed successfully---\n";
  }

  void InsertAtBeginning(T val)
  {
    Node<T> *curr = head;
    Node<T> *new_node = new Node<T>(val, NULL);
    new_node->next = curr;
    if (curr)
      curr->prev = new_node;

    head = new_node;
    ++_length;
  }

  void InsertAtEnd(T val)
  {
    Node<T> *new_node = new Node<T>(val, NULL);
    if (tail)
      tail->next = new_node;
    else
    {
      tail = new_node;
      head = new_node;
    }

    new_node->prev = tail;
    tail = new_node;
    ++_length;
  }

  void InsertAfter(T before_val, T val)
  {
    Node<T> *new_node = new Node<T>(val, NULL);

    Node<T> *before_node = Find(before_val);

    Node<T> *save = before_node->next;

    if (before_node)
      before_node->next = new_node;
    else
      head = new_node;
    new_node->prev = before_node;
    new_node->next = save;

    if (save)
      save->prev = new_node;
    else
      tail = new_node;

    ++_length;
  }

  void PrintList()
  {
    Node<T> *curr = head;
    if (!curr)
      cout << "[]\n";
    _print_header();
    while (curr)
    {
      _handle_node_print(curr);
      curr = curr->next;
    }
  }

  void DebugPrintNextPath()
  {
    Node<T> *curr = head;
    if (!curr)
      cout << "[]\n";
    cout << endl;
    while (curr)
    {
      _handle_node_print_next_path(curr);
      curr = curr->next;
    }
    cout << endl;
  }

  void DebugPrintPrevPath()
  {
    Node<T> *curr = tail;
    if (!curr)
      cout << "[]\n";
    cout << endl;
    while (curr)
    {
      _handle_node_print_prev_path(curr);
      curr = curr->prev;
    }
    cout << endl;
  }

  Node<T> *Find(T val)
  {
    Node<T> *curr = head;
    while (curr)
    {
      if (curr->val == val)
        return curr;
      curr = curr->next;
    }
    return nullptr;
    ;
  }

  void DeleteFirstNode()
  {
    if (!head)
      return;
    Node<T> *new_head = head->next;
    head->next = NULL;
    delete head;
    head = new_head;
    if (new_head)
      new_head->prev = NULL;

    --_length;
  }

  void DeleteLastNode()
  {
    if (!tail)
      return;

    Node<T> *to_be_deleted = tail;

    tail = tail->prev;

    if (tail)
      tail->next = NULL;
    else
      head = NULL;

    delete to_be_deleted;
    --_length;
  }

  void DeleteNode(T val)
  {

    InsertAtBeginning(NULL);
    InsertAtEnd(NULL);

    Node<T> *to_be_deleted = Find(val);

    Node<T> *to_be_del_prev = to_be_deleted ? to_be_deleted->prev : NULL;

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
    DeleteFirstNode();
    DeleteLastNode();
    --_length;
  }
  int Size()
  {
    return _length;
  }

  bool IsEmpty()
  {
    return !_length;
  }

  void Clear()
  {
    _DeallocateList();
  }

  void Reverse()
  {
    if (_length < 2)
      return;
    Node<T> *curr = head, *save_next, *save_prev;
    while (curr)
    {
      save_next = curr->next;

      if (!save_next)
        head = curr;
      if (!curr->prev)
        tail = curr;

      curr->next = curr->prev;
      curr->prev = save_next;

      curr = save_next;
    }
  }

  Node<T>* GetNode(int idx) {
    if (idx >= _length || idx < 0)
      return NULL;
    
    Node<T> *curr = head;
    while (idx--)
      curr = curr->next;
    return curr;
  }

  T GetItem(int idx) {
    Node<T>* node = GetNode(idx);
    if (!node)
      return NULL;
    
    return node->val;
  }
};
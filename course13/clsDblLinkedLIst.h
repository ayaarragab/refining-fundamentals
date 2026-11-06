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
  void _handle_node_print(Node<T> *curr)
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
    if (curr && curr->prev)
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
    while (curr)
    {
      _handle_node_print(curr);
      curr = curr->next;
    }
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

  void Reverse() {
    Node<T>* prev_tail = tail->prev;
    Node<T>* head_next = head->next;

    tail->next = prev_tail;
    prev_tail->prev = tail;
    tail->prev = NULL;

    head->prev = head_next;
    head_next->next = head;
    head->next = NULL;

    Node<T>* temp = head;
    head = tail;
    tail = temp;
  }
};
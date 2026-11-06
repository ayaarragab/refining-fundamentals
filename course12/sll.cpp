#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val = NULL, Node *next = NULL)
    {
        this->val = val;
        this->next = next;
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
        head = new_node;
        ++length;
    }

    void insert_at_the_end(int val)
    {
        Node *new_node = new Node(val, NULL);
        tail->next = new_node;
        tail = new_node;
        ++length;
    }

    void insert_after(int before_val, int val) {
        Node *new_node = new Node(val, NULL);

        Node *before_node = find(before_val);
        Node *save = before_node->next;
        
        before_node->next = new_node;
        new_node->next = save;
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
        return _empty_node();
    }

    void delete_front() {
        Node* new_head = head->next;
        head->next = NULL;
        delete head;
        head = new_head;
    }

    void delete_end() {
        Node *new_tail = head;
        
        while (new_tail->next != tail)
            new_tail = new_tail->next;
        

        new_tail->next = NULL;
        delete tail;
        tail = new_tail;
    }

    void delete_node(int val) {
        
        insert_at_the_beginning(NULL);
        insert_at_the_end(NULL);

        Node* before_node = head;

        while (before_node && before_node->next && before_node->next->val != val)
            before_node = before_node->next;
        
        if (before_node->next)
        {
            if (before_node->next->next)
            {
                Node *to_be_deleted = before_node->next;
                before_node->next = before_node->next->next;
                delete to_be_deleted;
            }
        }
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

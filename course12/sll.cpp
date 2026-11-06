#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node(int val, Node* next) {
            this->val = val;
            this->next =next;
        }
};

void insert_at_the_beginning(Node *head, int val) {
    Node *curr = head;
    Node *new_node = new Node(val, NULL);
    curr->next = new_node;
    head = new_node;
}

void print_list(Node *head) {
    Node *curr = head;
    while (curr)
    {
        if (!curr->next)
        {
            cout << "[" << curr->val << "]\n"; 
            return;
        }
        cout << "[" << curr->val << "], "; 
        curr = curr->next;
    }
}

void deallocate_list(Node *head) {
    Node *curr = head;
    while (curr)
    {
        Node *temp = curr->next;
        delete curr;
        curr = temp;
    }
    cout << "---Memory freed successfully---\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Node *head = new Node(1, NULL);
    insert_at_the_beginning(head, 2);
    print_list(head);
    deallocate_list(head);
    return 0;
}

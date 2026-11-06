#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node* next;
        Node(int val, Node* next = NULL) {
            this->val = val;
            this->next =next;
        }
};

class LinkedList {
    public:
        Node *head;
        int length;
        
        LinkedList(Node *head) {
            this->head = head;
            length = 1;
        }

        void insert_at_the_beginning(int val) {
            Node *curr = head;
            Node *new_node = new Node(val, NULL);
            new_node->next = curr;
            head = new_node;
            ++length;
        }

        void print_list() {
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

        void deallocate_list() {
            Node *curr = head;
            while (curr)
            {
                Node *temp = curr->next;
                delete curr;
                curr = temp;
            }
            cout << "---Memory freed successfully---\n";
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LinkedList list = LinkedList(new Node(1, NULL));

    list.insert_at_the_beginning(2);
    list.print_list();
    list.deallocate_list();
    return 0;
}

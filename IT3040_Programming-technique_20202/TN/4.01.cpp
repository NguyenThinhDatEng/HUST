#include <iostream> 
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node* prepend(Node* head, int data) {
    Node* q = new Node(data);
    if (head == nullptr)
        return q;
    q->next = head;
    return q;
}

// print the list content on a line
void print(Node* head) {
    if (head == nullptr)
        return;
    Node* p = head;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// return the new head of the reversed list
Node* reverse(Node* head) {
    if (head == nullptr)
        return head;
    Node* q = NULL;
    Node* p = head;
    while (p != nullptr)
    {
        q = prepend(q, p->data);
        p = p->next;
    }
    return q;
}

int main() {
    cout << "\nNguyen Van Thinh 20194178\n" << endl;
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i) {
        cin >> u;
        head = prepend(head, u);
    }

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}
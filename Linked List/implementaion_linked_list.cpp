#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert at head
void insertAtHead(node* &head, int d) {
    node* temp = new node(d);
    temp->next = head;
    head = temp;
}

// Insert at tail
void insertAtTail(node* &head, int d) {
    node* temp = new node(d);
    if (head == NULL) {
        head = temp;
        return;
    }
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

// Insert at middle (after a given position)
void insertAtMiddle(node* &head, int position, int d) {
    if (position == 0) {
        insertAtHead(head, d);
        return;
    }
    node* temp = head;
    int count = 0;
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Position out of range" << endl;
        return;
    }
    node* newNode = new node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at head
void deleteAtHead(node* &head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
}

// Delete at tail
void deleteAtTail(node* &head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    delete current->next;
    current->next = NULL;
}

// Delete at middle (given position)
void deleteAtMiddle(node* &head, int position) {
    if (position == 0) {
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    int count = 0;
    while (count < position - 1 && temp != NULL && temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range" << endl;
        return;
    }
    node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Print nodes
void printNode(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* node1 = new node(10);
    node* head = node1;

    printNode(head);

    insertAtHead(head, 12);
    printNode(head);

    insertAtTail(head, 15);
    printNode(head);

    insertAtMiddle(head, 1, 20); // Insert at position 1
    printNode(head);

    deleteAtHead(head);
    printNode(head);

    deleteAtTail(head);
    printNode(head);

    deleteAtMiddle(head, 1); // Delete at position 1
    printNode(head);

    return 0;
}

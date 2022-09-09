#include <iostream>
using namespace std;

class Node {
    
    public:
        int data;
        Node* nextNode;

    public:
    Node() {
        this->data = 0;
        this->nextNode = 0;
    }

    Node(int data) {
        this->data = data;
        this->nextNode = 0;
    }
};


class LinkedList {
    public:
        Node* head;
        int len;
    
    // public: 
    //     int __ERROR_LINE_NUMBER__ = 0;

    public:
    LinkedList() {
        this->head = NULL;
        this->len = 0;
    }
    
    int length() {
        return this->len; 
    }

    // INSERT a new node AT-END of the Linked List via REFRENCE
    void insertNode(Node& newNode) {
        //  If the head node is null then the list is empty and new node must be inserted at head node 
        if(!this->head) {
            this->head = &newNode;
            this->len++;
            return;
        }

        // If head exists then traverse the list to find the last node and insert a new Node after that 
        Node* currNode = this->head;
        while (currNode)
        {
            if(!currNode->nextNode) {
                currNode->nextNode = &newNode;
                this->len++;
                return;
            }
            currNode = currNode->nextNode;
        }    
    }

    // INSERT a new node AT-END of the Linked List via POINTER
    void insertNode(Node* newNode) {
        //  If the head node is null then the list is empty and head node is updated  
        if(!this->head) {
            this->head = newNode;
            this->len++;
            return;
        }

        // If head exists then traverse the list to find the last node and insert a new Node after that 
        Node* currNode = this->head;
        while (currNode)
        {
            if(!currNode->nextNode) {
                currNode->nextNode = newNode;
                this->len++;
                return;
            }
            currNode = currNode->nextNode;
        }
    }

    // INSERT a new node AT-CUSTOM-INDEX in the Linked List via REFRENCE
    void insertNode(Node& newNode, int index) {
        // Check if index is within the bounds of the Linked List
        if (index > this->len || index < 0) {
            cout << "At Line " << __LINE__ << "[ERROR] : Index out of bounds" << endl;
            exit(EXIT_FAILURE);
            return;
        }

        // INSERT a node at the head-node or AT-HEAD-INDEX of Linked List
        if (index == 0) {
            newNode.nextNode = this->head;
            this->head = &newNode;
            this->len++;
            return;
        }

        // INSERT a node at the tail node or AT-END-INDEX of Linked List
        if (index == this->len) {
            insertNode(newNode);
            return;
        }
        
        // INSERT a new node IN-BETWEEN the Linked List 
        Node* currNode = this->head;
        Node* prevNode;
        for (int i = 0; i < index; i++)
        {
            prevNode = currNode;
            currNode = currNode->nextNode;
        }
        prevNode->nextNode = &newNode;
        newNode.nextNode = currNode;
        this->len++;
        return;
    }
    
    // INSERT a new node AT-CUSTOM-INDEX in the Linked List via POINTER
    void insertNode(Node* newNode, int index) {
        // Check if index is within the bounds of the Linked List
        if (index > this->len || index < 0) {
            cout << "At Line " << __LINE__ << "[ERROR] : Index out of bounds" << endl;
            exit(EXIT_FAILURE);
            return;
        }

        // INSERT a node at the head-node or AT-HEAD-INDEX of Linked List
        if (index == 0) {
            newNode->nextNode = this->head;
            this->head = newNode;
            this->len++;
            return;
        }

        // INSERT a node at the tail node or AT-END-INDEX of Linked List
        if (index == this->len) {
            insertNode(newNode);
            return;
        }
        
        // INSERT a new node IN-BETWEEN the Linked List 
        Node* currNode = this->head;
        Node* prevNode;
        for (int i = 0; i < index; i++)
        {
            prevNode = currNode;
            currNode = currNode->nextNode;
        }
        prevNode->nextNode = newNode;
        newNode->nextNode = currNode;
        this->len++;
        return;
    }
    
    // DELETE an existing node AT-CUSTOM-INDEX of the Linked List
    void deleteNode(int index) {
        // Check if index is within the bounds of the Linked List
        if (index > this->len - 1 || index < 0) {
            // cout << "At Line " << line << endl;
            cout << "[ERROR] : Index out of bounds" << endl;
            exit(EXIT_FAILURE);
            return;
        }
        // DELETE an existing node AT-HEAD of the Linked List
        if (index == 0) {
            this->head = this->head->nextNode;
            this->len--;
        }
    }
};


// Overloading << to print a Node Instance
ostream& operator<< (ostream& os, Node& node) { 
    os << "Data = " << node.data << " , Address = " << &node << " , Points to = " << node.nextNode;
    return os;
}


// Overloading << to print a Linked List Instance
ostream& operator<< (ostream& os, LinkedList& linkedList) { 
    Node* tempNode = linkedList.head;
    if (!tempNode) {
        os << "Linked List is empty" << endl;
    }
    while (tempNode)
    {
        os << *tempNode << endl;
        tempNode = tempNode->nextNode;
    }
    os << "Length of list : " << linkedList.len; 
    return os;
}


int main() {
    LinkedList newList;
    
    Node node1 = 1;
    Node* node2 = new Node(2);
    Node node3 = 3;


    newList.insertNode(node1);
    newList.insertNode(node2);
    newList.insertNode(node3);

    
    cout << "LINKED LIST" << endl;
    cout << newList << endl;

    delete node2;
    // cout << newList.len << endl;

    return 0;
}
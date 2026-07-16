/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {

private:

    void InsertAtTail(Node* &head, Node* &tail, int d) {

        Node* newNode = new Node(d);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:

    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        // STEP 1: Create clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while(temp != NULL) {
            InsertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        // STEP 2: Insert clone nodes between original nodes
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next;
            next = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next;
        }
        // STEP 3: Copy random pointers
        temp = head;
        while(temp != NULL) {
            if(temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        // STEP 4: Separate both lists
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;
            if(originalNode != NULL) {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};
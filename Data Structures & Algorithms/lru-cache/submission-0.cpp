class Node {
public:

    int key;
    int val;

    Node* next;
    Node* prev;

    Node(int k, int v) {

        key = k;
        val = v;

        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:

    unordered_map<int, Node*> m;

    int limit;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {

        limit = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Add node right after head
    void addNode(Node* newNode) {

        Node* oldNext = head->next;

        head->next = newNode;

        newNode->prev = head;

        newNode->next = oldNext;

        oldNext->prev = newNode;
    }

    // Delete node from DLL
    void delNode(Node* oldNode) {

        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;

        oldNext->prev = oldPrev;
    }

    int get(int key) {

        if(m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];

        int ans = ansNode->val;

        // Move node to front (most recently used)
        delNode(ansNode);

        addNode(ansNode);

        return ans;
    }

    void put(int key, int value) {

        // Key already exists
        if(m.find(key) != m.end()) {

            Node* oldNode = m[key];

            delNode(oldNode);

            m.erase(key);
        }
        // Cache full
        if(m.size() == limit) {
            Node* lru = tail->prev;
            m.erase(lru->key);
            delNode(lru);
        }

        Node* newNode = new Node(key, value);

        addNode(newNode);

        m[key] = newNode;
    }
};
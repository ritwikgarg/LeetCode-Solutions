class LRUCache {
public:
    LRUCache(int capacity): head(-1, -1), tail(-1, -1), capacity(capacity) {
        head.next = &tail;   
        tail.prev = &head;
        mp.clear();
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) { // Key already exists in cache
            Node* existingNode = mp[key]; 

            detachNode(existingNode);
            addNodeAfterHead(existingNode);

            return existingNode->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (mp.find(key) != mp.end()) { // Key already exists in cache
            Node* existingNode = mp[key]; 
            // Update the value
            existingNode->value = value; 
            detachNode(existingNode);
            addNodeAfterHead(existingNode);
        } else {
            if (mp.size() == capacity) {
                // Cache has exceeded maximum capacity -> need to delete last node (before tail)
                Node* lru = tail.prev;
                detachNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            addNodeAfterHead(newNode);
            mp.insert({key, newNode});
        }
    }

private:
    struct Node {
        Node* prev;
        Node* next;
        int key;
        int value;

        Node() : prev(nullptr), next(nullptr), key(0), value(0) {}
        Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    void detachNode(Node* existingNode) {
        if(existingNode->prev && existingNode->next) { // Making sure they are not null ptrs
            // Rewire prev and next of existing node
            Node* prevNode = existingNode->prev; 
            Node* nextNode = existingNode->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }

    }

    void addNodeAfterHead(Node* newNode) {
        // Move new node to be after head
        Node* oldNextOfHead = head.next; 
        newNode->next = oldNextOfHead;
        newNode->prev = &head;

        // Reassign next ptr of head to point to new node
        head.next = newNode; 

        // Reassign prev ptr of oldNextOfHead to point to new node
        oldNextOfHead->prev = newNode;
    }

    Node head;
    Node tail;

    int capacity;
    unordered_map <int, Node*> mp; // Stores key -> node
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
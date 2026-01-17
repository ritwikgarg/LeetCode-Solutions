class LFUCache {
public:
    LFUCache(int capacity): capacity(capacity), minFreq(0), totalSize(0) {
        
    }
    
    int get(int key) {
        if(nodeMap.find(key) != nodeMap.end()) { // Node exists in the cache
            Node* existingNode = nodeMap[key];
            int currFreq = existingNode->freq;

            DLL& currDLL = freqMap[currFreq];
            increaseNodeFreq(currDLL, existingNode);

            // Return the value
            return existingNode->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (nodeMap.find(key) != nodeMap.end()) { // Key already exists in the cache
            Node* existingNode = nodeMap[key];

            int currFreq = existingNode->freq;
            DLL& currDLL = freqMap[currFreq];

            existingNode->value = value; // Update the value

            increaseNodeFreq(currDLL, existingNode);
        } else { // Cache is full
            if (totalSize == capacity) {
                // Remove the LFU node, if 2 or more LFU nodes, remove the LRU node among them
                DLL& minFreqDLL = freqMap[minFreq];
                Node* lfuNode = minFreqDLL.tail.prev;
                detachNode(minFreqDLL, lfuNode);

                // Remove node from nodeMap;
                nodeMap.erase(lfuNode->key);

                delete lfuNode;
            } else {
                totalSize++;
            }

            Node* newNode = new Node(key, value);
            // Add new node into nodeMap
            nodeMap[key] = newNode;
            
            // Add new node to freq=1 DLL
            minFreq = 1;
            DLL& minFreqDLL = freqMap[minFreq];
            addNodeAfterHead(minFreqDLL, newNode);
        }
    }

private:
    struct Node {
        int key;
        int value;
        int freq;
        Node* next;
        Node* prev;

        Node(): key(-1), value(-1), freq(0), next(nullptr), prev(nullptr) {}
        Node(int k, int v): key(k), value(v), freq(1), next(nullptr), prev(nullptr) {}
    };

    struct DLL {
        Node head;
        Node tail;
        int size;

        DLL(): size(0) {
            head.next = &tail;
            tail.prev = &head;
        }
    };

    void detachNode(DLL& dll, Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        dll.size--;
    }

    void addNodeAfterHead(DLL& dll, Node* node) {
        Node* oldNextOfHead = dll.head.next;

        // Next of head points to node, prev of node points to head
        dll.head.next = node; 
        node->prev = &dll.head;

        // Next of node points to oldNextOfHead, prev of oldNextOfHead points to node
        oldNextOfHead->prev = node;
        node->next = oldNextOfHead;

        dll.size++;
    }

    void increaseNodeFreq(DLL& currDLL, Node* existingNode) {
        // 1) Detach the node from the current freq DLL
        detachNode(currDLL, existingNode);

        // 2) Add the node into the next freq DLL, right after head
        int currFreq = existingNode->freq;
        DLL& nextDLL = freqMap[currFreq+1]; //Creates new DLL if it doesn't already exist
        existingNode->freq++;
        addNodeAfterHead(nextDLL, existingNode);

        // 3) Update minFreq if required
        if(currFreq == minFreq && currDLL.size == 0) {
            freqMap.erase(minFreq);
            minFreq++;
        }
    }

    int minFreq;
    int totalSize;
    int capacity;
    unordered_map <int, DLL> freqMap; // Stores a DLL for each frequency 
    unordered_map <int, Node*> nodeMap; // Stores all the nodes across all frequencies
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
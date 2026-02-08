class LFUCache {
public:
    LFUCache(int capacity): size(0), capacity(capacity), minFreq(0) {
        
    }
    
    int get(int key) {
        if (nodeMap.find(key) == nodeMap.end()) {
            return -1;
        }

        Node* node = nodeMap[key];
        int currFreq = node->freq;
        node->freq = currFreq+1;

        detachNode(currFreq, node);  
        attachNodeAfterHead(currFreq+1, node);

        if (currFreq == minFreq && freqMap.find(currFreq) == freqMap.end()) {
            minFreq = currFreq + 1;
        }

        return node->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (nodeMap.find(key) == nodeMap.end()) {
            if (size == capacity) {
                removeMinFreqNode();
                size--;
            }
            Node* newNode = new Node(key, value);
            attachNodeAfterHead(1, newNode);
            nodeMap[key] = newNode;
            minFreq = 1;
            size++; 
        } else {
            Node* node = nodeMap[key];
            node->value = value;

            int currFreq = node->freq;
            node->freq = currFreq+1;

            detachNode(currFreq, node);
            attachNodeAfterHead(currFreq+1, node);   
            if (currFreq == minFreq && freqMap.find(currFreq) == freqMap.end()) {
                minFreq = currFreq + 1;
            }         
        }
    }
private:
    struct Node {
        Node* next;
        Node* prev;

        int key;
        int value;
        int freq;
        Node() {
            next = nullptr;
            prev = nullptr;
        }
        Node (int k, int v) {
            freq = 1;
            key = k;
            value = v;
            next = nullptr;
            prev = nullptr;
        }
    };
    int size;
    int capacity;
    int minFreq;
    unordered_map <int, Node*> nodeMap;

    struct DLL {
        Node head;
        Node tail;
        int size;

        DLL() {
            head.next = &tail;
            tail.prev = &head;
            head.prev = nullptr;
            tail.next = nullptr;
            size = 0;
        }
    };

    unordered_map <int, DLL> freqMap;

    void attachNodeAfterHead(int freq, Node* node) {
        DLL& currDLL = freqMap[freq];
        currDLL.size++;

        Node* oldNext = currDLL.head.next;

        currDLL.head.next = node;
        node->next = oldNext;

        oldNext->prev = node;
        node->prev = &currDLL.head;
    }

    void detachNode(int freq, Node* node) {
        DLL& oldDLL = freqMap[freq];

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        node->next = nullptr;
        node->prev = nullptr;

        oldDLL.size--;
        if (oldDLL.size == 0) {
            freqMap.erase(freq);
        }
    }

    void removeMinFreqNode() {
        DLL& minFreqDLL = freqMap[minFreq];
        Node* lastNode = minFreqDLL.tail.prev;
        detachNode(minFreq, lastNode);
        nodeMap.erase(lastNode->key);
        delete lastNode;

        if (nodeMap.empty()) {
            minFreq = 0;
            return;
        }

        // If minFreq list got erased, advance to next existing freq
        if (freqMap.find(minFreq) == freqMap.end()) {
            int f = minFreq + 1;
            while (freqMap.find(f) == freqMap.end()) f++;
            minFreq = f;
        }

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
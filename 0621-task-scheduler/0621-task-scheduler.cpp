class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freqMap;
        priority_queue<int> maxHeap; 

        int size = tasks.size();

        for (int i=0; i<size; i++) {
            freqMap[tasks[i]]++;
        }

        int time = 0;

        for (auto it: freqMap) {
            maxHeap.push(it.second);
        }

        while (!maxHeap.empty()) {

            vector<int> temp;
            for (int i=1; i<=n+1; i++) {
                
                if (!maxHeap.empty()) {
                    int freq = maxHeap.top();
                    maxHeap.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for (int &f : temp) {
                if (f > 0) {
                    maxHeap.push(f);
                }
            }

            if (maxHeap.empty()) {
                time += temp.size();
            } else {
                time += n+1;
            }
        }
        return time;
    }
};
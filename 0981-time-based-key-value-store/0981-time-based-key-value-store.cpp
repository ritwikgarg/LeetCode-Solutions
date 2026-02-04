class TimeMap {
public:
TimeMap() {
    
}

void set(string key, string value, int timestamp) {
    pair<string, int> p = {value, timestamp};
    timeMap[key].push_back(p);
}

string get(string key, int timestamp) {
    if (timeMap.find(key) == timeMap.end()) {
        return "";
    }

    auto &values = timeMap[key];
    int n = values.size();
    int low = 0;
    int high = n-1;
    string ans;
    while (low <= high) {
        int mid = low + (high-low)/2;

        if (values[mid].second <= timestamp) {
            low = mid+1;
            ans = values[mid].first;
        }
        else {
            high = mid-1;
        }
    }
    return ans;
}

private:
unordered_map <string, vector<pair<string, int>>> timeMap;
};

/**
* Your TimeMap object will be instantiated and called as such:
* TimeMap* obj = new TimeMap();
* obj->set(key,value,timestamp);
* string param_2 = obj->get(key,timestamp);
*/
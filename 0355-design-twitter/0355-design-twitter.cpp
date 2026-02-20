struct PostItem {
    int index;;
    int timestamp;
    int userId;

    PostItem() : index(-1), timestamp(-1), userId(-1) {}

    PostItem(int index, int timestamp, int userId) {
        this->index = index;
        this->timestamp = timestamp;
        this->userId = userId;
    }
};

class compare {
public:
    bool operator()(PostItem* a, PostItem* b) {
        return a->timestamp < b->timestamp;
    }
};

class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        followingMap[userId].insert(userId);
        userPostsMap[userId].push_back({timestamp, tweetId});
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> &following = followingMap[userId];
        priority_queue<PostItem*, vector<PostItem*>, compare> maxHeap;

        // initialize the heap;
        for (auto &f : following) {
            vector<pair<int, int>>& userPosts = userPostsMap[f];
            if (!userPosts.empty()) {
                int lastIndex = userPosts.size() - 1;
                maxHeap.push(new PostItem(lastIndex, userPosts[lastIndex].first, f));
            }
        }

        vector<int> feed;
        while(!maxHeap.empty() && feed.size() < 10) {
            PostItem* post = maxHeap.top();
            maxHeap.pop();   
            feed.push_back(userPostsMap[post->userId][post->index].second);

            int nextIndex = post->index - 1;
            if (nextIndex >= 0) {
                maxHeap.push(new PostItem(nextIndex, userPostsMap[post->userId][nextIndex].first, post->userId));
            }

            delete post; 
        }

        while (!maxHeap.empty()) {
            delete maxHeap.top();
            maxHeap.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followingMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followingMap[followerId].erase(followeeId);
    }

private:
    unordered_map <int, unordered_set<int>> followingMap;
    unordered_map <int, vector<pair<int,int>>> userPostsMap; // Each element in the vector is a (timestamp, tweetId) pair
    int timestamp = 0; 
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
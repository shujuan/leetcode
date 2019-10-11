struct Tweet{
    int t;
    int id;
    Tweet(int time, int index) {
        t = time;
        id = index;
    }
    bool operator <(const Tweet& b) const{
        return t >b.t;
    }
};



class Twitter {
    
    unordered_map<int, unordered_set<int>>followingList;
    unordered_map<int, vector<Tweet>>tweetList;
    int time;
    
public:
    /** Initialize your data structure here. */
    Twitter() :time(0){
        followingList.clear();
        tweetList.clear();
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(!tweetList.count(userId)) {
           tweetList[userId] = vector<Tweet>();
        }
        time++;
        tweetList[userId].push_back(Tweet(time, tweetId));
        
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<Tweet>tweetFeed = tweetList.count(userId) ? getTen(tweetList[userId]) : vector<Tweet>();
        for(auto user : followingList[userId]) {
            if(tweetList.count(user)) {
                vector<Tweet>tmp = getTen(tweetList[user]);
                tweetFeed.insert(tweetFeed.end(), tmp.begin(), tmp.end());
            }
        }
        sort(tweetFeed.begin(), tweetFeed.end());
        vector<int>res;
        
        for(int i=0; i<tweetFeed.size(); i++) {
            if(i==10) break;
            res.push_back(tweetFeed[i].id);
        }
        return res;
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        if(!followingList.count(followerId))
            followingList[followerId] = unordered_set<int>();
        followingList[followerId].insert(followeeId);
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        
        if(!followingList.count(followerId))
            return;
        followingList[followerId].erase(followeeId);
           
    }
    
    
    vector<Tweet> getTen(vector<Tweet>& tweets) {
        int cnt =0;
        int n = tweets.size();
        vector<Tweet>res;
        for(int i=n-1; i>=0; i--) {
            if(cnt == 10) break;
            cnt++;
            res.push_back(tweets[i]);  
        }
        return res;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
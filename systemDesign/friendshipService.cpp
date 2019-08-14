class FriendshipService {
    unordered_map<int, set<int>>followers;
    unordered_map<int, set<int>> following;
    
public:
    FriendshipService() {
        // do intialization if necessary
    }

    /*
     * @param user_id: An integer
     * @return: all followers and sort by user_id
     */
    vector<int> getFollowers(int user_id) {
        // write your code here
        return vector<int>(followers[user_id].begin(), followers[user_id].end());
    }

    /*
     * @param user_id: An integer
     * @return: all followings and sort by user_id
     */
    vector<int> getFollowings(int user_id) {
        // write your code here
        return vector<int>(following[user_id].begin(), following[user_id].end()) ;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int to_user_id, int from_user_id) {
        // write your code here
        followers[to_user_id].insert(from_user_id);
        following[from_user_id].insert(to_user_id);
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int to_user_id, int from_user_id) {
        // write your code here
        followers[to_user_id].erase(from_user_id);
        following[from_user_id].erase(to_user_id);
        
    }
};

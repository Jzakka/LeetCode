class Twitter {
private:
    struct Feed{
        int id;
        int writerId;

        Feed(int id, int writerId):id(id), writerId(writerId){}
    };

    vector<Feed> feeds;
    unordered_map<int, unordered_set<int>> followings;
public:
    Twitter() {
        for (int i = 1; i <= 500; i++) {
            follow(i, i);
        }
    }

    void postTweet(int userId, int tweetId) {
        feeds.push_back(Feed(tweetId, userId));
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> news;
        for (auto it = feeds.rbegin(); it != feeds.rend(); it++) {
            auto feed = *it;
            if (followings[userId].find(feed.writerId) != followings[userId].end()) {
                news.push_back(feed.id);
                if (news.size() == 10) {
                    break;
                }
            }
        }
        return news;
    }

    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};

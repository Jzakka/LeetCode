class Solution {
public:
    map<string, set<string>> edges;
    unordered_map<string, int> edgeVisited;
    int ticketCount;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ticketCount = tickets.size();

        for (const auto &ticket: tickets) {
            auto src = ticket.front();
            auto dest = ticket.back();

            edges[src].insert(dest);
            edgeVisited[src + dest]++;
        }

        vector<string> itinerary;
        dfs(itinerary, "JFK");

        return itinerary;
    }

    bool dfs(vector<string>& itinerary, string src){
        itinerary.push_back(src);
        if (!ticketCount) {
            return true;
        }

        for (const auto &nextHop: edges[src]){
            if(!visited(src,nextHop)){

                visit(src, nextHop);

                if (dfs(itinerary, nextHop)) {
                    return true;
                }

                visitRollBack(src, nextHop);

            }
        }

        itinerary.pop_back();
        return false;
    }

    bool visited(string src, string dest){
        return edgeVisited[src + dest] == 0;
    }

    void visit(string src, string dest){
        ticketCount--;
        edgeVisited[src + dest]--;
    }

    void visitRollBack(string src, string dest){
        ticketCount++;
        edgeVisited[src + dest]++;
    }
};
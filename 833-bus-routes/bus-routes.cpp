class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source == target) return 0;

        unordered_map<int, vector<int>> adj;
        int n = routes.size();

        for(int route=0; route < n; route++){
            for(auto &stops : routes[route]){
                adj[stops].push_back(route);
            }
        }

        queue<int> q;
        unordered_set<int> visitedBuses;

        for(int bus : adj[source]){
            q.push(bus);
            visitedBuses.insert(bus);
        }

        int busCount = 1;

        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                int curBus = q.front(); q.pop();
                
                for(int stop: routes[curBus]){
                    if(stop == target) return busCount;

                    for (int nextBus: adj[stop]){
                        if(!visitedBuses.count(nextBus)){
                            q.push(nextBus);
                            visitedBuses.insert(nextBus);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};
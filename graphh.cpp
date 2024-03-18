#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int minSubwayLines(int n, int m, vector<vector<pair<int, int>>> &adjList, int b, int e) {
    vector<int> visited(n + 1, 0); // 0 for not visited, 1 for visited
    queue<int> q;
    q.push(b);
    visited[b] = 1;
    unordered_map<int, unordered_set<int>> colorMap;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == e) return 0; // if destination found, no subway lines needed

        for (auto &[v, color] : adjList[u]) {
            colorMap[color].insert(u); // map stations with the same color
            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    int minLines = INT_MAX;

    for (auto &[color, stations] : colorMap) {
        bool found = false;
        for (int station : stations) {
            for (auto &[v, _] : adjList[station]) {
                if (visited[v]) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) minLines = min(minLines, (int)stations.size());
    }

    return minLines;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<pair<int, int>>> adjList(n + 1);

        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            adjList[u].push_back({v, c});
            adjList[v].push_back({u, c});
        }

        int b, e;
        cin >> b >> e;

        int minLines = minSubwayLines(n, m, adjList, b, e);
        cout << minLines << endl;
    }

    return 0;
}

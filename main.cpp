#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define MAX_NK 100005
#define MAX_M 500005
#define MAX_P 100000009

using namespace std;

int N, M, K;
bool DEBUG = false;

vector<int> incoming[MAX_M];
vector<int> outcoming[MAX_M];
vector<pair<long long, int>> pro_needed_with_prj;
long long pro_needed[MAX_NK];
set<int> not_visited;
int is_visited[MAX_NK];
vector<long long> sorted_prj;

void read_input() {
    int left, right;
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &pro_needed[i]);
        pro_needed_with_prj.push_back(make_pair(pro_needed[i], i));
    }
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &left, &right);
        //incoming[left].push_back(right);
        outcoming[right].push_back(left);
    }
}

void visit(int node) {
    if (is_visited[node] == 0) {
        for (int m : outcoming[node]) {
            visit(m);
        }
        is_visited[node] = 1;
        //not_visited.erase(node);
        sorted_prj.push_back(pro_needed[node]);
    }
}

void topo_sort() {
    sort(pro_needed_with_prj.rbegin(), pro_needed_with_prj.rend());
    for (int i = 0; i < N; i++) {
        visit(pro_needed_with_prj[i].second);
    }
    if (DEBUG) {
        cout << "Dd";
    }

    //reverse(sorted_prj.begin(), sorted_prj.end());
}

/*void topo_sort() {
    vector<int> no_inc_edges;
    if (DEBUG) {
        cout << "Nodes with no incoming edges: ";
    }
    for (int i = 1; i <= N; i++) {
        if (incoming[i].empty()) {
            if (DEBUG) {
                cout << i << " ";
            }
            no_inc_edges.push_back(i);
        }
    }
    if (DEBUG) {
        cout << endl;
    }

    int n;
    while (!no_inc_edges.empty()) {
        n = no_inc_edges.back();
        no_inc_edges.pop_back();
        sorted_prj.push_back(n);
        for (vector<int>::iterator m_it = outcoming[n].begin();
             m_it < outcoming[n].end(); m_it++) {
            outcoming[n].erase(m_it);
            incoming[m]
        }
    }
}*/

int main() {

    read_input();
    topo_sort();
    long long result = *(max_element(sorted_prj.begin() + N - K,
                                     sorted_prj.end()));
    cout << result;
    return 0;
}
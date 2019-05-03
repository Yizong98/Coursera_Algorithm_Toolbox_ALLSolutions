#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

// Method walk through
// a while loop: greedy--> safe move: find farthest reachable stop; if cannot reach, return -1
// Edge: if after last gas station still + m cannot reach d, return -1

//pseudo: agg = 0; cnt = 0; while agg + m < d: 
// find the farthest stop: if agg + m < stop_position; return -1
// else: update agg. cnt++: if agg + m < d,return cnt

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int cnt = 0;
    int current = 0;
    vector<int> dummies = stops;
    dummies.insert(dummies.begin(),0);
    dummies.insert(dummies.end(),dist);
    while (current <= dummies.size()-1){
        int last = current;
        while (current <= dummies.size()-1 && dummies[current+1] - dummies[last] <= tank ){
            current++;
        }
        if (current == last) {
            return -1;
        }
        if (current <= dummies.size()-1)
            cnt++;
    }
    return cnt;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
vector<pii> calender = {{0, 6}, {1, 3}, {3, 5}, {3, 8}, {4, 7}, {5, 9}, {6, 10}, {8, 11}};
vector<pii> path;

void print() {
    for (auto x : calender) {
        cout << x.first << " " << x.second << endl;
    }
}

void greedy() {
    sort(calender.begin(), calender.end(), [](pii a, pii b) {
        return a.second < b.second;     // Thoi gian ket thuc tang dan, ket thuc cang som cang tot
    });
    path.push_back(calender[0]);
    int cur = calender[0].second;
    for (int i = 1; i < calender.size(); i++) {
        if (calender[i].first >= cur) {
            path.push_back(calender[i]);
            cur = calender[i].second;
        }
    }
}

int main()
{
    
    return 0;
}
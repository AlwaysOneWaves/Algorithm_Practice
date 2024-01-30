#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    pair<int, int> pii[42];
    pii[0] = make_pair(1, 0);
    pii[1] = make_pair(0, 1);
    map <int, pair<int, int>> mp;
    
    int t;
    cin >> t;
    for(int i = 0 ; i< t ; i++){
        int n;
        cin >> n;
        if(n == 0 || n == 1){
            mp[i] = pii[n];
            continue;
        }
        for(int j = 2 ; j <= n ; j++)
        {
            pii[j].first = pii[j-1].first + pii[j-2].first;
            pii[j].second = pii[j-1].second + pii[j-2].second;
        }
        mp[i] = pii[n];
    }

    for(int i = 0; i < t; i++){
        cout << mp[i].first << " " << mp[i].second << endl;
    }
    return 0;
}

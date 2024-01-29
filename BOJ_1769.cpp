#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    string::iterator iter;
    int cnt = 0;
    int res;
    if(s.size() > 1){
        while(1){
            res = 0;
            for(iter = s.begin(); iter != s.end() ; ++iter){
                res += (*iter - '0');
            }
            // cout << res << " , " << cnt << endl;
            s = to_string(res);
            cnt+=1;

            if(res < 10)
                break;
        }
    }

    res = stoi(s);
    cout << cnt << endl;
    
    if(res%3 == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
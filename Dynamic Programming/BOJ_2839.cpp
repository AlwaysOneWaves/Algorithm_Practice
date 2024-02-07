#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int res = -1;
    int q = n/5;
    for(int i = q; i >= 1; i--){
        if((n-5*i)%3 == 0)
        {
            res = i + (n-5*i)/3;
            break;
        }
    res = -1;
    }
    if(res == -1){
        if(n%5 == 0)
            res = n/5;
        else if(n%3 == 0)
            res = n/3;
        else
            res = -1;
    }
    cout << res;
    return 0;
}

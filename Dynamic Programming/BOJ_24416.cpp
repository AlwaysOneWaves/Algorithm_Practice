#include <iostream>

using namespace std;

int dp_fib[44] = {0,};

int fibonacci(int n){
    dp_fib[1] = 1;
    dp_fib[2] = 1;
    int cnt = 0;
    for(int i = 3; i <= n ; i++){
        cnt ++;
        dp_fib[i] = dp_fib[i-1] + dp_fib[i-2];
    }

    return cnt;
}

int fib(int n, int *cnt){
   
    // cout << *cnt << endl;
    if(n <= 2){
        *cnt += 1;
        return 1;
    }
    else
        return fib(n-1, cnt) + fib(n-2, cnt);
}

int main(){
    int cnt = 0;

    int n;
    cin >> n;
    
    fib(n, &cnt);
    int dp_res = fibonacci(n);
    cout << cnt << " " << dp_res;

    return 0;
}

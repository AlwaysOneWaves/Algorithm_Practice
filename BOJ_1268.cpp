#include <iostream>

using namespace std;

int student[1000][5];
int cnt[1000][1000];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < 5; j++){
            cin >> student[i][j];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i==j)
                continue;
            for(int k = 0 ; k < 5; k++){
                if(student[i][k] == student[j][k])
                    {
                        cnt[i][j] = 1;
                        k = 5;
                        continue;
                    }
            }
        }
    }
    int maxRef = 0;
    int maxCnt = 0;
    for(int i = 0 ; i<n ; i++){
        int temp = 0 ;
        for(int j = 0 ; j < n; j++){
            temp += cnt[i][j];
        }
        if(maxCnt < temp){
            maxRef = i;
            maxCnt = temp;
        }
    }
    cout << maxRef+1;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

#define BOY 1
#define GIRL 2

using namespace std;

int changeStatus(int base_status){
    if(base_status == 1)
        return 0;
    return 1;
}
void switchStatus(vector<int> *v, int gender, int num){
    if(gender == BOY){
        for(long unsigned int i = 0 ; i < v->size() ; i++){
            if((i+1)%num==0){
                v->at(i) = changeStatus(v->at(i));
            }
            continue;
        }
    }else{//gender == GIRL
        // cout << " how to ?" << endl;
        int base_index = num-1;
        
        if(base_index == 0 || base_index == (int)v->size()-1){
            v->at(base_index) = changeStatus(v->at(base_index));
            return;
        }else{
            int left = base_index-1, right = base_index+1;
            int range_start = base_index, range_end = base_index + 1;
            if(v->at(left) != v->at(right)){
                v->at(base_index) = changeStatus(v->at(base_index));
                return;
            }
            while(1){
                if(left == 0 || right == (int)v->size()-1){
                    if(v->at(left) == v->at(right))
                    {
                        range_start = left;
                        range_end = right;
                        break;
                    }else
                        break;
                }
                
                //compare left to right
                if(v->at(left) != v->at(right))
                    break;
                else{//left == right
                    range_start = left;
                    range_end = right;

                    //left, right move
                    left--;
                    right++;
                }
            }
            for(int j = range_start ; j<=range_end; j++){
                v->at(j) = changeStatus(v->at(j));
            }
        }
    }
    
}
int main(){
    int n;
    
    vector<int> switches;

    cin >> n;
    for(int i = 0 ; i< n ; i++){
        int status;
        cin >> status;
        switches.push_back(status);
    }
    int num_student;
    cin >> num_student;
    for(int i = 0 ; i < num_student ; i++){
        //man : 1, woman : 2
        int gender, num;
        cin >> gender >> num;
        switchStatus(&switches, gender, num);
    }
    for(int i = 0 ; i< (int)switches.size() ; i++){
        if(i > 0  && i%20 == 0)
            cout << endl;

        cout << switches[i];
        
        if( i != (int)switches.size() - 1)
            cout << " ";
    }
    return 0;
}

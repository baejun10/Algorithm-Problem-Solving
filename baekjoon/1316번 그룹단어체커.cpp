#include <iostream>

using namespace std;


int is_group(string in){
    bool already [500] = {false};
    int i, j;
    for(i = 0 ; i < in.size() ; i++){
        if(already[in.at(i)] == true){
            return -1; // Not group word
        }
        else already[in.at(i)] = true;
        for(j = i ; in[j] == in[j+1] ; j++){
            i = j+1;
        }
    }
    return 1; // groupword
}

int main()
{
    int n, cnt = 0;
    string in;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> in;
        if(is_group(in)== 1)
        cnt++;
    }
    cout << cnt;
}
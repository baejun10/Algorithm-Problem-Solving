#include <iostream>

using namespace std;

int main()
{
    int tc,sc = 0,combo = 0;
    char ox[90] = {};

    cin >> tc;
    for(int k = 0 ; k < tc ; k++){
        cin >> ox;
        for(int i = 0 ; ox[i] != 0 ; i++){
            
            if(ox[i] == 'O'){
                combo++;
                sc +=combo;
                
            }
            else{
                combo = 0;
            }
            
        }
        cout << sc << endl;
        sc = 0;
        combo = 0;
    }
    

}
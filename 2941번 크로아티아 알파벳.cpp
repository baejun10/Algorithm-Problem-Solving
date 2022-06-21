#include <iostream>

using namespace std;

int main()
{
    int an = 0;
    bool wrong = 0;
    int i, j, k;
    string comp[9] = {"c=", "c-","dz=","d-","d-","lj","nj","s=","z="};
    string in;
    cin >> in;
    for(i = 0 ; i < in.size() ; i++){
        for(j = 0 ; j < 9; j++){
            wrong = 0;
            for(k = 0 ; k < comp[j].size() ; k++){
                if(in.size() - i < comp[j].size()){
                    wrong = 1;
                    break;
                }
                if(in[k+i] != comp[j].at(k)){
                    wrong = 1;
                    break;
                }
            }
            if(wrong == 0){
                i += comp[j].size()-1; // 원래 기본적으로 i++을 수행하므로 1을 빼준다.
                break;
            }
        }
        an++; // 알파벳 한번 찾음
    }
    cout << an;
}
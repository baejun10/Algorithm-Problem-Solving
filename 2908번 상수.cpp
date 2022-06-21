#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2, rs1, rs2;
    int is1,is2, max;
    cin >> s1 >> s2;
    int len = s1.length();
    for(int i = 0; i < len ; i++){
        rs1[len-1-i] = s1[i]; 
    }
    len = s2.length();

    for(int i = 0; i < len ; i++){
        rs2[len-1-i] = s2[i]; 
    }
    is1 = stoi(rs1);
    is2 = stoi(rs2);
    max = is1 > is2?is1:is2;
    cout << max;

    

}
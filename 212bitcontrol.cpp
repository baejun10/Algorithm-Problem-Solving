#include <iostream>
using namespace std;
int main(){
    int x = 0x87654321;
    //A. The Least Significant Byte of x, with all other bits set to 0.
    cout << hex << (x & 0xff) << endl;
    //B. All but the Least Significant Byte of x complemented, with the Least Significant Byte left unchanged.
    cout << hex << ~(x ^ 0xff) << endl;
    //C. The Least Significant Byte of x set to all 1s, and all other bytes of x left unchanged.
    cout << hex << (x | 0xff) << endl;
}
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string hexStr = "0x3ae";
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexStr;
    ss >> x;
    cout << x << endl; // this will print 942
    return 0;
}

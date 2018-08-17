#include <bits/stdc++.h>
using namespace std;
 
string operation(string hex_a,string hex_b,int choice){ //0 for add and 1 for subtraction
	unsigned int dec_a=0,dec_b=0;
	stringstream ss_a,ss_b;
	ss_a<<hex<<hex_a;
	ss_b<<hex<<hex_b;
	ss_a>>dec_a;
	ss_b>>dec_b;
	cout<<"deca is "<<dec_a<<" and "<<"decb is"<<dec_b;
	unsigned int c=0;
	if(choice==0 or choice=='0'){
		c=dec_a+dec_b;
	}
	else if(choice==1 or choice=='1'){
		c=dec_a-dec_b;
	}
	cout<<"c is "<<c;
	stringstream ss_c;
	ss_c<<hex<<c;
	return ss_c.str();
}	
int main()
{
    cout<<operation("0x600","0x003000",'0');
}

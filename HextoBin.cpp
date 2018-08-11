#include<iostream>
#include<string>
#include <bitset>
#include <bits/stdc++.h>
#include<math.h>
using namespace std;

string operation(string hex_a,string hex_b,int choice){ //0 for add and 1 for subtraction
	unsigned int dec_a,dec_b;
	stringstream ss_a,ss_b;
	ss_a<<hex<<hex_a;
	ss_b<<hex<<hex_b;
	ss_a>>dec_a;
	ss_b>>dec_b;
	unsigned int sum=0;
	if(choice==0 or choice=='0') 	  sum=dec_a+dec_b;
	else if(choice==1 or choice=='1') sum=dec_a-dec_b;
	stringstream ss_sum;
	ss_sum<<hex<<sum;
	return ss_sum.str();
}	
void decode(string bin,string str_X,string str_B,string str_PC){
	stringstream X,B,PC;
	string addressing="";
	X<<hex<<str_X;
	B<<hex<<str_B;
	PC<<hex<<str_PC;
	stringstream TA;
	string machine="";
	string opcode(bin.substr(0,6)); //first six bits is the opcode
	stringstream ss_d;
	char n=bin[6],i=bin[7],x=bin[8],b=bin[9],p=bin[10],e=bin[11];
	string mnemonic("");

	if(n=='0' && i=='0'){
		mnemonic+="op m"; 
		bitset<100> disp(bin.substr(9));
		ss_d<<hex<<disp.to_ulong();	
		machine="SIC";
		if(x=='1'){
			mnemonic+=",X";  TA<<hex<<ss_d.str();  addressing="Direct";  
		}
		else{
			TA<<hex<<operation(ss_d.str(),X.str(),0);  addressing="Indexed";
		}		
	}
	else {
		machine="SIC/XE";
		if(e=='1') 		mnemonic+="+op ";
		else if(e=='0') mnemonic+="op ";
		if(n=='1' && i=='1') addressing="direct";
		else if(n=='0' && i=='1'){
			addressing="immediate"; 
			mnemonic+="#";
		}
		else if(n=='1' && i=='0') {
			addressing="indirect";
			mnemonic+="@";
		}
		bitset<100> disp(bin.substr(13));
		ss_d<<hex<<disp.to_ulong();	
		TA<<hex<<disp.to_ulong();
		if(x=='1'){
			stringstream output;
			output<<hex<<operation(TA.str(),X.str(),0);
			TA.str("");
			TA<<hex<<output.str();
		}
		if(b=='1'){
			stringstream output;
		 	output<<hex<<operation(TA.str(),B.str(),0);
		 	TA.str("");
		 	TA<<hex<<output.str();
		}
		if(p=='1'){ 
			stringstream PC_disp;
			PC_disp<<hex<<str_PC.substr(1);
			stringstream output;
			output<<hex<<operation(TA.str(),PC_disp.str().substr(1),str_PC[0]);
			TA.str("");
			TA<<hex<<output.str();
		}
		if(e=='1') 		mnemonic+="m";
		else if(x=='1' && p=='0' && b=='0' && e=='0')	mnemonic+="c";
		else if((x=='0')&&(p=='0')&&(b=='0')&&(e=='0')) mnemonic+="c";
		else mnemonic+="m";
		if(x=='1') mnemonic+=",X";
		
	}
	cout<<"nixbpe : "<<n<<i<<x<<b<<p<<e<<endl;
	cout<<"opcode: "+opcode<<endl; 
	cout<<"Machine: "+machine<<endl;
	cout<<"displacement is: "<<ss_d.str()<<endl;
	cout<<"TA is: "+TA.str()<<endl;
	cout<<"addressing mode: "<<addressing<<endl;
	cout<<"mnemonic :"<<mnemonic<<endl;
}
int main(){
	string hex_input("f94fff");
	stringstream ss_hex;
	ss_hex<<hex<<hex_input;
	unsigned n;
	ss_hex>>n;
	int l=hex_input.length();
	bitset<32> b(n);
	string X,B,PC;
	X="000090",B="006000";PC="003000";
	cout<<"binary of "<<hex_input<<"is "<<b.to_string().substr((8-l)*4)<<endl;
	decode(b.to_string().substr((8-l)*4),X,B,PC);	
}
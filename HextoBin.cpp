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
void decode(string bin,string str_X,string str_B,string str_PC){ //function to help decode the instruction
	stringstream X,B,PC; //Register string streams
	string addressing=""; //variable for addressing mode 
	/*converting the string register addresses into hex and 
	storing them into stringstream registers X,B,PC*/
	X<<hex<<str_X; 
	B<<hex<<str_B;
	PC<<hex<<str_PC;
	stringstream TA; //variable for target address
	string machine=""; //variable for SIC or SIC/XE machine
	string opcode(bin.substr(0,6)); //first six bits is the opcode
	stringstream ss_d; //variable for finding the displacement if exists
	//finding the bit parameter values of n,i,b,x,n,p
	char n=bin[6],i=bin[7],x=bin[8],b=bin[9],p=bin[10],e=bin[11];  
	string mnemonic("");//Variable for storing the instruction format

	if(n=='0' && i=='0'){ //n=0 and i=0 means SIC machine
		mnemonic+="op m"; 
		bitset<100> disp(bin.substr(9)); //finding the displacement by taking bits from 9 to rest
		ss_d<<hex<<disp.to_ulong();	
		machine="SIC";
		if(x=='0'){ //This means index addressing exists
			mnemonic+=",X";  TA<<hex<<ss_d.str();  addressing="Direct";  
		}
		else{
			TA<<hex<<operation(ss_d.str(),X.str(),0);  addressing="Indexed";
		}		
	}
	else {
		machine="SIC/XE";
		if(e=='1') 		mnemonic+="+op "; //e=1 means its a format 4
		else if(e=='0') mnemonic+="op "; //e=0 means its format 3
		if(n=='1' && i=='1') addressing="direct"; //n stands for indirect i stands for immediate
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
int main(int argc,char *argv[]){ //pass the hex code as command line argument
	if(argc==1){
		cout<<"Enter a 6 digit Hex code"<<endl;
	}
	else{
		string hex_input(argv[1]);
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
}

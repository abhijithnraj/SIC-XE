#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

/*int instruction_format(string i){ //function to find the instruction format of the instruction
	int instr_format=1; //default instruction format is 1
	if(i[0]=='+'){
		instr_format=4;
		char *words=strtok(i," ");
		char *operands=strtok(string(words[1]),",");
		int n_words=sizeof(words)/sizeof(char);
		else{
			cout<<"This is an invalid instruction"<<endl;
			return 0; 
		}


	}
	return instr_format;

}*/	
char *toCharArray(string s){
	int n=s.length();
	char *char_array;
	char_array=malloc(n+1);
	strcpy(char_array, s.c_str());
	return char_array;
}
int instruction_format(string i){
	char *words = strtok(toCharArray(i)," ");
	int length_words=sizeof(words)/sizeof(char);
	if(length_words==1){
		return 1;
	}
	string instruction = string(words[0]);
	else if(length_words==2){
		if(words[1].find(",") != string::npos){
			//char *operands=strtok(words[1],",");
			if(instruction[0]=='R' or instruction[instruction.length()-1]=='R'){
					return 2;
			}
		}
		else{ //not format 1 but contains only one operand 
			if(instruction[0]=='+'){
				return 4;
			}
			else{
				return 3;
			}
		}
	}
}
int main(int argc,char* argv[]){
	if(argc==1){
		cout<<"Please enter the instruction of  SIC or SIC/XE machine"<<endl;
	}
	else if(argc>2){
		cout<<"Please Enter only the SIC or SIC/XE instruction"<<endl;
	}
	else{
		string i(argv[1]); //i stands for instruction
		int instr_format = instruction_format(i);
		cout<<"The instruction format of "<<i<<" is "<<instr_format<<endl;

	}

}
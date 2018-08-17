string Hex2BinPerBit(char hex_bit){
	string bin_bit("");
	switch(hex_bit){
		case '0':
			bin_bit="0000";
			break;
		case '1':
			bin_bit="0001";
			break;
		case '2':
			bin_bit="0010";
			break;
		case '3':
			bin_bit="0011";
			break;
		case '4':
			bin_bit="0100";
			break;
		case '5':
			bin_bit="0101";
			break;
		case '6':
			bin_bit="0110";
			break;
		case '7':
			bin_bit="0111";
			break;
		case '8':
			bin_bit="1000";
			break;
		case '9':
			bin_bit="1001";
			break;
		case 'A':
		case 'a':
			bin_bit="1010";
			break;
		case 'B':
		case 'b':
			bin_bit="1011";
			break;
		case 'C':
		case 'c':
			bin_bit="1100";
			break;
		case 'd':
		case 'D':
			bin_bit="1101";
			break;
		case 'e':
		case 'E':
			bin_bit="1110";
			break;
		case 'F':
		case 'f':
			bin_bit="1111";
			break;

	}
	return bin_bit;

}
string Hex2Bin(string hex){
	string bin("");
	int n = hex.length();
	for(int i=0;i<n;i++){
		bin+=Hex2BinPerBit(hex[i]);
	}
	return bin;

}

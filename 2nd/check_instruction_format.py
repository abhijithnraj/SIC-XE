def format30R4(mnemonic):
    if(mnemonic[0]=="+"):
        return 4
    else:
        return 3
def format_instruction(instruction):
    words=instruction.split();
    length=len(words)
    mnemonic = words[0].upper() # ie ADD SUB etc
    #print(words,length)
    if(mnemonic=="OR" or mnemonic=="RD"):
        return format30R4(mnemonic)
    if(length==1):
        if("RSUB" in mnemonic):
            return format30R4(mnemonic)
        else:
            return 1
    elif(length==2):
        if( (mnemonic[0]=="R" or mnemonic[-1]=="R") or ("SHIFT" in mnemonic) or
        							 ("CLEAR" in mnemonic) or(mnemonic=="SVC")):
                    return 2
        else:
                return format30R4(mnemonic)
instruction=input("Enter a valid SIC/XE instruction \n eg: ADDR r1,r2\n")
print("The instruction format of "+str(instruction)+" is format "+str(format_instruction(instruction)))


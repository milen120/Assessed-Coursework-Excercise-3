/**************************************************************************
 * Assessment Title: Assessed Coursework Excercise 3
 *
 * Number of Submitted C Files: 1
 *
 * Date: 
 *
 * 
 * Author:  Reg no: 
 *
 *
 * Personal Statement: I confirm that this submission is all our own work.
 *
 *          (Signed)
 *
 * 
 *
 **************************************************************************/
#include<stdio.h>
#include<string.h>

//Declaring variables to be used as registers
int running = 1; //Variable controlling 'while' loop
char ac[17]; //Accumulator
char ir[17]; //Instruction register 
char mbr[17]; //Memory buffer register
char pc[13]; //Program counter
char mar[13]; //Memory address register
char in_reg[13]; //Input register
char out_reg[13]; //Output register

//Declaring functions
void halt(); //0000
void jump_x(); //0001
void load_x(); //0010
void store_x(); //0011
void input(); //0100
void output(); //0101
void subt_x(); //0110
void add_x(); //0111
void skipcond(); //1000

//Auxilary functions
int decimal_to_binary(int size,char bin[size);
int binary_to_decimal(int dec,int size);


int main()
{
char main_memory[4096][17] = {' '}; //4K words main memory

	while(running == 1)
	{
		//Functions will go here
		halt();	
	}

return 0; 
}

//Function descriptions

void halt()
{
/*HLT instruction brings execution to an orderly close by setting the halt flag,
disabling further processing. HLT has opcode 0, because if we accidentally jump into empty memory,
we're marginally more likely to hit 0 than anything else.*/	
	running = 0;
	printf("The program has halted.\n");
}

void jump_x()
{
/*JMP instruction transfers control to the address indicated by its operand, setting IP.
Take care not to JMP to the JMP instruction itself!*/
	
}

void load_x()
{
/*LDA address fetches the value stored at address and copies it to the accumulator,
giving the main way to get data from memory to the processor.*/	
	
}

void store_x()
{
/*Wites a copy of the accumulator to the indicates address in memory.*/
	
	
}

void input()
{
 	printf("Please enter your 16-bit binary input\n");
	printf("Please include a 4-bit OPcode and 12bit Operand - >");
	scanf(" %s", in_reg);
	
	//Checking what OPcode is
	if(in_reg[0] == 0 && in_reg[1] == 0 && in_reg[2] == 0 && in_reg[3] == 0)
	{
		halt();
	}
	else if(in_reg[0] == 0 && in_reg[1] == 0 && in_reg[2] == 0 && in_reg[3] == 1)
	{
		jump_x();
	}
	else if(in_reg[0] == 0 && in_reg[1] == 0 && in_reg[2] == 1 && in_reg[3] == 0)
	{
		load_x();
	}
	else if(in_reg[0] == 0 && in_reg[1] == 0 && in_reg[2] == 1 && in_reg[3] == 1)
	{
		store_x();
	}
	else if(in_reg[0] == 0 && in_reg[1] == 1 && in_reg[2] == 0 && in_reg[3] == 0)
	{
		input();
	}
	else if(in_reg[0] == 0 && in_reg[1] == 1 && in_reg[2] == 0 && in_reg[3] == 1)
	{
		output();
	}
	else if(in_reg[0] == 0 && in_reg[1] == 1 && in_reg[2] == 1 && in_reg[3] == 0)
	{
		subt_x();
	}
	else if(in_reg[0] == 0 && in_reg[1] == 1 && in_reg[2] == 1 && in_reg[3] == 1)
	{
		add_x();
	}
	else if(in_reg[0] == 1 && in_reg[1] == 0 && in_reg[2] == 0 && in_reg[3] == 0)
	{
		skipcond();
	}
}

void output()
{
/*copy AC to back of output queue to AC; IP = IP+1*/
	for(int i = 0; i <13; i++)
	{
		out_reg[i] = ac[i];
	}
	
}

void subt_x()
{
	
}

void add_x()
{
	
}

void skipcond()
{
	
}
int decimal_to_binary(int size,char bin[size])
{
	if(size==17){
	int result=0;
	if(bin[size-2]=='1'){
		result++;
	}
	for(int i=size-3;i>-1;i--){
		int power_of_two=2;
		if(bin[i]=='1'){
			for(int f=i;f<size-3;f++){
				power_of_two=power_of_two*2;
			}
			if(i!=0){
				result=result+power_of_two;
			}else{
				result=result-power_of_two;
			}
		}
	}
	return result;
	}else{
		int result=0;
		if(bin[11]=='1'){
			result++;
		}
		for(int i=10;i>-1;i--){
			int power_of_two=2;
			if(bin[i]=='1'){
				for(int f=i;f<10;f++){
					power_of_two=power_of_two*2;
				}
				result=result+power_of_two;
			}
		}
	
		return result;
	}
}
char * binary_to_decimal(int dec,int size)
{
	if(size==17){
		static char bin[17];
		bin[size-1]='\0';
		for(int i=size-2;i>-1;i--){
			if(dec%2==0 ){
				bin[i]='0';
			}else{
				bin[i]='1';
			}
			dec=dec/2;
		}
		return bin;
	}else{
		static char bin[13];
		bin[12]='\0';
		for(int i=10;i>-1;i--){
			if(dec%2==0 ){
				bin[i]='0';
			}else{
				bin[i]='1';
			}
			dec=dec/2;
		}
		return bin;
	}
}



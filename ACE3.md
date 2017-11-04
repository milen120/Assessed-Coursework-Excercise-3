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
char ac[17]; //Accumolator
char ir[17]; //Instruction register 
char mbr[17]; //Memory buffer register
char pc[13]; //Program counter
char mar[13]; //Memory address register
char input[17]; //Input register
char output[13]; //Output register

//Declaring functions
void halt(); //0000
void store_x(); //0001
void subt_x(); //0010
void add_x(); //0011
void input(); //0100
void output(); //0101
void load_x(); //0110
void skipcond(); //0111
void jump_x(); //1000


int main()
{
char main_memory[4000][13] = {' '}; //4K words main memory

	while(running == 1)
	{
		//Functions will go here
		halt();	
	}

return 0; 
}

//Function descriptions

void input()
{
 	printf("Please enter your binary input: ");
	scanf(" %s", input);
}

void halt()
{
	running = 0;
	printf("The program has halted.\n");
}

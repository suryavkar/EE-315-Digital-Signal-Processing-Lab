/*
 * main.c
 */

#include <stdio.h>
#include "usbstk5515.h"

#define IR_length 12
#define In_length 12
#define tmp_l IR_length+In_length-1

Int16 x[In_length] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
Int16 array[tmp_l];
void linearbuff();
Int16 *inPtr;
Int16 *outPtr;
Int16 *coeff;
Int16 coefs[IR_length] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
		/*{0.073230274467899411638960316395241534337,
		0.177368063271133302727378122654045000672,
		0.249401662260967382778176215651910752058,
		0.249401662260967382778176215651910752058,
		0.177368063271133302727378122654045000672,
		0.073230274467899411638960316395241534337};*/
Int16 input;
Int16 output;


void linearbuff(void)
{
	int i;
	long int accumulator=0;
    static Int16 buffer[IR_length]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
/*
 write convolution code here;
 */
    for(i=1;i<IR_length;i++)
    {
    	buffer[IR_length-i] = buffer[IR_length-i-1];
    }
    buffer[0] = *inPtr;
    for(i=0;i<IR_length;i++)
    {
    	accumulator+=buffer[i]*(*coeff++);
    }
    (*outPtr)=((Int16)accumulator);
}




main(void)
{
int j=0;
coeff = &coefs[0]; 	//coefs is coefficient of impulse response defined in fdacoefs_int.h
inPtr = &input;		//inPtr is a globally declared pointer to a Int16
outPtr = &output;
//	SYS_EXBUSSEL = 0x6100;
//    USBSTK5515_init( );
//temp_length=IR_length+In_length-1;

// static Int16 inbuffer[In_length]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while(j<tmp_l) // loop
    {
        /*  Read input data using a probe-point connected to a host file. */
      //printf("x=%d\n",x[j]);
    	if(j<In_length)
    		input=x[j];
    	else
    		input=0;
    	//write your code for function call;
    	coeff = &coefs[0];
    	linearbuff();

    	array[j]=output;
    	printf("output=%d\n",array[j]);

        j=j+1;
    }
    return 0;
}

/*
 * FUNCTION:     Read input signal and write processed output signal
 *              using ProbePoints
 * PARAMETERS: none.
 * RETURN VALUE: none.
 */
/*static void dataInput()
{
    do data I/O
    return;
}*/

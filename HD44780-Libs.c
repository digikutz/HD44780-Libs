#ifndef F_cpu
#define F_CPU 1000000  // by default we have the 1MHz internal oscillator
#endif

#include <avr/io.h>      // this contains all the IO port definitions
#include <util/delay.h>
#include <stdio.h> 
#include <string.h>

void Lcdinit(void)	//Initalize lcd display
{
	
   //init sequence
  //part 1
  PORTD = 0x22;
    _delay_ms(10);
    PORTD = 0x02;		//0 0 1 0
    _delay_ms(10);
  
  PORTD = 0x22;
    _delay_ms(10);
    PORTD = 0x02;		//0 0 1 0
    _delay_ms(10);
  
  PORTD = 0x22;			
    _delay_ms(10);
    PORTD = 0x28;			
    _delay_ms(10);
    PORTD = 0x08;		//1 0 0 0
    _delay_ms(10);
  PORTD = 0x28;
    _delay_ms(10);
    
    
    PORTD = 0x20;
    _delay_ms(10);
    PORTD = 0x00;		//0 0 0 0
    _delay_ms(10);
    
    
    PORTD = 0x20;
    _delay_ms(10);
    PORTD = 0x2f;		
    _delay_ms(10);
    
    PORTD = 0x0f;		//1 1 1 1
    _delay_ms(10);
    PORTD = 0x2f;		
    _delay_ms(10);
    
    PORTD = 0x20;
    _delay_ms(10);
    PORTD = 0x00;		//0 0 0 0
    _delay_ms(10);
    PORTD = 0x20;
    _delay_ms(10);
    
    PORTD = 0x26;		
    _delay_ms(10);
    
    PORTD = 0x06;		//0 1 1 0
    _delay_ms(10);
    PORTD = 0x26;		
    _delay_ms(10);
	PORTD = 0x20;		
    _delay_ms(10);
   }
    //code
void DoNibbles(uint8_t nibbleone, uint8_t nibbletwo)  // writes nibble to port
{

    PORTD = nibbleone + 0x20;
    _delay_us(500);
    PORTD = nibbleone;		//nibble one
    _delay_us(500);
     PORTD = nibbleone + 0x20;
    _delay_us(500);
	
    PORTD = nibbletwo + 0x20;
    _delay_us(500);
    PORTD = nibbletwo;		//nibble two
    _delay_us(500);
    PORTD = nibbletwo + 0x20;
    _delay_us(500);
    PORTD =  0x20;
    _delay_us(500);


}


void PrintChar(uint8_t singlechar)	//picks set of nibbles to send on to DoNibbles
{
	  switch(singlechar)
	  {
	    //only L, S, & D have correct nibble values
	    //0x01 = ohms

	    case 0x41: DoNibbles(0x14, 0x11); break;	//A
	    case 0x42: DoNibbles(0x14, 0x12); break;	//B
	    case 0x43: DoNibbles(0x14, 0x13); break;	//C
	    case 0x44: DoNibbles(0x14, 0x14); break;	//D
	    case 0x45: DoNibbles(0x14, 0x15); break;	//E
	    case 0x46: DoNibbles(0x14, 0x16); break;	//F
	    case 0x47: DoNibbles(0x14, 0x17); break;	//G
	    case 0x48: DoNibbles(0x14, 0x18); break;	//H	      
	    case 0x49: DoNibbles(0x14, 0x19); break;	//I
	    case 0x4a: DoNibbles(0x14, 0x1a); break;	//J
	    case 0x4b: DoNibbles(0x14, 0x1b); break;	//K
	    case 0x4c: DoNibbles(0x14, 0x1c); break;	//L
	    case 0x4d: DoNibbles(0x14, 0x1d); break;	//M	
	    case 0x4e: DoNibbles(0x14, 0x1e); break;	//N
	    case 0x4f: DoNibbles(0x14, 0x1f); break;	//O
	    case 0x50: DoNibbles(0x15, 0x10); break;	//P
	    case 0x51: DoNibbles(0x15, 0x11); break;	//Q
	    case 0x52: DoNibbles(0x15, 0x12); break;	//R
	    case 0x53: DoNibbles(0x15, 0x13); break;	//S
	    case 0x54: DoNibbles(0x15, 0x14); break;	//T
	    case 0x55: DoNibbles(0x15, 0x15); break;	//U
	    case 0x56: DoNibbles(0x15, 0x16); break;	//V
	    case 0x57: DoNibbles(0x15, 0x17); break;	//W
	    case 0x58: DoNibbles(0x15, 0x18); break;	//X
	    case 0x59: DoNibbles(0x15, 0x19); break;	//Y
	    case 0x5a: DoNibbles(0x15, 0x1a); break;	//Z
	    case 0x61: DoNibbles(0x16, 0x11); break;	//a
	    case 0x62: DoNibbles(0x16, 0x12); break;	//b
	    case 0x63: DoNibbles(0x16, 0x13); break;	//c
	    case 0x64: DoNibbles(0x16, 0x14); break;	//d
	    case 0x65: DoNibbles(0x16, 0x15); break;	//e
	    case 0x66: DoNibbles(0x16, 0x16); break;	//f
	    case 0x67: DoNibbles(0x16, 0x17); break;	//g
	    case 0x68: DoNibbles(0x16, 0x18); break;	//h	      
	    case 0x69: DoNibbles(0x16, 0x19); break;	//i
	    case 0x6a: DoNibbles(0x16, 0x1a); break;	//j
	    case 0x6b: DoNibbles(0x16, 0x1b); break;	//k
	    case 0x6c: DoNibbles(0x16, 0x1c); break;	//l
	    case 0x6d: DoNibbles(0x16, 0x1d); break;	//m	
	    case 0x6e: DoNibbles(0x16, 0x1e); break;	//n
	    case 0x6f: DoNibbles(0x16, 0x1f); break;	//o
	    case 0x70: DoNibbles(0x17, 0x10); break;	//p
	    case 0x71: DoNibbles(0x17, 0x11); break;	//q
	    case 0x72: DoNibbles(0x17, 0x12); break;	//r
	    case 0x73: DoNibbles(0x17, 0x13); break;	//s
	    case 0x74: DoNibbles(0x17, 0x14); break;	//t
	    case 0x75: DoNibbles(0x17, 0x15); break;	//u
	    case 0x76: DoNibbles(0x17, 0x16); break;	//v
	    case 0x77: DoNibbles(0x17, 0x17); break;	//w
	    case 0x78: DoNibbles(0x17, 0x18); break;	//x
	    case 0x79: DoNibbles(0x17, 0x19); break;	//y
	    case 0x7a: DoNibbles(0x17, 0x1a); break;	//z
	    case 0x30: DoNibbles(0x13, 0x10); break;	//0
	    case 0x31: DoNibbles(0x13, 0x11); break;	//1
	    case 0x32: DoNibbles(0x13, 0x12); break;	//2
	    case 0x33: DoNibbles(0x13, 0x13); break;	//3
	    case 0x34: DoNibbles(0x13, 0x14); break;	//4
	    case 0x35: DoNibbles(0x13, 0x15); break;	//5
	    case 0x36: DoNibbles(0x13, 0x16); break;	//6
	    case 0x37: DoNibbles(0x13, 0x17); break;	//7
	    case 0x38: DoNibbles(0x13, 0x18); break;	//8
	    case 0x39: DoNibbles(0x13, 0x19); break;	//9
	    
	    //special chars
	    
	    case 0x2e: DoNibbles(0x12, 0x1e); break;	//decimal
	    case 0x2d: DoNibbles(0x12, 0x1d); break;	//dash
	    case 0x01: DoNibbles(0x1f, 0x14); break;	//ohm symbol
	    
	    //commands 
	    
	    case 0x04: DoNibbles(0x00, 0x02); break;	//home
	    case 0x05: DoNibbles(0x00, 0x01); break;	//clear display
	    case 0x06: DoNibbles(0x01, 0x04); break;	//direction right 
	    case 0x07: DoNibbles(0x00, 0x04); break;	//direction left
	    default: break;	
	  }	
	
    }

void Printnumber(char singlechar)	//picks set of nibbles to send on to DoNibbles
{
	  switch(singlechar)
	  {
	    
	    case 0: PrintChar(0x10); break;
	    case 1: PrintChar(0x11); break;
	    case 2: PrintChar(0x12); break;	
	    case 3: PrintChar(0x13); break;	
	    case 4: PrintChar(0x14); break;	
	    case 5: PrintChar(0x15); break;	
	    case 6: PrintChar(0x16); break;	
	    case 7: PrintChar(0x17); break;
	    case 8: PrintChar(0x18); break;	
	    case 9: PrintChar(0x19); break;	
	    default:PrintChar(0x79); break;
	    
	  }
	  
	  
}	  
void PrintMebane(void)  //prints MEBANE-LABS ((4x20 loop for scroll)
{	
	PrintChar(0x05);
	//PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x4d);
	PrintChar(0x45);
	PrintChar(0x42);
	PrintChar(0x41);
	PrintChar(0x4e);
	PrintChar(0x45);
	
	
	PrintChar(0x06);
	PrintChar(0x06);
	
	PrintChar(0x06);
	PrintChar(0x4c);
	PrintChar(0x41);
	PrintChar(0x42);
	PrintChar(0x53);
	
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	
	PrintChar(0x37);
	PrintChar(0x2d);
	PrintChar(0x32);
	PrintChar(0x39);
	PrintChar(0x2d);
	
	PrintChar(0x32);
	PrintChar(0x30);
	PrintChar(0x31);
	PrintChar(0x31);
	
	
	_delay_ms(5000);



}


void Count(void)	// prints 0.0000-omega
{
	PrintChar(0x05);
	
	
	 //4.      
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x34);
	PrintChar(0x2e);
	PrintChar(0x39);
	PrintChar(0x39);
	PrintChar(0x39);
	PrintChar(0x36);
	PrintChar(0x06);
	PrintChar(0x01);
	
	_delay_ms(500);
	
	PrintChar(0x05);
	
	
	 //.0002
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x34);
	PrintChar(0x2e);
	PrintChar(0x39);
	PrintChar(0x39);
	PrintChar(0x39);
	PrintChar(0x37);
	PrintChar(0x06);
	PrintChar(0x01);
	
	_delay_ms(50);
	
	//PrintChar(0x05); //.0001
	//PrintChar(0x34);
	//PrintChar(0x2e);
	//PrintChar(0x39);
	//PrintChar(0x39);
	//PrintChar(0x39);
	//PrintChar(0x35);
	//PrintChar(0x2d);
	//PrintChar(0x01);

	//_delay_ms(50);
}

void Count1(void)	// Prints 0123456789
{
	
	
        PrintChar(0x30);       
	PrintChar(0x31);
	PrintChar(0x32);
	PrintChar(0x33);
	PrintChar(0x34);
	PrintChar(0x35);
	PrintChar(0x36);
	PrintChar(0x37);
	PrintChar(0x38);
	PrintChar(0x39);
}

uint16_t ReadADC(uint8_t __channel)
{
   ADMUX |= __channel; 		      // Channel selection
   ADMUX |= 0x64;      		      // Use interanl 1.1v ref (cap on ref pin)
   ADCSRA |= _BV(ADSC);               // Start conversion
   while(!bit_is_set(ADCSRA,ADIF));   // Loop until conversion is complete
   ADCSRA |= _BV(ADIF);               // Clear ADIF by writing a 1 (this sets the value to 0)
 
   return(ADC);
}
 
void adc_init()
{
        ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); //Enable ADC and set 128 prescale
}

void Getadc()   //prepaares adc output for (printchar) lcd
{
	uint16_t now;
	float mul;
	char str[64];
        long fun;
	
	now = ReadADC(0);
		
	mul = 10.7;     // = 1.1/1024 use for internal ref
	//mul = 47.66;  // = 4.88/1024 is the voltage represented by each count (adc multiplyer)	
	
	fun = (float)mul * (uint16_t)now;
	
	ltoa(fun, str, 10);  
 	//sprintf(str,"%f",fun); 
	
	PrintChar(str[0]);
	PrintChar(0x2e);    //decimal
	PrintChar(str[1]);
	PrintChar(str[2]);
	PrintChar(str[3]);
	PrintChar(str[4]);
	//PrintChar(str[5]);
	//PrintChar(str[6]);
	//PrintChar(str[7]);
	//PrintChar(0x07);
	//PrintChar(0x07);
	//PrintChar(0x07);
	//PrintChar(0x07);
	
	PrintChar(0x06);
	PrintChar(0x56);
	PrintChar(0x64);
	PrintChar(0x63);
} 



void Centerspace()   //spaces to center
{
    PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
	PrintChar(0x06);
}  

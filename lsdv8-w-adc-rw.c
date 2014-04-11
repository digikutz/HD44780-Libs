
#include </home/ill/git/HD44780-Libs/HD44780-Libs.c> 
#include </home/ill/git/HD44780-Libs/HD44780-Libs.h>



int main(void) {
    
    DDRC = 0x00;  //adc ports as inputs 	
    DDRD = 0xff;  // set PORTD to an output (lcd port)
    PORTD = 0x20; // set enable high (nibble plus+0x20) 		
      
    Lcdinit();
    adc_init();
    
    PrintMebane();  //print banner	
          
    //Centerspace(); //space to line 2 center
    
    while (1) {
	 
	PrintChar(0x05);  //go to home of lcd
        
	Getadc();	  //print voltage to lcd
	
	_delay_ms(100);

    }     
 }// reads 2.397 at 2.448 0.979% accurate to fluke 77
	 
	 
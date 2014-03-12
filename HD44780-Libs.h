

void Lcdinit(void);	//Initalize lcd display

void DoNibbles(uint8_t nibbleone, uint8_t nibbletwo);  // writes nibble to port

void PrintChar(uint8_t singlechar);	//picks set of nibbles to send on to DoNibbles

void Printnumber(char singlechar);	//picks set of nibbles to send on to DoNibbles

void PrintMebane(void);  //prints MEBANE-LABS ((4x20 loop for scroll)

void Count(void);	// prints 0.0000-omega

void Count1(void);	// Prints 0123456789

uint16_t ReadADC(uint8_t __channel);
 
void adc_init();

void Getadc();   //prepaares adc output for (printchar) lcd

void Centerspace();   //spaces to center


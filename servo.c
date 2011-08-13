#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
// Setup Timer to phase correct pwm 
// Enable output on specifc pin
// Configure port which contains the output pin (DDR)
// This will likely be an 'additional function' of the pin

#if 0
void initClock(void)
{
    cli(); // Disable interrupts so we don't mess up the prescaler timing
    CLKPR |= (1 << CLKPCE); // Enable prescaler change
    CLKPR = 0x08; //Disable prescale change and prescale by 256
    sei(); // Re-enable interrupts
    return;
}
#endif
void initPWM(void)
{
    DDRB |= (1 << DDB2); //Set PB2 as output of PWM (OC0A)
    TCCR0A |= (1 << WGM00) | (1 << COM0A1); // This sets PWM Phase Correct mode 1, compare behavior
    TCCR0B |= (1 << CS02); //CS02 sets timer prescaling to 256
    OCR0A = 24; //This sets the compare match value to 9.16% dc, 1.5ms pulse, centering the servo


}
int main(void)
{

    //initClock();
    initPWM();
    for (;;)
        ;
    return (0);
}


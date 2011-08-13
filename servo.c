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
    TCCR0A |= (1 << WGM00);
    TCCR0B |= (1 << WGM02) | (1 << CS02); // The WGM bits setup the correct PWM mode, the CS02 sets timer prescaling to 256

}
int main(void)
{

    //initClock();
    initPWM();
    for (;;)
        sleep_mode();
    return (0);
}


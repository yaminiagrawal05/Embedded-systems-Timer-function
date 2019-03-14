void timer_normal_init()
{
 TCCR0|=(1<<CS01);
}
void timer_pwm_init()
{
TCCR0|=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01);
DDRB=0b00001000;
}
void timer_ctc_init()
{
TCCR0|=(1<<WGM01)|(1<<COM00)|(1<<CS01);
DDRB=0b00001000;
}



// eeprom function
void eeprom_write(unsigned int add,unsigned char data)
{
  while(EECR&(1<<EEWE)){} // so that the write register is filled..then it becmes empty
  EEAR=add;
  EEDR=data;
  EECR|=(1<<EEMWE); //enable the master write bit(it should always be high before the EEWE bit
  EECR|=(1<<EEWE);   //enable the write bit
}
char eeprom_read(unsigned int add)
{
   while(EECR&(1<<EEWE)){}
    EECR|=(1<<EERE);
   return (EEDR);
}
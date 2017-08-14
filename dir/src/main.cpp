#include <samv71/samv71.h>

extern "C" void SystemInit()
{
}


void delay1();

int main ()
{  

    SCB_EnableICache(); // Instruction cache Enable
    SCB_EnableDCache(); // Data cache Enable

  
        delay1();
        
    * ( ( unsigned long int * ) 0x400E0630 ) = 0x2;  //включает тактирование через PLLACK
    * ( ( unsigned long int * ) 0x400E0628 ) = 0x20180001;  //ставит умножитель PLLACK на 25 и делитель на 1 + бит one + 0 циклов медленнх часов
    

    * ( ( unsigned long int * ) 0x400E0610 ) = 0x400;//включает блок PIOA
    * ( ( unsigned long int * ) 0x400E0E00 ) = 0x800000;//активровали пин
    * ( ( unsigned long int * ) 0x400E0EA4 ) = 0x800000;//разрешает изменение
    * ( ( unsigned long int * ) 0x400E0E10 ) = 0x800000;//активирует линию входа/выхода на пине

    while(1)
    {
    * ( ( unsigned long int * ) 0x400E0E34 ) = 0x800000;//clear
     delay1();   
    * ( ( unsigned long int * ) 0x400E0E30 ) = 0x800000;//set
     delay1();
    }
     
}


void delay1(){
    for ( volatile long long int i = 0; i < 1000000; ++ i )
    {
        asm volatile ( "nop" );
    }
    




}


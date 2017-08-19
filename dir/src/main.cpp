#include <samv71/samv71.h>

extern "C" void SystemInit()
{
}


void delay1();

int main ()
{  

    SCB_EnableICache(); // Instruction cache Enable
    
    SCB_EnableDCache(); // Data cache Enable

    PMC->PMC_MCKR = PMC_MCKR_CSS_PLLA_CLK;  //включает тактирование через PLLACK
     
    REG_CKGR_PLLAR  = 0x20180001;  //ставит умножитель PLLACK на 25 и делитель на 1 + бит one + 0 циклов медленнх часов
    
    PMC->PMC_PCER0 = PMC_PCER0_PID10; //включает тактирование периферии включая PIOA
    
    PIOA->PIO_PER=PIO_PA23; //активровали пин в блоке PIOA  (через смещение в файле)        * ( ( unsigned long int * ) 0x400E0E00 ) = 0x800000;

    PIOA->PIO_OWDR=PIO_PA23; //REG_PIOA_OWDR = PIO_PA23; //разрешает изменение PIO_OWDR
    
    PIOA->PIO_OER=PIO_PA23;  //REG_PIOA_OER = PIO_PA23; //активирует линию входа/выхода на пине


    while(1)
    {
        PIOA->PIO_CODR = PIO_PA23; //clear
        delay1();  
        PIOA->PIO_SODR = PIO_PA23; //set
        delay1();
    }
     
}


void delay1(){
    for ( volatile long long int i = 0; i < 10000000; ++ i )
    {
        asm volatile ( "nop" );
    }
    




}
/*
 *  PIOA = 0x400E0E00             файл  samv71q21.h
 *  REG_PMC_MCKR = 0x400E0630     файл  instance_pmc.h
 *  REG_CKGR_PLLAR = 0x400E0628   файл  instance_pmc.h
 *  REG_PMC_PCER0  = 0x400E0610   файл  instance_pmc.h
 * 
 *  REG_PIOA_OWDR = 0x400E0EA4    файл  instance_pioa.h
 *  REG_PIOA_OER = 0x400E0E10     файл  instance_pioa.h
 *  REG_PIOA_CODR = 0x400E0E34    файл  instance_pioa.h
 *  REG_PIOA_SODR = 0x400E0E30    файл  instance_pioa.h
 * 
 * 
 * instance_pioa.h  свойства регистра блока выходов a*/


#include <samv71/samv71.h>

extern "C" void SystemInit()
{
}

void dalay1();
int main ()
{  
        dalay1();
     
    *((unsigned long int*)0x400E0610) = 0x400;//включает блок PIOA
    *((unsigned long int*)0x400E0E00) = 0x800000;//активровали пин
    *((unsigned long int*)0x400E0EA4) = 0x800000;//разрешает изменение
    *((unsigned long int*)0x400E0E10) = 0x800000;//активирует линию входа/выхода на пине

    while(1)
    {
    *((unsigned long int*)0x400E0E34) = 0x800000;//clear
     dalay1();   
    *((unsigned long int*)0x400E0E30) = 0x800000;//set
     dalay1();
    }
     
}


void dalay1(){
    for(volatile long long int i = 0; i<100000;++i){
        asm volatile ("nop");
    }
}


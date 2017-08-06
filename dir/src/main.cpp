#include <stdio.h>
extern "C" void SystemInit()
{
}


int main () {
                
                            *((unsigned long int*)0x400E0610) = 0x400;//включает блок PIOA
                            *((unsigned long int*)0x400E0E00) = 0x800000;//активровали пин
                            *((unsigned long int*)0x400E0E10) = 0x800000;//активирует линию входа/выхода на пине

                            delay(1000);



                while(1){
                            *((unsigned long int*)0x400E0EA4) = 0x800000;//деактивирует линию на пине 23
                            delay(1000);
                            *((unsigned long int*)0x400E0E10) = 0x800000;//активирует линию входа/выхода на пине 23
                            delay(1000);
                        }


            }

#include <samv71/samv71.h>
#include <core_cm7.h>

extern "C" void SystemInit()
{
}

/*
bool zzz = false; 

extern "C" void SysTick_Handler ( void ) 
{  
    PIOA->PIO_SODR = PIO_PA23;
    
    if(zzz)
    {
        PIOA->PIO_CODR = PIO_PA23;
        zzz = false;
        
    } else {
    
        PIOA->PIO_SODR = PIO_PA23;
        zzz = true;
    }
    
    
}
extern "C" void NMI_Handler        ( void ){while(1){}}
extern "C" void HardFault_Handler  ( void ){while(1){}}
extern "C" void MemManage_Handler  ( void ){while(1){}}
extern "C" void BusFault_Handler   ( void ){while(1){}}
extern "C" void UsageFault_Handler ( void ){while(1){}}

*/

void delay1(unsigned int ms);

int main ()
{  
    
    SCB_EnableICache(); // Instruction cache Enable
    
    SCB_EnableDCache(); // Data cache Enable

    PMC->PMC_MCKR = PMC_MCKR_CSS_PLLA_CLK;  //включает тактирование через PLLACK
    
    PMC->CKGR_PLLAR=CKGR_PLLAR_ONE | CKGR_PLLAR_MULA(24) | CKGR_PLLAR_PLLACOUNT(0) | CKGR_PLLAR_DIVA(1);      //REG_CKGR_PLLAR  = 0x20180001;  //ставит умножитель PLLACK на 25 и делитель на 1 + бит one + 0 циклов медленнх часов

    PMC->PMC_PCER0 = PMC_PCER0_PID10; //включает тактирование периферии включая PIOA
    
    PIOA->PIO_PER=PIO_PA23; //активровали пин в блоке PIOA  (через смещение в файле)        * ( ( unsigned int * ) 0x400E0E00 ) = 0x800000;

    PIOA->PIO_OWDR=PIO_PA23; //REG_PIOA_OWDR = PIO_PA23; //разрешает изменение PIO_OWDR
    
    PIOA->PIO_OER=PIO_PA23;  //REG_PIOA_OER = PIO_PA23; //активирует линию входа/выхода на пине
    
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk; // или 0b0101   ( | SysTick_CTRL_TICKINT_Msk генерирует исключение) -------- учавствуют в активации systick
    
    SysTick->LOAD = 0x993E0U;  //SysTick_LOAD_RELOAD_Msk; //reload registr   ------------ учавствуют в активации systick
    
    //SysTick_Config(0x00FFFFFFU);
    
    //NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);   //настройка прерывания systick    

   

    while(1)
    {
        
        PIOA->PIO_CODR = PIO_PA23; //clear
        
        delay1(1000);
        
        PIOA->PIO_SODR = PIO_PA23; //set
        
        delay1(1000);
        
    }
    
     
}


void delay1 (unsigned int ms)
{
    register unsigned int i = 0;
    
        while( i < ms )
        {
            SysTick -> VAL =  0x0U;
    
            while ( ! ( ( SysTick->LOAD - ( SysTick -> VAL ) ) >  300000U ) ) { }
            
            i += 1;

    
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
 * samv71q21.h --имена основных регистров
 * component_pio.h -- структура PIO
 * component_pmc.h -- структура PMC настройка PLL
 * core_cm7.h  -- содержит структуру DWT_Type
 * 
 * instance_pioa.h  свойства регистра блока выходов a
 
 ------------------------------------------------------------------------
 
 при активации прерываний в SysTick участвует функция
 
 NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)  --- прототип(неполный)
 
 NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); --- пример функции для systick
 
 SysTick_IRQn = -1
 
 
 
 */


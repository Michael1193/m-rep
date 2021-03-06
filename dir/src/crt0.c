/*
 * Pavel Kirienko, 2014 <pavel.kirienko@gmail.com>
 * ARM Cortex-M0(+)/M1/M3 startup file.
 */
#include <samv71/samv71.h>
typedef void (*funptr_t)(void);

#define fill32(start, end, filler) {   \
    unsigned *p1 = start;              \
    const unsigned * const p2 = end;   \
    while (p1 < p2)                    \
        *p1++ = filler;                \
}

extern const unsigned _etext;

extern unsigned _data;
extern unsigned _edata;

extern unsigned _bss;
extern unsigned _ebss;

extern funptr_t __init_array_start;
extern funptr_t __init_array_end;

__attribute__((noreturn))
extern int main(void);

extern void SystemInit(void);

#pragma GCC optimize 1


/**
 * Firmware entry point
 */
__attribute__((naked, noreturn))
void Reset_Handler(void)
{
    // Data section
    {
        const unsigned* tp = &_etext;
        unsigned* dp = &_data;
        while (dp < &_edata)
        {
            *dp++ = *tp++;
        }
    }

    // BSS section
    fill32(&_bss, &_ebss, 0);

    SystemInit();

    // Constructors
    {
        funptr_t* fpp = &__init_array_start;
        while (fpp < &__init_array_end)
        {
            (*fpp)();
            fpp++;
        }
    }

    (void)main();

    while (1) { }
}

/**
 * Default handlers
 */
__attribute__((weak))
void Dummy_Handler(void)
{
    while(1) { }
}

/**
 * Refer to the linker script
 */
extern void __stack_end(void);


/* Default empty handler */
void Dummy_Handler(void);

/* Cortex-M7 core handlers */
void NMI_Handler        (void) __attribute__ ((weak, alias("Dummy_Handler")));
void HardFault_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void MemManage_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void BusFault_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void UsageFault_Handler (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SVC_Handler        (void) __attribute__ ((weak, alias("Dummy_Handler")));
void DebugMon_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void PendSV_Handler     (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SysTick_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));

/* Peripherals handlers */
void SUPC_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void RSTC_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void RTC_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void RTT_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void WDT_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void PMC_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void EFC_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void UART0_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void UART1_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOA_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOB_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAMV71_PIOC_INSTANCE_
	void PIOC_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_PIOC_INSTANCE_ */
void USART0_Handler (void) __attribute__ ((weak, alias("Dummy_Handler")));
void USART1_Handler (void) __attribute__ ((weak, alias("Dummy_Handler")));
void USART2_Handler (void) __attribute__ ((weak, alias("Dummy_Handler")));
void PIOD_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAMV71_PIOE_INSTANCE_
	void PIOE_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_PIOE_INSTANCE_ */
void HSMCI_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TWIHS0_Handler (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TWIHS1_Handler (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SPI0_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void SSC_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC0_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC1_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC2_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAMV71_TC1_INSTANCE_
	void TC3_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_TC1_INSTANCE_ */
#ifdef _SAMV71_TC1_INSTANCE_
	void TC4_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_TC1_INSTANCE_ */
#ifdef _SAMV71_TC1_INSTANCE_
	void TC5_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_TC1_INSTANCE_ */
void AFEC0_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAMV71_DACC_INSTANCE_
	void DACC_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_DACC_INSTANCE_ */
void PWM0_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void ICM_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void ACC_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void USBHS_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void MCAN0_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void MCAN0_Line1_Handler  (void) __attribute__ ((weak,
		alias("Dummy_Handler")));
void MCAN1_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void MCAN1_Line1_Handler  (void) __attribute__ ((weak,
		alias("Dummy_Handler")));
void GMAC_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
#pragma weak GMACQ1_Handler=Dummy_Handler
#pragma weak GMACQ2_Handler=Dummy_Handler
void AFEC1_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAMV71_TWIHS2_INSTANCE_
	void TWIHS2_Handler (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_TWIHS2_INSTANCE_ */
void SPI1_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void QSPI_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void UART2_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void UART3_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void UART4_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAMV71_TC2_INSTANCE_
	void TC6_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_TC2_INSTANCE_ */
#ifdef _SAMV71_TC2_INSTANCE_
	void TC7_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_TC2_INSTANCE_ */
#ifdef _SAMV71_TC2_INSTANCE_
	void TC8_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_TC2_INSTANCE_ */
void TC9_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC10_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TC11_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void MLB_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void AES_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void TRNG_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void XDMAC_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void ISI_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void PWM1_Handler   (void) __attribute__ ((weak, alias("Dummy_Handler")));
void FPU_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
#ifdef _SAMV71_SDRAMC_INSTANCE_
	void SDRAMC_Handler (void) __attribute__ ((weak, alias("Dummy_Handler")));
#endif /* _SAMV71_SDRAMC_INSTANCE_ */
void RSWDT_Handler  (void) __attribute__ ((weak, alias("Dummy_Handler")));
void CCF_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));
void CCW_Handler    (void) __attribute__ ((weak, alias("Dummy_Handler")));

/* Exception Table */
__attribute__ ((used, section("vectors")))
const DeviceVectors exception_table = {

	/* Configure Initial Stack Pointer, using linker-generated symbols */
	.pvStack = (void *) (&__stack_end),

	.pfnReset_Handler      = (void *) Reset_Handler,
	.pfnNMI_Handler        = (void *) NMI_Handler,
	.pfnHardFault_Handler  = (void *) HardFault_Handler,
	.pfnMemManage_Handler  = (void *) MemManage_Handler,
	.pfnBusFault_Handler   = (void *) BusFault_Handler,
	.pfnUsageFault_Handler = (void *) UsageFault_Handler,
	.pfnReserved1_Handler  = (void *) (0UL),         /* Reserved */
	.pfnReserved2_Handler  = (void *) (0UL),         /* Reserved */
	.pfnReserved3_Handler  = (void *) (0UL),         /* Reserved */
	.pfnReserved4_Handler  = (void *) (0UL),         /* Reserved */
	.pfnSVC_Handler        = (void *) SVC_Handler,
	.pfnDebugMon_Handler   = (void *) DebugMon_Handler,
	.pfnReserved5_Handler  = (void *) (0UL),         /* Reserved */
	.pfnPendSV_Handler     = (void *) PendSV_Handler,
	.pfnSysTick_Handler    = (void *) SysTick_Handler,

	/* Configurable interrupts */
	.pfnSUPC_Handler   = (void *) SUPC_Handler,  /* 0  Supply Controller */
	.pfnRSTC_Handler   = (void *) RSTC_Handler,  /* 1  Reset Controller */
	.pfnRTC_Handler    = (void *) RTC_Handler,   /* 2  Real Time Clock */
	.pfnRTT_Handler    = (void *) RTT_Handler,   /* 3  Real Time Timer */
	.pfnWDT_Handler    = (void *) WDT_Handler,   /* 4  Watchdog Timer */
	.pfnPMC_Handler    = (void *) PMC_Handler,   /* 5  Power Management Controller */
	.pfnEFC_Handler    = (void *) EFC_Handler,   /* 6  Enhanced Embedded Flash Controller */
	.pfnUART0_Handler  = (void *) UART0_Handler, /* 7  UART 0 */
	.pfnUART1_Handler  = (void *) UART1_Handler, /* 8  UART 1 */
	.pvReserved9       = (void *) (0UL),         /* 9  Reserved */
	.pfnPIOA_Handler   = (void *) PIOA_Handler,  /* 10 Parallel I/O Controller A */
	.pfnPIOB_Handler   = (void *) PIOB_Handler,  /* 11 Parallel I/O Controller B */
#ifdef _SAMV71_PIOC_INSTANCE_
	.pfnPIOC_Handler   = (void *) PIOC_Handler,  /* 12 Parallel I/O Controller C */
#else
	.pvReserved12      = (void *) (0UL),         /* 12 Reserved */
#endif /* _SAMV71_PIOC_INSTANCE_ */
	.pfnUSART0_Handler = (void *) USART0_Handler, /* 13 USART 0 */
	.pfnUSART1_Handler = (void *) USART1_Handler, /* 14 USART 1 */
	.pfnUSART2_Handler = (void *) USART2_Handler, /* 15 USART 2 */
	.pfnPIOD_Handler   = (void *) PIOD_Handler,  /* 16 Parallel I/O Controller D */
#ifdef _SAMV71_PIOE_INSTANCE_
	.pfnPIOE_Handler   = (void *) PIOE_Handler,  /* 17 Parallel I/O Controller E */
#else
	.pvReserved17      = (void *) (0UL),         /* 17 Reserved */
#endif /* _SAMV71_PIOE_INSTANCE_ */
	.pfnHSMCI_Handler  = (void *) HSMCI_Handler, /* 18 Multimedia Card Interface */
	.pfnTWIHS0_Handler = (void *) TWIHS0_Handler, /* 19 Two Wire Interface 0 HS */
	.pfnTWIHS1_Handler = (void *) TWIHS1_Handler, /* 20 Two Wire Interface 1 HS */
	.pfnSPI0_Handler   = (void *) SPI0_Handler,  /* 21 Serial Peripheral Interface 0 */
	.pfnSSC_Handler    = (void *) SSC_Handler,   /* 22 Synchronous Serial Controller */
	.pfnTC0_Handler    = (void *) TC0_Handler,   /* 23 Timer/Counter 0 */
	.pfnTC1_Handler    = (void *) TC1_Handler,   /* 24 Timer/Counter 1 */
	.pfnTC2_Handler    = (void *) TC2_Handler,   /* 25 Timer/Counter 2 */
#ifdef _SAMV71_TC1_INSTANCE_
	.pfnTC3_Handler    = (void *) TC3_Handler,   /* 26 Timer/Counter 3 */
#else
	.pvReserved26      = (void *) (0UL),         /* 26 Reserved */
#endif /* _SAMV71_TC1_INSTANCE_ */
#ifdef _SAMV71_TC1_INSTANCE_
	.pfnTC4_Handler    = (void *) TC4_Handler,   /* 27 Timer/Counter 4 */
#else
	.pvReserved27      = (void *) (0UL),         /* 27 Reserved */
#endif /* _SAMV71_TC1_INSTANCE_ */
#ifdef _SAMV71_TC1_INSTANCE_
	.pfnTC5_Handler    = (void *) TC5_Handler,   /* 28 Timer/Counter 5 */
#else
	.pvReserved28      = (void *) (0UL),         /* 28 Reserved */
#endif /* _SAMV71_TC1_INSTANCE_ */
	.pfnAFEC0_Handler  = (void *) AFEC0_Handler, /* 29 Analog Front End 0 */
#ifdef _SAMV71_DACC_INSTANCE_
	.pfnDACC_Handler   = (void *) DACC_Handler,  /* 30 Digital To Analog Converter */
#else
	.pvReserved30      = (void *) (0UL),         /* 30 Reserved */
#endif /* _SAMV71_DACC_INSTANCE_ */
	.pfnPWM0_Handler   = (void *) PWM0_Handler,  /* 31 Pulse Width Modulation 0 */
	.pfnICM_Handler    = (void *) ICM_Handler,   /* 32 Integrity Check Monitor */
	.pfnACC_Handler    = (void *) ACC_Handler,   /* 33 Analog Comparator */
	.pfnUSBHS_Handler  = (void *) USBHS_Handler, /* 34 USB Host / Device Controller */
	.pfnMCAN0_Handler  = (void *) MCAN0_Handler, /* 35 MCAN Controller 0 */
	.pfnMCAN0_Line1_Handler = (void *) MCAN0_Line1_Handler, /* 36 CAN Controller 0 - Line 1  */
	.pfnMCAN1_Handler  = (void *) MCAN1_Handler, /* 37 MCAN Controller 1 */
	.pfnMCAN1_Line1_Handler = (void *) MCAN1_Line1_Handler, /* 38 CAN Controller 1 - Line 1  */
	.pfnGMAC_Handler   = (void *) GMAC_Handler,  /* 39 Ethernet MAC */
	.pfnAFEC1_Handler  = (void *) AFEC1_Handler, /* 40 Analog Front End 1 */
#ifdef _SAMV71_TWIHS2_INSTANCE_
	.pfnTWIHS2_Handler = (void *) TWIHS2_Handler, /* 41 Two Wire Interface 2 HS */
#else
	.pvReserved41      = (void *) (0UL),         /* 41 Reserved */
#endif /* _SAMV71_TWIHS2_INSTANCE_ */
	.pfnSPI1_Handler   = (void *) SPI1_Handler,  /* 42 Serial Peripheral Interface 1 */
	.pfnQSPI_Handler   = (void *) QSPI_Handler,  /* 43 Quad I/O Serial Peripheral Interface */
	.pfnUART2_Handler  = (void *) UART2_Handler, /* 44 UART 2 */
	.pfnUART3_Handler  = (void *) UART3_Handler, /* 45 UART 3 */
	.pfnUART4_Handler  = (void *) UART4_Handler, /* 46 UART 4 */
#ifdef _SAMV71_TC2_INSTANCE_
	.pfnTC6_Handler    = (void *) TC6_Handler,   /* 47 Timer/Counter 6 */
#else
	.pvReserved47      = (void *) (0UL),         /* 47 Reserved */
#endif /* _SAMV71_TC2_INSTANCE_ */
#ifdef _SAMV71_TC2_INSTANCE_
	.pfnTC7_Handler    = (void *) TC7_Handler,   /* 48 Timer/Counter 7 */
#else
	.pvReserved48      = (void *) (0UL),         /* 48 Reserved */
#endif /* _SAMV71_TC2_INSTANCE_ */
#ifdef _SAMV71_TC2_INSTANCE_
	.pfnTC8_Handler    = (void *) TC8_Handler,   /* 49 Timer/Counter 8 */
#else
	.pvReserved49      = (void *) (0UL),         /* 49 Reserved */
#endif /* _SAMV71_TC2_INSTANCE_ */
	.pfnTC9_Handler    = (void *) TC9_Handler,   /* 50 Timer/Counter 9 */
	.pfnTC10_Handler   = (void *) TC10_Handler,  /* 51 Timer/Counter 10 */
	.pfnTC11_Handler   = (void *) TC11_Handler,  /* 52 Timer/Counter 11 */
	.pfnMLB_Handler    = (void *) MLB_Handler,   /* 53 MediaLB */
	.pvReserved54      = (void *) (0UL),         /* 54 Reserved */
	.pvReserved55      = (void *) (0UL),         /* 55 Reserved */
	.pfnAES_Handler    = (void *) AES_Handler,   /* 56 AES */
	.pfnTRNG_Handler   = (void *) TRNG_Handler,  /* 57 True Random Generator */
	.pfnXDMAC_Handler  = (void *) XDMAC_Handler, /* 58 DMA */
	.pfnISI_Handler    = (void *) ISI_Handler,   /* 59 Camera Interface */
	.pfnPWM1_Handler   = (void *) PWM1_Handler,  /* 60 Pulse Width Modulation 1 */
	.pvReserved61      = (void *) (0UL),         /* 61 Reserved */
#ifdef _SAMV71_SDRAMC_INSTANCE_
	.pfnSDRAMC_Handler = (void *) SDRAMC_Handler, /* 62 SDRAM Controller */
#else
	.pvReserved62      = (void *) (0UL),         /* 62 Reserved */
#endif /* _SAMV71_SDRAMC_INSTANCE_ */
	.pfnRSWDT_Handler  = (void *) RSWDT_Handler  /* 63 Reinforced Secure Watchdog Timer */
};




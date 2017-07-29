/*
 * Pavel Kirienko, 2014 <pavel.kirienko@gmail.com>
 * Linker script for LPC11C24
 */

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x00400000, LENGTH = 0x00200000
  RAM (rwx) : ORIGIN = 0x20400000, LENGTH = 0x00060000
  /*sdram(rwx): ORIGIN = 0x70000000, LENGTH = 0x00200000*/
}

ENTRY(Reset_Handler)

SECTIONS
{
    . = 0x00400000;
    _text = .;

    startup :
    {
        KEEP(*(vectors))
    } > FLASH

    constructors : ALIGN(4) SUBALIGN(4)
    {
        PROVIDE(__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        PROVIDE(__init_array_end = .);
    } > FLASH

    /* NO DESTRUCTORS */

    .text :
    {
        *(.text.startup.*)
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        *(.glue_7t)
        *(.glue_7)
        *(.gcc*)
    } > FLASH

    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > FLASH

    .ARM.exidx : {
        PROVIDE(__exidx_start = .);
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        PROVIDE(__exidx_end = .);
     } > FLASH

    .eh_frame_hdr :
    {
        *(.eh_frame_hdr)
    } > FLASH

    .eh_frame : ONLY_IF_RO
    {
        *(.eh_frame)
    } > FLASH

    .textalign : ONLY_IF_RO
    {
        . = ALIGN(8);
    } > FLASH

    . = ALIGN(4);
    _etext = .;
    _textdata = _etext;

    .data :
    {
        . = ALIGN(4);
        PROVIDE(_data = .);
        *(.data)
        . = ALIGN(4);
        *(.data.*)
        . = ALIGN(4);
        *(.ramtext)
        . = ALIGN(4);
        PROVIDE(_edata = .);
    } > RAM AT > FLASH

    .bss :
    {
        . = ALIGN(4);
        PROVIDE(_bss = .);
        *(.bss)
        . = ALIGN(4);
        *(.bss.*)
        . = ALIGN(4);
        *(COMMON)
        . = ALIGN(4);
        PROVIDE(_ebss = .);
    } > RAM

    PROVIDE(__stack_end = ORIGIN(RAM) + LENGTH(RAM));
}

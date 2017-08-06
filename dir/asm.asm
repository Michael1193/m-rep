
build/firmware.elf:     file format elf32-littlearm


Disassembly of section .text:

00400140 <ACC_Handler>:
  400140:	e7fe      	b.n	400140 <ACC_Handler>
	...

00400144 <Reset_Handler>:
  400144:	4b18      	ldr	r3, [pc, #96]	; (4001a8 <Reset_Handler+0x64>)
  400146:	4a19      	ldr	r2, [pc, #100]	; (4001ac <Reset_Handler+0x68>)
  400148:	429a      	cmp	r2, r3
  40014a:	d20d      	bcs.n	400168 <Reset_Handler+0x24>
  40014c:	4613      	mov	r3, r2
  40014e:	4818      	ldr	r0, [pc, #96]	; (4001b0 <Reset_Handler+0x6c>)
  400150:	1a80      	subs	r0, r0, r2
  400152:	f020 0003 	bic.w	r0, r0, #3
  400156:	3004      	adds	r0, #4
  400158:	4410      	add	r0, r2
  40015a:	4a16      	ldr	r2, [pc, #88]	; (4001b4 <Reset_Handler+0x70>)
  40015c:	f852 1b04 	ldr.w	r1, [r2], #4
  400160:	f843 1b04 	str.w	r1, [r3], #4
  400164:	4283      	cmp	r3, r0
  400166:	d1f9      	bne.n	40015c <Reset_Handler+0x18>
  400168:	4b13      	ldr	r3, [pc, #76]	; (4001b8 <Reset_Handler+0x74>)
  40016a:	4a14      	ldr	r2, [pc, #80]	; (4001bc <Reset_Handler+0x78>)
  40016c:	429a      	cmp	r2, r3
  40016e:	d20b      	bcs.n	400188 <Reset_Handler+0x44>
  400170:	4613      	mov	r3, r2
  400172:	4a13      	ldr	r2, [pc, #76]	; (4001c0 <Reset_Handler+0x7c>)
  400174:	1ad2      	subs	r2, r2, r3
  400176:	f022 0203 	bic.w	r2, r2, #3
  40017a:	3204      	adds	r2, #4
  40017c:	441a      	add	r2, r3
  40017e:	2100      	movs	r1, #0
  400180:	f843 1b04 	str.w	r1, [r3], #4
  400184:	4293      	cmp	r3, r2
  400186:	d1fb      	bne.n	400180 <Reset_Handler+0x3c>
  400188:	f000 f820 	bl	4001cc <SystemInit>
  40018c:	4b0d      	ldr	r3, [pc, #52]	; (4001c4 <Reset_Handler+0x80>)
  40018e:	4a0e      	ldr	r2, [pc, #56]	; (4001c8 <Reset_Handler+0x84>)
  400190:	429a      	cmp	r2, r3
  400192:	d206      	bcs.n	4001a2 <Reset_Handler+0x5e>
  400194:	4614      	mov	r4, r2
  400196:	461d      	mov	r5, r3
  400198:	f854 3b04 	ldr.w	r3, [r4], #4
  40019c:	4798      	blx	r3
  40019e:	42ac      	cmp	r4, r5
  4001a0:	d3fa      	bcc.n	400198 <Reset_Handler+0x54>
  4001a2:	f000 f827 	bl	4001f4 <main>
  4001a6:	bf00      	nop
  4001a8:	20400000 	.word	0x20400000
  4001ac:	20400000 	.word	0x20400000
  4001b0:	203fffff 	.word	0x203fffff
  4001b4:	00400238 	.word	0x00400238
  4001b8:	20400000 	.word	0x20400000
  4001bc:	20400000 	.word	0x20400000
  4001c0:	203fffff 	.word	0x203fffff
  4001c4:	00400140 	.word	0x00400140
  4001c8:	00400140 	.word	0x00400140

004001cc <SystemInit>:
  4001cc:	4770      	bx	lr
	...

004001d0 <_Z6dalay1v>:
  4001d0:	b082      	sub	sp, #8
  4001d2:	9a01      	ldr	r2, [sp, #4]
  4001d4:	4b06      	ldr	r3, [pc, #24]	; (4001f0 <_Z6dalay1v+0x20>)
  4001d6:	429a      	cmp	r2, r3
  4001d8:	dc07      	bgt.n	4001ea <_Z6dalay1v+0x1a>
  4001da:	461a      	mov	r2, r3
  4001dc:	bf00      	nop
  4001de:	9b01      	ldr	r3, [sp, #4]
  4001e0:	3301      	adds	r3, #1
  4001e2:	9301      	str	r3, [sp, #4]
  4001e4:	9b01      	ldr	r3, [sp, #4]
  4001e6:	4293      	cmp	r3, r2
  4001e8:	ddf8      	ble.n	4001dc <_Z6dalay1v+0xc>
  4001ea:	b002      	add	sp, #8
  4001ec:	4770      	bx	lr
  4001ee:	bf00      	nop
  4001f0:	000f423f 	.word	0x000f423f

004001f4 <main>:
  4001f4:	b508      	push	{r3, lr}
  4001f6:	f7ff ffeb 	bl	4001d0 <_Z6dalay1v>
  4001fa:	f44f 6280 	mov.w	r2, #1024	; 0x400
  4001fe:	4b09      	ldr	r3, [pc, #36]	; (400224 <main+0x30>)
  400200:	601a      	str	r2, [r3, #0]
  400202:	f44f 0300 	mov.w	r3, #8388608	; 0x800000
  400206:	4a08      	ldr	r2, [pc, #32]	; (400228 <main+0x34>)
  400208:	6013      	str	r3, [r2, #0]
  40020a:	32a4      	adds	r2, #164	; 0xa4
  40020c:	6013      	str	r3, [r2, #0]
  40020e:	3a94      	subs	r2, #148	; 0x94
  400210:	6013      	str	r3, [r2, #0]
  400212:	4e06      	ldr	r6, [pc, #24]	; (40022c <main+0x38>)
  400214:	461c      	mov	r4, r3
  400216:	4d06      	ldr	r5, [pc, #24]	; (400230 <main+0x3c>)
  400218:	6034      	str	r4, [r6, #0]
  40021a:	602c      	str	r4, [r5, #0]
  40021c:	f7ff ffd8 	bl	4001d0 <_Z6dalay1v>
  400220:	e7fa      	b.n	400218 <main+0x24>
  400222:	bf00      	nop
  400224:	400e0610 	.word	0x400e0610
  400228:	400e0e00 	.word	0x400e0e00
  40022c:	400e0e34 	.word	0x400e0e34
  400230:	400e0e30 	.word	0x400e0e30

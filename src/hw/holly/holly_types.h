#ifndef HOLLY_TYPES_H
#define HOLLY_TYPES_H

#include <stdint.h>

// registers
enum {
#define HOLLY_REG(addr, name, flags, default) name = (addr - 0x005f0000) >> 2,
#include "hw/holly/holly_regs.inc"
#undef HOLLY_REG
  NUM_HOLLY_REGS = 0x00008000 >> 2,
};

// interrupts
#define HOLLY_INTERRUPT(type, irq) (((uint64_t)type << 32) | irq)
#define HOLLY_INTERRUPT_TYPE(intr) (intr >> 32)
#define HOLLY_INTERRUPT_IRQ(intr) ((uint32_t)intr)

enum holly_interrupt_type {
  HOLLY_INTC_NRM = 0x1,
  HOLLY_INTC_EXT = 0x2,
  HOLLY_INTC_ERR = 0x3
};

typedef uint64_t holly_interrupt_t;

//
// HOLLY_INTC_NRM
//
// Video End of Render
#define HOLLY_INTC_PCEOVINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x1)
// ISP End of Render
#define HOLLY_INTC_PCEOIINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x2)
// TSP End of Render
#define HOLLY_INTC_PCEOTINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x4)
// VBlank In
#define HOLLY_INTC_PCVIINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x8)
// VBlank Out
#define HOLLY_INTC_PCVOINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x10)
// HBlank In
#define HOLLY_INTC_PCHIINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x20)
// End Of YUV Data Storage
#define HOLLY_INTC_TAYUVINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x40)
// End Of Opaque List Storage
#define HOLLY_INTC_TAEOINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x80)
// End Of Opaque Modifier Volume List Storage
#define HOLLY_INTC_TAEOMINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x100)
// End Of Translucent List Storage
#define HOLLY_INTC_TAETINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x200)
// End Of Translucent Modifier Volume List Storage
#define HOLLY_INTC_TAETMINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x400)
// PVR End of DMA
#define HOLLY_INTC_PIDEINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x800)
// MAPLE End of DMA
#define HOLLY_INTC_MDEINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x1000)
// MAPLE VBlank Over
#define HOLLY_INTC_MVOINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x2000)
// G1 End of DMA
#define HOLLY_INTC_G1DEINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x4000)
// G2 End of AICA-DMA
#define HOLLY_INTC_G2DEAINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x8000)
// G2 End of Ext-DMA1
#define HOLLY_INTC_G2DE1INT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x10000)
// G2 End of Ext-DMA2
#define HOLLY_INTC_G2DE2INT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x20000)
// G2 End of Dev-DMA
#define HOLLY_INTC_G2DEDINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x40000)
// End of ch2-DMA
#define HOLLY_INTC_DTDE2INT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x80000)
// End of Sort-DMA
#define HOLLY_INTC_DTDESINT HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x100000)
// End Of Punch Through List Storage
#define HOLLY_INTC_TAEPTIN HOLLY_INTERRUPT(HOLLY_INTC_NRM, 0x200000)
//
// HOLLY_INTC_EXT
//
// From GD-ROM Drive
#define HOLLY_INTC_G1GDINT HOLLY_INTERRUPT(HOLLY_INTC_EXT, 0x1)
// From AICA
#define HOLLY_INTC_G2AICINT HOLLY_INTERRUPT(HOLLY_INTC_EXT, 0x2)
// From Modem
#define HOLLY_INTC_G2MDMINT HOLLY_INTERRUPT(HOLLY_INTC_EXT, 0x4)
// From External Device
#define HOLLY_INTC_G2EXTINT HOLLY_INTERRUPT(HOLLY_INTC_EXT, 0x8)
//
// HOLLY_INTC_ERR
//
// ISP Out of Cache
#define HOLLY_INTC_PCIOCINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x1)
// Hazard Processing of Strip Buffer
#define HOLLY_INTC_PCHZDINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x2)
// ISP/TSP Parameter Limit Address
#define HOLLY_INTC_TAPOFINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x4)
// Object List Limit Address
#define HOLLY_INTC_TALOFINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x8)
// Illegal Parameter Input
#define HOLLY_INTC_TAIPINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x10)
// TA FIFO Over Flow
#define HOLLY_INTC_TAFOFINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x20)
// PVR Illegal Address Set
#define HOLLY_INTC_PIIAINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x40)
// PVR DMA Over Run
#define HOLLY_INTC_PIORINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x80)
// MAPLE Illegal Address Set
#define HOLLY_INTC_MIAINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x100)
// MAPLE DMA Over Run
#define HOLLY_INTC_MORINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x200)
// MAPLE Write FIFO Overf Flow
#define HOLLY_INTC_MFOFINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x400)
// MAPLE Illegal Command
#define HOLLY_INTC_MICINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x800)
// G1 Illegal Address Set
#define HOLLY_INTC_G1IAINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x1000)
// G1 DMA Over Run
#define HOLLY_INTC_G1ORINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x2000)
// G1 Access at DMA
#define HOLLY_INTC_G1ATINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x4000)
// G2 AICA-DMA Illegal Address Set
#define HOLLY_INTC_G2IAAINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x8000)
// G2 Ext1-DMA Illegal Address Set
#define HOLLY_INTC_G2IA1INT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x10000)
// G2 Ext2-DMA Illegal Address Set
#define HOLLY_INTC_G2IA2INT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x20000)
// G2 Dev-DMA Illegal Address Set
#define HOLLY_INTC_G2IADINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x40000)
// G2 AICA-DMA Over Run
#define HOLLY_INTC_G2ORAINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x80000)
// G2 Ext1-DMA Over Run
#define HOLLY_INTC_G2OR1INT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x100000)
// G2 Ext2-DMA Over Run
#define HOLLY_INTC_G2OR2INT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x200000)
// G2 Dev-DMA Over Run
#define HOLLY_INTC_G2ORDINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x400000)
// G2 AICA-DMA Time Out
#define HOLLY_INTC_G2TOAINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x800000)
// G2 Ext1-DMA Time Out
#define HOLLY_INTC_G2TO1INT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x1000000)
// G2 Ext2-DMA Time Out
#define HOLLY_INTC_G2TO2INT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x2000000)
// G2 Dev-DMA Time Out
#define HOLLY_INTC_G2TODINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x4000000)
// G2 Time Out in CPU Accessing
#define HOLLY_INTC_G2TOCINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x8000000)
// Sort-DMA Command Error
#define HOLLY_INTC_DTCESINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x10000000)
#define HOLLY_INTC_RESERVED1 HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x20000000)
#define HOLLY_INTC_RESERVED2 HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x40000000)
// SH4 Accessing to Inhibited Area
#define HOLLY_INTC_CIHINT HOLLY_INTERRUPT(HOLLY_INTC_ERR, 0x80000000)

#endif

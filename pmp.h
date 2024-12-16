#define PMP_R     0x01
#define PMP_W     0x02
#define PMP_X     0x04
#define PMP_A     0x18
#define PMP_L     0x80
#define PMP_SHIFT 2

#define PMP_TOR   0x08
#define PMP_NA4   0x10
#define PMP_NAPOT 0x18

#define CSR_PMPCFG0 0x3A0
#define CSR_PMPADDR0 0x3B0

#define CSR_MTVEC 0x305
#define CSR_MCAUSE 0x342
#define CSR_MEPC 0x341
#define CSR_MTVAL 0x343
#define CSR_MSTATUS 0x300
           
#define PMP_ENTRY_SET(ENTRY, ADDR, CFG) do {  \
    RV_WRITE_CSR((CSR_PMPADDR0) + (ENTRY), (ADDR) >> (PMP_SHIFT));    \
    RV_SET_CSR((CSR_PMPCFG0) + (ENTRY)/4, ((CFG)&0xFF) << (ENTRY%4)*8); \
    } while(0)
    
#define RV_WRITE_CSR(reg, val) ({ \
  asm volatile ("csrw " _CSR_STRINGIFY(reg) ", %0" :: "rK"(val)); })
  
#define RV_SET_CSR(reg, bit) ({ unsigned long __tmp; \
  asm volatile ("csrrs %0, " _CSR_STRINGIFY(reg) ", %1" : "=r"(__tmp) : "rK"(bit)); __tmp; })

#define _CSR_STRINGIFY(REG) #REG

#define PMPADDR_NAPOT(START, END) ({ \
    ((uint32_t)(((START)) | (((END)-(START)-1)>>1))); \
})

#define RV_CLEAR_CSR(reg, bit) ({ unsigned long __tmp; \
  asm volatile ("csrrc %0, " _CSR_STRINGIFY(reg) ", %1" : "=r"(__tmp) : "rK"(bit)); __tmp; })
  
#define PMP_ENTRY_CFG_RESET(ENTRY) do {\
    RV_CLEAR_CSR((CSR_PMPCFG0) + (ENTRY)/4, (0xFF) << (ENTRY%4)*8); \
    } while(0)

#define RV_READ_CSR(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " _CSR_STRINGIFY(reg) : "=r"(__tmp)); __tmp; })

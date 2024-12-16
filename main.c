// SPDX-FileCopyrightText: 2022-2023 Cesanta Software Limited
// SPDX-License-Identifier: MIT

#include "hal.h"
#include "pmp.h"

void SystemInit(void) {  // Called automatically by startup code
  clock_init();
}

void esp_cpu_configure_region_protection(void)
{
    //const unsigned NONE    = PMP_L | PMP_NAPOT;
    const unsigned R       = PMP_L | PMP_NAPOT | PMP_R;
    //const unsigned RW      = PMP_L | PMP_NAPOT | PMP_R | PMP_W;
    //const unsigned RX      = PMP_L | PMP_NAPOT | PMP_R | PMP_X;
    //const unsigned RWX     = PMP_L | PMP_NAPOT | PMP_R | PMP_W | PMP_X;

    const uint32_t pmpaddr = PMPADDR_NAPOT(0x20000000, 0x30000000);
    PMP_ENTRY_SET(0, pmpaddr, R);
}

int main(){

    esp_cpu_configure_region_protection();
    
    unsigned long pmpcfg0   = RV_READ_CSR(pmpcfg0);
    unsigned long pmpcfg1   = RV_READ_CSR(pmpcfg1);
    unsigned long pmpcfg2   = RV_READ_CSR(pmpcfg2);
    unsigned long pmpcfg3   = RV_READ_CSR(pmpcfg3);   
     
    unsigned long pmpaddr0  = RV_READ_CSR(pmpaddr0);
	unsigned long pmpaddr1  = RV_READ_CSR(pmpaddr1);
	unsigned long pmpaddr2  = RV_READ_CSR(pmpaddr2);
	unsigned long pmpaddr3  = RV_READ_CSR(pmpaddr3);
	unsigned long pmpaddr4  = RV_READ_CSR(pmpaddr4);
	unsigned long pmpaddr5  = RV_READ_CSR(pmpaddr5);
	unsigned long pmpaddr6  = RV_READ_CSR(pmpaddr6);
	unsigned long pmpaddr7  = RV_READ_CSR(pmpaddr7);
	unsigned long pmpaddr8  = RV_READ_CSR(pmpaddr8);
	unsigned long pmpaddr9  = RV_READ_CSR(pmpaddr9);
	unsigned long pmpaddr10 = RV_READ_CSR(pmpaddr10);
	unsigned long pmpaddr11 = RV_READ_CSR(pmpaddr11);
	unsigned long pmpaddr12 = RV_READ_CSR(pmpaddr12);
	unsigned long pmpaddr13 = RV_READ_CSR(pmpaddr13);
	unsigned long pmpaddr14 = RV_READ_CSR(pmpaddr14);
	unsigned long pmpaddr15 = RV_READ_CSR(pmpaddr15);

    uint32_t *test_addr = (uint32_t *)0x22000000;

    *test_addr = 0x08;

    printf("pmpcfg0=%p, pmpcfg1=%p, pmpcfg2=%p, pmpcfg3=%p, pmpaddr0=%p, pmpaddr1=%p, pmpaddr2=%p, pmpaddr3=%p, pmpaddr4=%p, pmpaddr5=%p, pmpaddr6=%p, pmpaddr7=%p, pmpaddr8=%p, pmpaddr9=%p, pmpaddr10=%p, pmpaddr11=%p, pmpaddr12=%p, pmpaddr13=%p, pmpaddr14=%p, pmpaddr15=%p \n", (unsigned long *)pmpcfg0, (void*)pmpcfg1, (void*)pmpcfg2, (void*)pmpcfg3, (void*)pmpaddr0, (void*)pmpaddr1, (void*)pmpaddr2, (void*)pmpaddr3, (void*)pmpaddr4, (void*)pmpaddr5, (void*)pmpaddr6, (void*)pmpaddr7, (void*)pmpaddr8, (void*)pmpaddr9, (void*)pmpaddr10, (void*)pmpaddr11, (void*)pmpaddr12, (void*)pmpaddr13, (void*)pmpaddr14, (void*)pmpaddr15);
    

    return 0;
}

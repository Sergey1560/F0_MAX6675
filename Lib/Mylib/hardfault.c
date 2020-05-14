#include "hardfault.h"

uint8_t hf_exit = 0;
 
void __attribute__((optimize("O0"))) hard_fault_handl_c (unsigned int * pStack){
  
  if (NVIC_HFSR & (1u << 31)) {
    NVIC_HFSR |=  (1u << 31);     // Reset Hard Fault status
    *(pStack + 6u) += 2u;         // PC is located on stack at SP + 24 bytes. Increment PC by 2 to skip break instruction.
    return;                       // Return to interrupted application
  }

  //
  // Read NVIC registers
  //
  HardFaultRegs.syshndctrl.byte = SYSHND_CTRL;  // System Handler Control and State Register
  HardFaultRegs.mfsr.byte       = NVIC_MFSR;    // Memory Fault Status Register
  HardFaultRegs.bfsr.byte       = NVIC_BFSR;    // Bus Fault Status Register
  HardFaultRegs.bfar            = NVIC_BFAR;    // Bus Fault Manage Address Register
  HardFaultRegs.ufsr.byte       = NVIC_UFSR;    // Usage Fault Status Register
  HardFaultRegs.hfsr.byte       = NVIC_HFSR;    // Hard Fault Status Register
  HardFaultRegs.dfsr.byte       = NVIC_DFSR;    // Debug Fault Status Register
  HardFaultRegs.afsr            = NVIC_AFSR;    // Auxiliary Fault Status Register
    
  hf_exit = 0;
  while (!hf_exit){
    __NOP();
  };


  HardFaultRegs.SavedRegs.r0       = pStack[0];  // Register R0
  HardFaultRegs.SavedRegs.r1       = pStack[1];  // Register R1
  HardFaultRegs.SavedRegs.r2       = pStack[2];  // Register R2
  HardFaultRegs.SavedRegs.r3       = pStack[3];  // Register R3
  HardFaultRegs.SavedRegs.r12      = pStack[4];  // Register R12
  HardFaultRegs.SavedRegs.lr       = pStack[5];  // Link register LR
  HardFaultRegs.SavedRegs.pc       = pStack[6];  // Program counter PC
  HardFaultRegs.SavedRegs.psr.byte = pStack[7];  // Program status word PSR

  hf_exit = 0;
  while (!hf_exit){
    __NOP();
  };

}



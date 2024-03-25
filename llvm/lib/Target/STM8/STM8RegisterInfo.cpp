//===-- STM8RegisterInfo.cpp - STM8 Register Information ------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the STM8 implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "STM8RegisterInfo.h"

#include "llvm/ADT/BitVector.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/IR/Function.h"

#include "MCTargetDesc/STM8MCTargetDesc.h"

#define GET_REGINFO_TARGET_DESC
#include "STM8GenRegisterInfo.inc"

namespace llvm {

/// Initialize register info
/// as there's no return address register, we Initialize
/// that with 0
STM8RegisterInfo::STM8RegisterInfo() : STM8GenRegisterInfo(0) {}

const MCPhysReg *
STM8RegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  // there are no callee saved regs, everything is caller saved
  static const MCPhysReg EmptySavedRegs[] = {0};
  return EmptySavedRegs;
}

BitVector STM8RegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());

  Reserved.set(STM8::R_SP);

  return Reserved;
}

const TargetRegisterClass *
STM8RegisterInfo::getPointerRegClass(const MachineFunction &MF,
                                     unsigned Kind) const {
  // These are all registers that are used as a pointer (not exclusively)
  // e.g. JP (X) or JP (Y)
  return &STM8::GPR16RegClass;
}

bool STM8RegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator MI,
                                           int SPAdj, unsigned FIOperandNum,
                                           RegScavenger *RS) const {
  // TODO: I've no idea yet what this does - smth. smth stack I think
  return false;
}

Register STM8RegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return STM8::R_SP;
}

} // end of namespace llvm

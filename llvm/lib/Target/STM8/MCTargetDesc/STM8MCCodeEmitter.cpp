//===-- STM8MCCodeEmitter.cpp - Convert STM8 Code to Machine Code ---------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the STM8MCCodeEmitter class.
//
//===----------------------------------------------------------------------===//

#include "STM8MCCodeEmitter.h"

#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCInstrInfo.h"

#include "MCTargetDesc/STM8MCTargetDesc.h"

namespace llvm {

void STM8MCCodeEmitter::encodeInstruction(const MCInst &MI,
                                          SmallVectorImpl<char> &CB,
                                          SmallVectorImpl<MCFixup> &Fixups,
                                          const MCSubtargetInfo &STI) const {
  const MCInstrDesc &Desc = MCII.get(MI.getOpcode());

  // Get byte count of instruction
  unsigned Size = Desc.getSize();

  assert(Size > 0 && "Instruction size cannot be zero");

  // TODO implement
}

MCCodeEmitter *createSTM8MCCodeEmitter(const MCInstrInfo &MCII,
                                       MCContext &Ctx) {
  return new STM8MCCodeEmitter(MCII, Ctx);
}

#include "STM8GenMCCodeEmitter.inc"

} // end of namespace llvm

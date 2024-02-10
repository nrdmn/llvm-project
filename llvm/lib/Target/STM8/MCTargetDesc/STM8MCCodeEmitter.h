//===-- STM8MCCodeEmitter.h - Convert STM8 Code to Machine Code -----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the STM8MCCodeEmitter class.
//
//===----------------------------------------------------------------------===//
//

#ifndef LLVM_STM8_CODE_EMITTER_H
#define LLVM_STM8_CODE_EMITTER_H

#include "llvm/MC/MCCodeEmitter.h"
#include "llvm/Support/DataTypes.h"

#define GET_INSTRINFO_OPERAND_TYPES_ENUM
#include "STM8GenInstrInfo.inc"

namespace llvm {

class MCContext;
class MCExpr;
class MCInstrInfo;
class MCOperand;

/// Writes STM8 machine code to a stream.
class STM8MCCodeEmitter : public MCCodeEmitter {
public:
  STM8MCCodeEmitter(const MCInstrInfo &MCII, MCContext &Ctx)
      : MCII(MCII), Ctx(Ctx) {}

private:
  /// TableGen'ed function to get the binary encoding for an instruction.
  uint64_t getBinaryCodeForInstr(const MCInst &MI,
                                 SmallVectorImpl<MCFixup> &Fixups,
                                 const MCSubtargetInfo &STI) const;

  void encodeInstruction(const MCInst &MI, SmallVectorImpl<char> &CB,
                         SmallVectorImpl<MCFixup> &Fixups,
                         const MCSubtargetInfo &STI) const override;

  STM8MCCodeEmitter(const STM8MCCodeEmitter &) = delete;
  void operator=(const STM8MCCodeEmitter &) = delete;

  const MCInstrInfo &MCII;
  MCContext &Ctx;
};

} // end of namespace llvm

#endif // LLVM_STM8_CODE_EMITTER_H

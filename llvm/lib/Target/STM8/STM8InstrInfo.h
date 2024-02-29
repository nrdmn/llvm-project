//===-- STM8InstrInfo.h - STM8 Instruction Information ------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the STM8 implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STM8_INSTR_INFO_H
#define LLVM_STM8_INSTR_INFO_H

#include "llvm/CodeGen/TargetInstrInfo.h"

#include "STM8RegisterInfo.h"

#define GET_INSTRINFO_HEADER
#include "STM8GenInstrInfo.inc"
#undef GET_INSTRINFO_HEADER

namespace llvm {

class STM8Subtarget;

class STM8InstrInfo : public STM8GenInstrInfo {
  const STM8RegisterInfo RI;

public:
  explicit STM8InstrInfo(STM8Subtarget &STI);

  const STM8RegisterInfo &getRegisterInfo() const { return RI; }
};

} // namespace llvm

#endif // !LLVM_STM8_INSTR_INFO_H

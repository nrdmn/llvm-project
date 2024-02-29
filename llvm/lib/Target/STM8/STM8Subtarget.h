//===-- STM8Subtarget.h - Define Subtarget for the STM8 ---------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the STM8 specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STM8_SUBTARGET_H
#define LLVM_STM8_SUBTARGET_H

#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetMachine.h"

#include "STM8FrameLowering.h"
#include "STM8ISelLowering.h"
#include "STM8InstrInfo.h"

#define GET_SUBTARGETINFO_HEADER
#include "STM8GenSubtargetInfo.inc"

namespace llvm {
/// A specific STM8 target MCU
class STM8Subtarget : public STM8GenSubtargetInfo {
  STM8FrameLowering FrameLowering;
  STM8InstrInfo InstrInfo;
  STM8TargetLowering TLInfo;
public:
  STM8Subtarget(const Triple &TT, const std::string &CPU,
                const std::string &FS, const STM8TargetMachine &TM);

  const STM8FrameLowering *getFrameLowering() const override {
    return &FrameLowering;
  }

  const STM8InstrInfo *getInstrInfo() const override { return &InstrInfo; }
  const STM8RegisterInfo *getRegisterInfo() const override {
    return &getInstrInfo()->getRegisterInfo();
  }

  const STM8TargetLowering *getTargetLowering() const override {
    return &TLInfo;
  }
};

}

#endif // !LLVM_STM8_SUBTARGET_H

//===-- STM8Subtarget.cpp - STM8 Subtarget Information --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the STM8 specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "STM8Subtarget.h"

#include "llvm/MC/TargetRegistry.h"

#define DEBUG_TYPE "stm8-subtarget"

#define GET_SUBTARGETINFO_TARGETDESC
#define GET_SUBTARGETINFO_CTOR
#include "STM8GenSubtargetInfo.inc"

namespace llvm {

STM8Subtarget::STM8Subtarget(const Triple &TT, const std::string &CPU,
                             const std::string &FS, const STM8TargetMachine &TM)
    : STM8GenSubtargetInfo(TT, CPU, /*TuneCPU*/ CPU, FS), FrameLowering(),
      TLInfo(TM, *this) {}

}

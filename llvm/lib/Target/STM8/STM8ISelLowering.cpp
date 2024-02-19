//===-- STM8ISelLowering.cpp - STM8 DAG Lowering Implementation -----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the STM8TargetLowering class.
//
//===----------------------------------------------------------------------===//

#include "STM8ISelLowering.h"
#include "STM8TargetMachine.h"

namespace llvm {

STM8TargetLowering::STM8TargetLowering(const STM8TargetMachine &TM,
                                       const STM8Subtarget &STI)
    : TargetLowering(TM), Subtarget(STI) {}

} // end of namespace llvm

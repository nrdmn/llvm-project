//===-- STM8TargetMachine.cpp - Define TargetMachine for STM8 -------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the STM8 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#include "STM8TargetMachine.h"

#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"

namespace llvm {

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSTM8Target() {
}

} // end of namespace llvm

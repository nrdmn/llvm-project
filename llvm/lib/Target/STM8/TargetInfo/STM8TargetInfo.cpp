//===-- STM8TargetInfo.cpp - STM8 Target Implementation -------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "TargetInfo/STM8TargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

namespace llvm {
Target &getTheSTM8Target() {
  static Target TheSTM8Target;
  return TheSTM8Target;
}
} // namespace llvm

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSTM8TargetInfo() {
  llvm::RegisterTarget<llvm::Triple::stm8, /*HasJIT=*/false> X(llvm::getTheSTM8Target(),
                                                    "stm8", "stm8", "stm8");
}

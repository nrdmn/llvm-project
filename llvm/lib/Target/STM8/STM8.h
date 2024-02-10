//===-- STM8.h - Top-level interface for STM8 representation ----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in the LLVM
// STM8 back-end.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_STM8_STM8_H
#define LLVM_LIB_TARGET_STM8_STM8_H

#include "llvm/Support/CodeGen.h"

namespace llvm {
  class FunctionPass;
  class STM8TargetMachine;

  FunctionPass *createSTM8ISelDag(STM8TargetMachine &TM,
                                   CodeGenOptLevel OptLevel);

} // end of namespace llvm

#endif

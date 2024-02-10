//===-- STM8MachineFuctionInfo.h - STM8 machine function info ---*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares STM8-specific per-machine-function information.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STM8_MACHINE_FUNCTION_INFO_H
#define LLVM_STM8_MACHINE_FUNCTION_INFO_H

#include "llvm/CodeGen/MachineFunction.h"

namespace llvm {

class STM8MachineFunctionInfo : public MachineFunctionInfo {
};

} // namespace llvm

#endif // LLVM_STM8_MACHINE_FUNCTION_INFO_H

//===-- STM8RegisterInfo.h - STM8 Register Information Impl -----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the STM8 implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STM8_REGISTER_INFO_H
#define LLVM_STM8_REGISTER_INFO_H

#include "llvm/CodeGen/TargetRegisterInfo.h"

#include "STM8FrameLowering.h"

#define GET_REGINFO_HEADER
#include "STM8GenRegisterInfo.inc"

namespace llvm {

/// Utilities relating to STM8 registers.
class STM8RegisterInfo : public STM8GenRegisterInfo {
};

} // end namespace llvm

#endif // LLVM_STM8_REGISTER_INFO_H

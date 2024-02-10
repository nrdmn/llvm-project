//===-- STM8RegisterInfo.cpp - STM8 Register Information ------------------===//
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

#include "STM8RegisterInfo.h"

#include "llvm/ADT/BitVector.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/IR/Function.h"

#include "MCTargetDesc/STM8MCTargetDesc.h"

#define GET_REGINFO_TARGET_DESC
#include "STM8GenRegisterInfo.inc"

namespace llvm {

} // end of namespace llvm

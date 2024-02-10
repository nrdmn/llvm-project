//===-- STM8MCTargetDesc.h - STM8 Target Descriptions -----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file provides STM8 specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STM8_MCTARGET_DESC_H
#define LLVM_STM8_MCTARGET_DESC_H

#include "llvm/Support/DataTypes.h"

#define GET_INSTRINFO_ENUM
#define GET_INSTRINFO_MC_HELPER_DECLS
#include "STM8GenInstrInfo.inc"

#define GET_REGINFO_ENUM
#include "STM8GenRegisterInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "STM8GenSubtargetInfo.inc"

#endif // LLVM_STM8_MCTARGET_DESC_H

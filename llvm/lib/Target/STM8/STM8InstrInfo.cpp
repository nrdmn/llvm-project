//===-- STM8InstrInfo.cpp - STM8 Instruction Information --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the STM8 implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#include "STM8InstrInfo.h"

using namespace llvm;

#define GET_INSTRINFO_CTOR_DTOR
#include "STM8GenInstrInfo.inc"

STM8InstrInfo::STM8InstrInfo(STM8Subtarget &STI) : STM8GenInstrInfo(), RI() {}



//===-- STM8MCTargetDesc.cpp - STM8 Target Descriptions -------------------===//
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

#include "STM8MCTargetDesc.h"

#include "llvm/MC/MCAsmBackend.h"

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSTM8TargetMC() {
}

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
#include "TargetInfo/STM8TargetInfo.h"

#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/MC/MCAsmBackend.h"

#define GET_REGINFO_MC_DESC
#include "STM8GenRegisterInfo.inc"

using namespace llvm;

static MCRegisterInfo *createSTM8MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitSTM8MCRegisterInfo(X, 0);
  return X;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSTM8TargetMC() {
  // Register the MC register info
  TargetRegistry::RegisterMCRegInfo(getTheSTM8Target(), createSTM8MCRegisterInfo);
}

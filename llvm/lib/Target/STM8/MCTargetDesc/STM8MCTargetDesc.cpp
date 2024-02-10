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
#include "STM8MCAsmInfo.h"
#include "TargetInfo/STM8TargetInfo.h"

#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/MC/MCAsmBackend.h"

#define GET_INSTRINFO_MC_DESC
#include "STM8GenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "STM8GenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "STM8GenRegisterInfo.inc"

using namespace llvm;

static MCAsmInfo *createSTM8MCAsmInfo(const MCRegisterInfo &MRI,
                                      const Triple &TT,
                                      const MCTargetOptions &Options) {
  MCAsmInfo *MAI = new STM8MCAsmInfo(TT);
  return MAI;
}

static MCInstrInfo *createSTM8MCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitSTM8MCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createSTM8MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitSTM8MCRegisterInfo(X, 0);
  return X;
}

static MCSubtargetInfo *createSTM8MCSubtargetInfo(const Triple &TT,
                                                  StringRef CPU, StringRef FS) {
  return createSTM8MCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

namespace llvm {

MCCodeEmitter *createSTM8MCCodeEmitter(const MCInstrInfo &MCII,
                                       MCContext &Ctx);

} // end of namespace llvm

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSTM8TargetMC() {
  // Register the MC asm info
  TargetRegistry::RegisterMCAsmInfo(getTheSTM8Target(), createSTM8MCAsmInfo);

  // Register the MC instruction info
  TargetRegistry::RegisterMCInstrInfo(getTheSTM8Target(), createSTM8MCInstrInfo);

  // Register the MC register info
  TargetRegistry::RegisterMCRegInfo(getTheSTM8Target(), createSTM8MCRegisterInfo);

  // Register the MC subtarget info
  TargetRegistry::RegisterMCSubtargetInfo(getTheSTM8Target(), createSTM8MCSubtargetInfo);

  // Register the MC Code Emitter
  TargetRegistry::RegisterMCCodeEmitter(getTheSTM8Target(), createSTM8MCCodeEmitter);
}

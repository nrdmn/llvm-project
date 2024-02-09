//===-- STM8MCAsmInfo.cpp - STM8 asm properties -----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the STM8MCAsmInfo properties.
//
//===----------------------------------------------------------------------===//

#include "STM8MCAsmInfo.h"
namespace llvm {

void STM8MCAsmInfo::anchor() { }

STM8MCAsmInfo::STM8MCAsmInfo(const Triple &TT) {
  CodePointerSize = 3;
  CalleeSaveStackSlotSize = 0;
  MaxInstLength = 5;
  UsesELFSectionDirectiveForBSS = true;
  SupportsDebugInformation = true;
}

} // namespace llvm

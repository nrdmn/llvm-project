//===-- STM8MCAsmInfo.h - STM8 asm properties ---------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the STM8MCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STM8_ASM_INFO_H
#define LLVM_STM8_ASM_INFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

/// Specifies the format of STM8 assembly files.
class STM8MCAsmInfo : public MCAsmInfoELF {
  void anchor() override;

public:
  explicit STM8MCAsmInfo(const Triple &TT);
};

} // end namespace llvm

#endif // LLVM_STM8_ASM_INFO_H

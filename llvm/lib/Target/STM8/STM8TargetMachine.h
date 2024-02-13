//===-- STM8TargetMachine.h - Define TargetMachine for STM8 -----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares the STM8 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STM8_TARGET_MACHINE_H
#define LLVM_STM8_TARGET_MACHINE_H

#include "STM8Subtarget.h"
#include "llvm/Target/TargetMachine.h"

#include <optional>

namespace llvm {

class STM8TargetMachine : public LLVMTargetMachine {
public:
  STM8TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options,
                    std::optional<Reloc::Model> RM, std::optional<CodeModel::Model> CM,
                    CodeGenOptLevel OL, bool JIT);

  const STM8Subtarget *getSubtargetImpl(const Function &) const override { return nullptr; }

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
};

} // end namespace llvm

#endif // LLVM_STM8_TARGET_MACHINE_H

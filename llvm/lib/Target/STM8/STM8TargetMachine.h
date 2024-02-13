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

class Module;

struct STM8InstrInfo {};
struct TargetFrameInfo {};

class STM8TargetMachine : public LLVMTargetMachine {
  STM8InstrInfo InstrInfo;
  TargetFrameInfo FrameInfo;

public:
  STM8TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                    StringRef FS, const TargetOptions &Options,
                    std::optional<Reloc::Model> RM, std::optional<CodeModel::Model> CM,
                    CodeGenOptLevel OL, bool JIT);
  ~STM8TargetMachine() override = default;

  virtual const STM8InstrInfo *getInstrInfo() const { return &InstrInfo; }
  virtual const TargetFrameInfo *getFrameInfo() const { return &FrameInfo; }
  const STM8Subtarget *getSubtargetImpl(const Function &) const override { return nullptr; }
  virtual const TargetRegisterInfo *getRegisterInfo() const { return nullptr; }
  virtual const class DataLayout *getDataLayout() const { return nullptr; }

  // Pass Pipeline Configuration
  virtual bool addInstSelector(PassManagerBase &PM, bool Fast) { return false; };
  virtual bool addPreEmitPass(PassManagerBase &PM, bool Fast) { return false; };

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
};

} // end namespace llvm

#endif // LLVM_STM8_TARGET_MACHINE_H

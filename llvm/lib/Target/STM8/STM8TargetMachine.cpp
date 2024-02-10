//===-- STM8TargetMachine.cpp - Define TargetMachine for STM8 -------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the STM8 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#include "STM8TargetMachine.h"

#include "STM8.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/IR/Module.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Target/TargetMachine.h"
#include "TargetInfo/STM8TargetInfo.h"

namespace llvm {

constexpr const char *STM8DataLayout =
    "e-p:24:8-i8:8-i16:8-i32:8-i64:8-f32:8-f64:8-n8:16-a:8";

STM8TargetMachine::STM8TargetMachine(const Target &T, const Triple &TT,
                                     StringRef CPU, StringRef FS,
                                     const TargetOptions &Options,
                                     std::optional<Reloc::Model> RM,
                                     std::optional<CodeModel::Model> CM,
                                     CodeGenOptLevel OL, bool JIT)
    : LLVMTargetMachine(T, STM8DataLayout, TT, CPU, FS, Options,
                        RM.value_or(Reloc::Static),
                        CM.value_or(CodeModel::Small),
                        OL) {
  initAsmInfo();
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSTM8Target() {
  // Register the target
  RegisterTargetMachine<STM8TargetMachine> X(getTheSTM8Target());

  auto &PR = *PassRegistry::getPassRegistry();
  // TODO initialize passes
}

class STM8PassConfig : public TargetPassConfig {
public:
  STM8PassConfig(STM8TargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  STM8TargetMachine &getSTM8TargetMachine() const {
    return getTM<STM8TargetMachine>();
  }

  bool addInstSelector() override;
};

bool STM8PassConfig::addInstSelector() {
  addPass(createSTM8ISelDag(getSTM8TargetMachine(), getOptLevel()));
  return false;
}

TargetPassConfig *STM8TargetMachine::createPassConfig(PassManagerBase &PM) {
  return new STM8PassConfig(*this, PM);
}

} // end of namespace llvm

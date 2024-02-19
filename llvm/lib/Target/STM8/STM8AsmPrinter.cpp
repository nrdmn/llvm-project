//===-- STM8AsmPrinter.cpp - STM8 LLVM assembly writer --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to GAS-format STM8 assembly language.
//
//===----------------------------------------------------------------------===//

#include "STM8TargetMachine.h"

#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/TargetRegistry.h"
#include "TargetInfo/STM8TargetInfo.h"


namespace llvm {

/// An STM8 assembly code printer.
class STM8AsmPrinter : public AsmPrinter {
public:
  STM8AsmPrinter(TargetMachine &TM, std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)), MRI(*TM.getMCRegisterInfo()) {}

  StringRef getPassName() const override { return "AVR Assembly Printer"; }

private:
  const MCRegisterInfo &MRI;
};

} // end of namespace llvm

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeSTM8AsmPrinter() {
  llvm::RegisterAsmPrinter<llvm::STM8AsmPrinter> X(llvm::getTheSTM8Target());
}

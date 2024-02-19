//===-- STM8AsmBackend.h - STM8 Asm Backend  ------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// \file The STM8 assembly backend implementation.
//
//===----------------------------------------------------------------------===//
//

#ifndef LLVM_STM8_ASM_BACKEND_H
#define LLVM_STM8_ASM_BACKEND_H

#include "llvm/MC/MCAsmBackend.h"
#include "llvm/TargetParser/Triple.h"

namespace llvm {

class MCAssembler;
class MCContext;
struct MCFixupKindInfo;

/// Utilities for manipulating generated STM8 machine code.
class STM8AsmBackend : public MCAsmBackend {
public:
  STM8AsmBackend(Triple::OSType OSType)
      : MCAsmBackend(llvm::endianness::little), OSType(OSType) {}

  std::unique_ptr<MCObjectTargetWriter>
  createObjectTargetWriter() const override;

  void applyFixup(const MCAssembler &Asm, const MCFixup &Fixup,
                  const MCValue &Target, MutableArrayRef<char> Data,
                  uint64_t Value, bool IsResolved,
                  const MCSubtargetInfo *STI) const override;
  unsigned getNumFixupKinds() const override {
    // TODO
    return 0;
  }

  bool fixupNeedsRelaxation(const MCFixup &Fixup, uint64_t Value,
                            const MCRelaxableFragment *DF,
                            const MCAsmLayout &Layout) const override {
    llvm_unreachable("RelaxInstruction() unimplemented");
    return false;
  }

  bool writeNopData(raw_ostream &OS, uint64_t Count,
                    const MCSubtargetInfo *STI) const override;

private:
  Triple::OSType OSType;
};

} // end namespace llvm

#endif // LLVM_STM8_ASM_BACKEND_H

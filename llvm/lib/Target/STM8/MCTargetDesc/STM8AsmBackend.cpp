//===-- STM8AsmBackend.cpp - STM8 Asm Backend  ----------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the STM8AsmBackend class.
//
//===----------------------------------------------------------------------===//

#include "MCTargetDesc/STM8AsmBackend.h"
#include "MCTargetDesc/STM8MCTargetDesc.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

namespace llvm {

class STM8ELFObjectWriter : public MCELFObjectTargetWriter {
public:
  STM8ELFObjectWriter(uint8_t OSABI)
    : MCELFObjectTargetWriter(false, OSABI, ELF::EM_STM8, true) {}


  unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                        const MCFixup &Fixup, bool IsPCRel) const override {
    return 0; // TODO
  }
};

std::unique_ptr<MCObjectTargetWriter>
STM8AsmBackend::createObjectTargetWriter() const {
  return std::make_unique<STM8ELFObjectWriter>(ELF::ELFOSABI_NONE);
}

void STM8AsmBackend::applyFixup(const MCAssembler &Asm, const MCFixup &Fixup,
                                const MCValue &Target,
                                MutableArrayRef<char> Data, uint64_t Value,
                                bool IsResolved,
                                const MCSubtargetInfo *STI) const {
}

bool STM8AsmBackend::writeNopData(raw_ostream &OS, uint64_t Count,
                                  const MCSubtargetInfo *STI) const {
  return true;
}

MCAsmBackend *createSTM8AsmBackend(const Target &T, const MCSubtargetInfo &STI,
                                   const MCRegisterInfo &MRI,
                                   const llvm::MCTargetOptions &TO) {
  return new STM8AsmBackend(STI.getTargetTriple().getOS());
}

} // end of namespace llvm

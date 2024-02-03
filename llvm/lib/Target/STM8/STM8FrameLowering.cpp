//===-- STM8FrameLowering.cpp - STM8 Frame Information --------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains the STM8 implementation of TargetFrameLowering class.
//
//===----------------------------------------------------------------------===//

#include "STM8FrameLowering.h"

namespace llvm {

STM8FrameLowering::STM8FrameLowering()
    : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(1), -2) {}

void STM8FrameLowering::emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const {
  return; // TODO
}

void STM8FrameLowering::emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const {
  return; // TODO
}

bool STM8FrameLowering::hasFP(const MachineFunction &MF) const {
  return false; // TODO
}

} // end of namespace llvm

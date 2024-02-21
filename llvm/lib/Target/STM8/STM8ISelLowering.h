//===-- STM8ISelLowering.h - STM8 DAG Lowering Interface --------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that STM8 uses to lower LLVM code into a
// selection DAG.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_STM8_ISEL_LOWERING_H
#define LLVM_STM8_ISEL_LOWERING_H

#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

namespace STM8ISD {

/// STM8 specific DAG nodes
enum NodeType {
  /// Start the numbering where the builtin ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  /// 
};

} // end of namespace STM8ISD

class STM8Subtarget;
class STM8TargetMachine;

class STM8TargetLowering : public TargetLowering {
public:
  explicit STM8TargetLowering(const STM8TargetMachine &TM,
                              const STM8Subtarget &STI);

private:
  const STM8Subtarget &Subtarget;

  MVT getPointerTy(const DataLayout &DL, unsigned AS) const override;
};

} // end of namespace llvm

#endif // LLVM_STM8_ISEL_LOWERING_H


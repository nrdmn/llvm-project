//===-- STM8ISelLowering.cpp - STM8 DAG Lowering Implementation -----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the STM8TargetLowering class.
//
//===----------------------------------------------------------------------===//

#include "STM8.h"
#include "STM8RegisterInfo.h"
#include "STM8ISelLowering.h"
#include "STM8TargetMachine.h"
#include "MCTargetDesc/STM8MCTargetDesc.h"

using namespace llvm;

namespace llvm {

STM8TargetLowering::STM8TargetLowering(const STM8TargetMachine &TM,
                                       const STM8Subtarget &STI)
    : TargetLowering(TM), Subtarget(STI) {}
//===----------------------------------------------------------------------===//
//                      Calling Convention Implementation
//===----------------------------------------------------------------------===//

#include "STM8GenCallingConv.inc"

SDValue STM8TargetLowering::LowerFormalArguments(
    SDValue Chain, CallingConv::ID CallConv, bool isVarArg,
    const SmallVectorImpl<ISD::InputArg> &Ins, const SDLoc &dl,
    SelectionDAG &DAG, SmallVectorImpl<SDValue> &InVals) const {

  return Chain;
}

bool STM8TargetLowering::CanLowerReturn(
    CallingConv::ID CallConv, MachineFunction &MF, bool IsVarArg,
    const SmallVectorImpl<ISD::OutputArg> &Outs, LLVMContext &Context) const {

  return true;
}

SDValue
STM8TargetLowering::LowerReturn(SDValue Chain, CallingConv::ID CallConv,
                                bool isVarArg,
                                const SmallVectorImpl<ISD::OutputArg> &Outs,
                                const SmallVectorImpl<SDValue> &OutVals,
                                const SDLoc &dl, SelectionDAG &DAG) const {

  return Chain;
}

MVT STM8TargetLowering::getPointerTy(const DataLayout &DL, unsigned AS) const {
  if (AS == 0 && DL.getPointerSizeInBits(AS) == 24)
    return MVT::i32;
  return TargetLowering::getPointerTy(DL, AS);
}

} // end of namespace llvm

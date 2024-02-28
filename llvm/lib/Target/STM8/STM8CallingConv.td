//==- STM8CallingConv.td - Calling Conventions for STM8 -*- tablegen -*-==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for STM8 architecture.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// STM8 Return Value Calling convention
//===----------------------------------------------------------------------===//
def RetCC_STM8 : CallingConv<[
  // i8 are returned in register A
  CCIfType<[i8], CCAssignToReg<[R_A]>>,

  // i16 are returned in register X
  CCIfType<[i16], CCAssignToReg<[R_X]>>,

  // TODO: i32 are returned with one half in X and other half in Y
]>;

//===----------------------------------------------------------------------===//
// STM8 Argument Calling Convention - VarArg
//===----------------------------------------------------------------------===//
// TOOD: unsure if this is correct
def CC_STM8_VarArgs : CallingConv<[
  // everything is passed through the stack
  // TODO: verify that this is working
  CCAssignToStack<1,1>
]>;

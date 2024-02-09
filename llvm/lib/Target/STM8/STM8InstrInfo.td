//===- STM8InstrInfo.td - Target Description for STM8 -----*- tablegen -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file describes the STM8 instructions in TableGen format.
//
//===----------------------------------------------------------------------===//

include "STM8InstrFormats.td"

// NOP
// No-operation instruction
// --------
// <|9D>
def NOP : F8<0x9D, (outs), (ins), "nop", []>;

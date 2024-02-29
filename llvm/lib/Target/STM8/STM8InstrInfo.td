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

//===----------------------------------------------------------------------===//
// STM8 Operands, Complex Patterns and Transformations Definitions.
//===----------------------------------------------------------------------===//

def imm_ldi8 : Operand<i8> {
}

//===----------------------------------------------------------------------===//
// Special/Control instructions
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Arithmetic instructions
//===----------------------------------------------------------------------===//

//======----------------------------------------------------------------======//
//// Addition instructions
//======----------------------------------------------------------------======//
let Constraints = "$src = $ra", Defs = [R_C] in {
  def ADDb : Fb<
    0xAB, (outs GPRA: $ra), (ins GPRA: $src, imm_ldi8: $byte), "add\t$ra, $byte",
    [(set i8: $ra, (add i8: $src, i8: $byte)), (implicit R_C)]
  >;
}

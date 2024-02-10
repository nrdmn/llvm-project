//===-- STM8InstrInfo.td - STM8 Instruction Formats --------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// STM8 Instruction Format Definitions.
//
//===----------------------------------------------------------------------===//

// A generic STM8 instruction
class STM8Inst<dag outs, dag ins, string asmstr, list<dag> pattern, int size>
    : Instruction {
  let Namespace = "STM8";

  let OutOperandList = outs;
  let InOperandList = ins;
  let AsmString = asmstr;
  let Pattern = pattern;

  int Size = size;
}

//===----------------------------------------------------------------------===//
// Special, opcode only instructions (1 byte): <|opcode|>
//===----------------------------------------------------------------------===//

class F8<bits<8> opcode, dag outs, dag ins, string asmstr, list<dag> pattern>
    : STM8Inst<outs, ins, asmstr, pattern, 1> {
  field bits<8> Inst = opcode;
}

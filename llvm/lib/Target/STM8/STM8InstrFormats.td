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
class STM8Inst<bits<8> op, dag outs, dag ins, string asmstr, list<dag> pattern, bits<8> mod>
    : Instruction {
  let Namespace = "STM8";

  let OutOperandList = outs;
  let InOperandList = ins;
  let AsmString = asmstr;
  let Pattern = pattern;

  int ArgSize = -1;  // argument size in bytes
  bits<8> Op = op;
  bits<8> Mod = mod;
  bits<32> Args = 0;

  // even though we have a CISC ISA here, the longest instruction will
  // always only be 6 bytes long. As there also exists a clear opcode
  // structure it is better to postprocess the instruction to bring it
  // to the right size, instead of rewriting the same few lines everywhere.
  field bits<48> Inst;
  let Inst{47-40} = Mod;
  let Inst{39-32} = Op;
  let Inst{31-0}  = Args;
}

//===----------------------------------------------------------------------===//
// Instructions classes representing the possible argument combinations
//
// As there are only a handful of employed operand combinations in the ISA,
// this task is rather managable.
//
// TODO: improve documentation
//===----------------------------------------------------------------------===//

// Without arguments
class F<bits<8> opcode, dag outs, dag ins, string asmstr, list<dag> pattern, bits<8> mod = 0>
  : STM8Inst<opcode, outs, ins, asmstr, pattern, mod> {
  let ArgSize = 0;
}

// With a single byte argument
class Fb<bits<8> opcode, dag outs, dag ins, string asmstr, list<dag> pattern, bits<8> mod = 0>
  : STM8Inst<opcode, outs, ins, asmstr, pattern, mod> {
  bits<8> byte;

  let ArgSize = 1;
  let Args{31-24} = byte;
}

// With a single word argument
class Fw<bits<8> opcode, dag outs, dag ins, string asmstr, list<dag> pattern, bits<8> mod = 0>
  : STM8Inst<opcode, outs, ins, asmstr, pattern, mod> {
  bits<16> word;

  let ArgSize = 2;
  let Args{31-16} = word;
}

/// ShortMem
class Fsm<bits<8> opcode, dag outs, dag ins, string asmstr, list<dag> pattern, bits<8> mod = 0>
  : Fb<opcode, outs, ins, asmstr, pattern, mod> {
  bits<8> sm;
  let byte = sm;
}

/// LongMem
class Flm<bits<8> opcode, dag outs, dag ins, string asmstr, list<dag> pattern, bits<8> mod = 0>
  : Fw<opcode, outs, ins, asmstr, pattern, mod> {
  bits<16> lm;
  let word = lm;
}

/// ShortOff
class Fso<bits<8> opcode, dag outs, dag ins, string asmstr, list<dag> pattern, bits<8> mod = 0>
  : Fb<opcode, outs, ins, asmstr, pattern, mod> {
  bits<8> so;
  let byte = so;
}

// ShortPtrW
class Fspw<bits<8> opcode, dag outs, dag ins, string asmstr, list<dag> pattern, bits<8> mod = 0>
  : Fb<opcode, outs, ins, asmstr, pattern, mod> {
  bits<8> spw;
  let byte = spw;
}

// LongPtrW
class Flpw<bits<8> opcode, dag outs, dag ins, string asmstr, list<dag> pattern, bits<8> mod = 0>
  : Fw<opcode, outs, ins, asmstr, pattern, mod> {
  bits<16> lpw;
  let word = lpw;
}

// TODO: integrate multi argument mnemonics classes

// TODO: introduce multiclasses as seen in analysis

//===-- STM8RegisterInfo.td - STM8 Register defs -----------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the STM8 register file
//===----------------------------------------------------------------------===//

// 8-bit General purpose register definition.
class STM8Reg<bits<16> num, string name, list<Register> subregs = [],
             list<string> altNames = []> : RegisterWithSubRegs<name, subregs> {
  field bits<16> Num = num;

  let HWEncoding = num;
  let Namespace = "STM8";
  let SubRegs = subregs;
  let AltNames = altNames;
}

// Subregister indices.
let Namespace = "STM8" in {
  def sub_lo : SubRegIndex<8>;
  def sub_hi : SubRegIndex<8, 8>;
}

let Namespace = "STM8" in { def ptr : RegAltNameIndex; }

//===----------------------------------------------------------------------===//
//  8-bit general purpose registers
//===----------------------------------------------------------------------===//

def R0 : STM8Reg<0, "r0">, DwarfRegNum<[0]>;
def R1 : STM8Reg<1, "r1">, DwarfRegNum<[1]>;

//===----------------------------------------------------------------------===//
// Register Classes
//===----------------------------------------------------------------------===//

// Main 8-bit register class.
def GPR8 : RegisterClass<"STM8", [i8], 8,
                         (
                             // Return value and argument registers.
                             add
                             //R24, R25, R18, R19, R20, R21, R22, R23,
                             // Scratch registers.
                             //R30, R31, R26, R27,
                             // Callee saved registers.
                             //R28, R29, R17, R16, R15, R14, R13, R12, R11, R10,
                             //R9, R8, R7, R6, R5, R4, R3, R2,
                             R0, R1)>;

// Register class used for the stack read pseudo instruction.
//def GPRSP : RegisterClass<"STM8", [i16], 8, (add SP)>;

// Status register.
def SREG : STM8Reg<14, "FLAGS">, DwarfRegNum<[88]>;
def CCR : RegisterClass<"STM8", [i8], 8, (add SREG)> {
  let CopyCost = -1; // Don't allow copying of status registers
}

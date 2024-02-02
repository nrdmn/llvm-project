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

let Namespace = "STM8" in {
  def sub_lo : SubRegIndex<8>;
  def sub_hi : SubRegIndex<8, 8>;
  def sub_ex : SubRegIndex<8, 16>;
}

let Namespace = "STM8" in { def ptr : RegAltNameIndex; }

//===----------------------------------------------------------------------===//
// CodeEmitterGen general purpose registers
//===----------------------------------------------------------------------===//
// - dwarf numbers are (partially) from SDCC for compatibility

// 8bit (sub)registers
def R_A : STM8Reg<0, "A">, DwarfRegNum<[0]>;        // accumulator
def R_XL : STM8Reg<1, "XL">, DwarfRegNum<[1]>;      // lower byte of X
def R_XH : STM8Reg<2, "XH">, DwarfRegNum<[2]>;      // higher byte of X
def R_YL : STM8Reg<3, "YL">, DwarfRegNum<[3]>;      // lower byte of Y
def R_YH : STM8Reg<4, "YH">, DwarfRegNum<[4]>;      // higher byte of Y
def R_C : STM8Reg<5, "C">, DwarfRegNum<[5]>;        // status register

def R_PCE : STM8Reg<6, "PCE">, DwarfRegNum<[10]>;   // extended byte of PC[24:16]
def R_PCH : STM8Reg<7, "PCH">, DwarfRegNum<[11]>;   // higher byte of PC[16:8]
def R_PCL : STM8Reg<8, "PCL">, DwarfRegNum<[12]>;   // lower byte of PC [8:0]

// 16bit (sub)registers
def R_SP : STM8Reg<11, "SP">, DwarfRegNum<[8]>;     // stack pointer

let SubRegIndices = [sub_lo, sub_hi], CoveredBySubRegs = 1 in {
  def R_X : STM8Reg<9, "X", [R_XL, R_XH]>, DwarfRegNum<[6]>;   // X index
  def R_Y : STM8Reg<10, "Y", [R_YL, R_YH]>, DwarfRegNum<[7]>;  // Y index

  // TODO: is it needed?
  def R_PCHL : STM8Reg<12, "PCH:PCL", [R_PCL, R_PCH]>, DwarfRegNum<[13]>;  // compilation targt register
}

// 24bit registers
let SubRegIndices = [sub_lo, sub_hi, sub_ex], CoveredBySubRegs = 1 in {
  def R_PC : STM8Reg<13, "PC", [R_PCL, R_PCH, R_PCE]>, DwarfRegNum<[9]>;  // the PC
}

//===----------------------------------------------------------------------===//
// Register Classes
//===----------------------------------------------------------------------===//

// main 8-bit register class (TODO: is this sensible?)
def GPR8 : RegisterClass<"STM8", [i8], 8, (
  // accumulator
  add R_A,
  // index registers
  R_XL, R_XH, R_YL, R_YH,
  // program counter
  R_PCL, R_PCH, R_PCE
)>;

// main 16-bit register class (TODO: is this sensible?)
def GPR16 : RegisterClass<"STM8", [i16], 8, (
  // index register
  add R_X, R_Y,
  // lower pc half
  R_PCHL
)>;

// accumulator register class
def GPRA : RegisterClass<"STM8", [i8], 8, (add R_A)>;

// x index register classes
def GPRXS : RegisterClass<"STM8", [i8], 8, (add R_XL)>;  // short
def GPRX : RegisterClass<"STM8", [i16], 8, (add R_X)>;   // long

// y index register class
def GPRYS : RegisterClass<"STM8", [i8], 8, (add R_YL)>;  // short
def GPRY : RegisterClass<"STM8", [i16], 8, (add R_Y)>;   // long

// program counter
def GPRPCL : RegisterClass<"STM8", [i16], 8, (add R_PCHL)>; // long
def GPRPCE : RegisterClass<"STM8", [i24], 8, (add R_PC)>;   // extended

// Register class used for the stack read pseudo instruction.
def GPRSP : RegisterClass<"STM8", [i16], 8, (add R_SP)>;

// Status register.
def GPRC : RegisterClass<"STM8", [i8], 8, (add R_C)> {
  let CopyCost = -1; // Don't allow copying of status registers
}

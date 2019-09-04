//===-- I8080InstrFormats.td - I8080 Instruction Formats ---*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

include "I8080Operators.td"


class I8080Inst<dag outs, dag ins, string opcodestr, string argstr, list<dag> pattern> : Instruction
{
  let Namespace = "I8080";
  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString = opcodestr # "\t" # argstr;
  let Pattern = pattern;
}

class I8080ALU_rInst<string opcodestr, SDNode opnode> : I8080Inst<(outs GPReg:regA), (ins GPReg:regA, GPReg:$src), opcodestr, "$src", 
[(set (i8 GPReg:regA), (opnode (i8 GPReg:regA), (i8 GPReg:$src)))]> {
  field bits<8> Inst;
}

class I8080PseudoInstr<dag outs, dag ins, string opcodestr, string argstr, list<dag> pattern> : I8080Inst<outs, ins, opcodestr, argstr, pattern> {
  let isPseudo = 1;
}
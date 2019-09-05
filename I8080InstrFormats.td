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

class I8080ALU_rInst<bits<5> opcode, string opcodestr, SDNode opnode> : I8080Inst<(outs AccReg:$a), (ins GPReg:$src2), opcodestr, "$src2", 
[(set AccReg:$a, (opnode regA, GPReg:$src2))]> {
  let Size = 1;
  field bits<8> Inst;
  let Inst{7-3} = opcode;

  bits<3> src2;
  let Inst{2-0} = src2;
}

class I8080PseudoInstr<dag outs, dag ins, string opcodestr, string argstr, list<dag> pattern> : I8080Inst<outs, ins, opcodestr, argstr, pattern> {
  let isPseudo = 1;
}
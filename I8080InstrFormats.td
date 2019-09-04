//===-- I8080InstrFormats.td - I8080 Instruction Formats ---*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

include "I8080Operators.td"


class InstI8080<dag outs, dag ins, bits<4> binOpcode, string opcodestr, string argstr, list<dag> pattern> : Instruction
{
  field bits<32> Inst;

  let Namespace = "I8080";
  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString = opcodestr # "\t" # argstr;
  let Pattern = pattern;
  let Size = 4; //???
  let Inst{31-28} = binOpcode;
}


class I8080PseudoInstr<dag outs, dag ins, string opcodestr, string argstr, list<dag> pattern> : InstI8080<outs, ins, 0, opcodestr, argstr, pattern> {
  let isPseudo = 1;
}

class RTypeInstr<bits<4> opcode, string opcodestr, list<dag> pattern> : InstI8080<(outs GRRegs:$dr), (ins GRRegs:$sr1, GRRegs:$sr2), opcode, opcodestr, "$dr, $sr1, $sr2", pattern> {
  bits<4> dr;
  bits<4> sr1;
  bits<4> sr2;
  let Inst{27-24} = dr;
  let Inst{23-20} = sr1;
  let Inst{3-0} = sr2;
  let Inst{19-4} = 0; // padding
}

class SKPTypeInstr<bits<4> opcode, bits<4> mode, string opcodestr, list<dag> pattern> : InstI8080<(outs), (ins GRRegs:$sr1, GRRegs:$sr2), opcode, opcodestr, "$sr1, $sr2", []> {
    bits<4> sr1;
    bits<4> sr2;
    let Inst{27-24} = mode;
    let Inst{23-20} = sr1;
    let Inst{3-0} = sr2;
    let Inst{19-4} = 0; // padding
    let isBranch = 1;
    let isCompare = 1;
}

class ITypeInstr<bits<4> opcode, dag outs, dag ins, string asmstr, string argstr, list<dag> pattern> : InstI8080<outs, ins, opcode, asmstr, argstr, pattern> {
}


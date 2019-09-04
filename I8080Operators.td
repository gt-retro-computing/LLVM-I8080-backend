//===-- I8080Operators.td - I8080-specific operators ------*- tblgen-*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

def Imm20 : AsmOperandClass {
    let Name = "Imm20";
}

// def I8080imm20 : Operand<i32>, ImmLeaf<i32, [{
//   return Imm >= 0 && Imm < 0x100000;
// }]> {
//     let ParserMatchClass = Imm20;
// }

//===----------------------------------------------------------------------===//
// Complex Pattern Definitions.
//===----------------------------------------------------------------------===//

def addr : ComplexPattern<iPTR, 2, "SelectAddr", [], []>; 
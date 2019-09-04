//===- I8080CallingConv.td - Calling Conventions for I8080 -*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This describes the calling conventions for I8080 architecture.
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// I8080 Return Value Calling Convention
//===----------------------------------------------------------------------===//
// def RetCC_I8080 : CallingConv<[
//   // i32 are returned in registers v0
//   CCIfType<[i32], CCAssignToReg<[v0]>>,

//   // Integer values get stored in stack slots that are 4 bytes in
//   // size and 4-byte aligned.
//   CCIfType<[i32], CCAssignToStack<4, 4>>
// ]>;

//===----------------------------------------------------------------------===//
// I8080 Argument Calling Conventions
//===----------------------------------------------------------------------===//
// def CC_I8080 : CallingConv<[
//   // Promote i8 arguments to i32.
//   CCIfType<[i8], CCPromoteToType<i32>>,

//   // Promote i16 arguments to i32.
//   CCIfType<[i16], CCPromoteToType<i32>>,

//   // The first 5 integer arguments are passed in integer registers.
//   CCIfType<[i32], CCAssignToReg<[a0, a1, a2]>>,

//   // Integer values get stored in stack slots that are 4 bytes in
//   // size and 4-byte aligned.
//   CCIfType<[i32], CCAssignToStack<4, 4>>
// ]>;

// def CC_Save : CalleeSavedRegs<(add s0, s1, s2, sp, fp, ra)>;
// Should there be only R7 here?
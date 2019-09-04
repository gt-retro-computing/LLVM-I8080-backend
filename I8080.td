//===-- I8080.td - Describe the I8080 Target Machine -------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//===----------------------------------------------------------------------===//
//
// This is the top level entry point for the I8080 target.
//
//===----------------------------------------------------------------------===//

include "llvm/Target/Target.td"

include "I8080RegisterInfo.td"
include "I8080InstrInfo.td"
include "I8080CallingConv.td"

def I8080InstrInfo : InstrInfo;

//===----------------------------------------------------------------------===//
// I8080 processors supported.
//===----------------------------------------------------------------------===//

class Proc<string Name, list<SubtargetFeature> Features>
    : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

//===----------------------------------------------------------------------===//
// Declare the target which we are implementing
//===----------------------------------------------------------------------===//

def I8080 : Target {
  let InstructionSet = I8080InstrInfo;
}
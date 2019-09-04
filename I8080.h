//
// Created by codetector on 8/29/19.
//

#ifndef TARGET_I8080_H
#define TARGET_I8080_H
#include "MCTargetDesc/I8080MCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
    class TargetMachine;
    class I8080TargetMachine;
    FunctionPass *createI8080ISelDag(I8080TargetMachine &TM, CodeGenOpt::Level OptLevel);
} // end namespace llvm;

#endif


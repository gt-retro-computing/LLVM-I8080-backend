//
// Created by codetector on 9/3/19.
//

#ifndef LLVM_I8080BASEINFO_H
#define LLVM_I8080BASEINFO_H

#include "I8080MCTargetDesc.h"
#include "llvm/Support/ErrorHandling.h"

namespace llvm {
namespace I8080 {
}

static inline unsigned getI8080RegisterNumbering(unsigned Reg) {
  switch (Reg) {
    case I8080::regA: return 7;
    case I8080::regB: return 0;
    case I8080::regC: return 1;
    case I8080::regD: return 2;
    case I8080::regE: return 3;
    case I8080::regH: return 4;
    case I8080::regL: return 5;
    case I8080::regM: return 6;
    // I think the following is correct as this is used in MCEmitter
    case I8080::regBC: return 0;
    case I8080::regDE: return 1;
    case I8080::regHL: return 2;
    case I8080::regSP: return 3;
    default:
      llvm_unreachable("LMAO, What register is this????");
  }
}
}

#endif //LLVM_I8080BASEINFO_H

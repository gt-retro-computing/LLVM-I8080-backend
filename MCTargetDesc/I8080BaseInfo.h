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
            case I8080::zero: return 0;
            case I8080::at: return 1;
            case I8080::v0: return 2;
            case I8080::a0: return 3;
            case I8080::a1: return 4;
            case I8080::a2: return 5;
            case I8080::t0: return 6;
            case I8080::t1: return 7;
            case I8080::t2: return 8;
            case I8080::s0: return 9;
            case I8080::s1: return 10;
            case I8080::s2: return 11;
            case I8080::k0: return 12;
            case I8080::sp: return 13;
            case I8080::fp: return 14;
            case I8080::ra: return 15;
            default: llvm_unreachable("LMAO, What register is this????");
        }
    }
}

#endif //LLVM_I8080BASEINFO_H

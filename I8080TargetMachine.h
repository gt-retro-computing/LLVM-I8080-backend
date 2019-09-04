//
// Created by codetector on 9/1/19.
//

#ifndef LLVM_LIB_TARGET_I8080_I8080TARGETMACHINE_H
#define LLVM_LIB_TARGET_I8080_I8080TARGETMACHINE_H

#include "llvm/Target/TargetMachine.h"

namespace llvm {
    class I8080TargetMachine : public TargetMachine {
    public:
        I8080TargetMachine(const llvm::Target &T, const llvm::Triple &TT, llvm::StringRef CPU,
                            llvm::StringRef FS, const llvm::TargetOptions &Options,
                            Optional<llvm::Reloc::Model> RM,
                            Optional<llvm::CodeModel::Model> CM, llvm::CodeGenOpt::Level OL, bool JIT);
    };
}

#endif //LLVM_I8080TARGETMACHINE_H

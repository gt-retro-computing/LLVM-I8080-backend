#include "I8080TargetMachine.h"
#include "I8080.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"
#include <iostream>

//class I8080PassConfig : public TargetPassConfig {
// public:
//	virtual bool addInstSelector();
//};
//
//bool I8080PassConfig::addInstSelector() {
//	addPass(createI8080ISelDag(getI8080TargetMachine()));
//	return false;
//}
//
using namespace llvm;
//

I8080TargetMachine::I8080TargetMachine(const llvm::Target &T, const llvm::Triple &TT, llvm::StringRef CPU,
                                   llvm::StringRef FS, const llvm::TargetOptions &Options,
                                   Optional<llvm::Reloc::Model> RM,
                                   Optional<llvm::CodeModel::Model> CM, llvm::CodeGenOpt::Level OL, bool JIT) :
        TargetMachine(T,
                "e-m:e-p:16:16:16-i1:16:16-i8:8:8-i16:16:16-i32:32:32-f64:64:64-a:0:16-n16",
                TT, CPU, FS, Options
        ) {
    std::cout << "Create Triple: %s"  << TT.str() << std::endl;
}
//
//namespace {
//	class I8080PassConfig : public TargetPassConfig {
//	 public:
//		I8080PassConfig(I8080TargetMachine *TM, PassManagerBase &PM)
//		: TargetPassConfig(TM, PM) {}
//		I8080TargetMachine &getI8080TargetMachine() const {
//			return getTM<I8080TargetMachine>();
//		}
//		virtual bool addPreISel();
//		virtual bool addInstSelector();
//		virtual bool addPreEmitPass();
//		};
//} // namespace
//
//TargetPassConfig
//*I8080TargetMachine::createPassConfig(PassManagerBase &PM) {
//	return new I8080PassConfig(this, PM);
//}
//
//bool I8080PassConfig::addPreISel() { return false; }
//
//bool I8080PassConfig::addInstSelector() {
//	addPass(createI8080ISelDag(getI8080TargetMachine(),
//	getOptLevel()));
//	return false;
//}
//
//bool I8080PassConfig::addPreEmitPass() { return false; }
//
// Force static initialization.
extern "C" void LLVMInitializeI8080Target() {
	RegisterTargetMachine<I8080TargetMachine> X(TheI8080Target);
}
//
//void I8080TargetMachine::addAnalysisPasses(PassManagerBase &PM) {}

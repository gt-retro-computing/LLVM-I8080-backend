#include "I8080.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

Target llvm::TheI8080Target;
extern "C" void LLVMInitializeI8080TargetInfo() {
	RegisterTarget<Triple::i8080> X(TheI8080Target, "i8080", "I8080", "I8080");
} 
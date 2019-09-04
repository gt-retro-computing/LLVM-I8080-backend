//
// Created by codetector on 9/2/19.
//

#include "I8080.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "asm-printer"
namespace {
class I8080AsmPrinter : public AsmPrinter {

};
}



extern "C" void LLVMInitializeI8080AsmPrinter() {
  RegisterAsmPrinter<I8080AsmPrinter> X(TheI8080Target);
}
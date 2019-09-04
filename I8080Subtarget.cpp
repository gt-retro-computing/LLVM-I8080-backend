#include "I8080Subtarget.h"
#include "I8080.h"
#include "llvm/Support/TargetRegistry.h"

#define DEBUG_TYPE "lc2200-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "I8080GenSubtargetInfo.inc"

using namespace llvm;

//I8080Subtarget::I8080Subtarget(const std::string &TT, const std::string &CPU, const std::string &FS, I8080TargetMachine &TM):
//	DataLayout("e-m:e-p:32:32-i1:8:32-i8:8:32-i16:16:32-i64:32-f64:32-a:0:32-n32"),
//	InstrInfo(), TLInfo(TM), TSInfo(DL), FrameLowering()
//	{}
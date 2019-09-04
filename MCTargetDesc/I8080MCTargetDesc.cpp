#include "I8080MCTargetDesc.h"
#include "I8080MCAsmInfo.h"
#include "InstPrinter/I8080InstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/FormattedStream.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_MC_DESC
#include "I8080GenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "I8080GenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "I8080GenRegisterInfo.inc"

using namespace llvm;

static MCInstrInfo *createI8080MCInstrInfo() {
	MCInstrInfo *X = new MCInstrInfo();
	InitI8080MCInstrInfo(X);
	return X;
}

static MCRegisterInfo *createI8080MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitI8080MCRegisterInfo(X, 0);
  return X;
}

//static MCSubtargetInfo *createI8080MCSubtargetInfo(const Triple &TT, StringRef CPU,
//                                                    StringRef FS) {
//  return createI8080MCSubtargetInfoImpl(TT, CPU, FS);
//}

static MCAsmInfo *createI8080MCAsmInfo(const MCRegisterInfo &MRI, const Triple &TT) {
  MCAsmInfo *MAI = new I8080MCAsmInfo(TT);
  return MAI;
}

//static MCCodeGenInfo *createI8080MCCodeGenInfo(const Triple &TT, Reloc::Model RM,
//	CodeModel::Model CM, CodeGenOpt::Level OL) {
//	MCCodeGenInfo *X = new MCCodeGenInfo();
//	if (RM == Reloc::Default) {
//		RM = Reloc::Static;
//	}
//	if (CM == CodeModel::Default) {
//		CM = CodeModel::Small;
//	}
//	if (CM != CodeModel::Small && CM != CodeModel::Large) {
//		report_fatal_error("Target only supports CodeModel Small or Large");
//	}
//	X->InitMCCodeGenInfo(RM, CM, OL);
//	return X;
//}

static MCInstPrinter *
createI8080MCInstPrinter(const Triple &T, unsigned SyntaxVariant,
                          const MCAsmInfo &MAI, const MCInstrInfo &MII,
                          const MCRegisterInfo &MRI) {
  return new I8080InstPrinter(MAI, MII, MRI);
}

static MCStreamer* createI8080ELFStreamer(const Triple &T, MCContext &Ctx,
        std::unique_ptr<MCAsmBackend> &&MAB,
        std::unique_ptr<MCObjectWriter> &&OW,
        std::unique_ptr<MCCodeEmitter> &&Emitter, bool RelaxAll) {
    return createELFStreamer(Ctx, std::move(MAB), std::move(OW), std::move(Emitter), RelaxAll);
}

static MCTargetStreamer* createI8080TargetStreamer(MCStreamer &S, const MCSubtargetInfo &STI) {
    if (STI.getTargetTriple().getObjectFormat() == Triple::HEX) {

    }
}

//static MCStreamer *
//createMCAsmStreamer(MCContext &Ctx, formatted_raw_ostream &OS,
//	bool isVerboseAsm, bool useDwarfDirectory, MCInstPrinter *InstPrint,
//	MCCodeEmitter *CE,MCAsmBackend *TAB, bool ShowInst) {
//	return createAsmStreamer(Ctx, OS, isVerboseAsm,
//		useDwarfDirectory, InstPrint, CE, TAB, ShowInst);
//}
//
//static MCStreamer *createMCStreamer(const Target &T,
//	StringRef TT, MCContext &Ctx, MCAsmBackend &MAB,
//	raw_ostream &OS, MCCodeEmitter *Emitter, const MCSubtargetInfo &STI,
//	bool RelaxAll, bool NoExecStack) {
//	return createELFStreamer(Ctx, MAB, OS, Emitter, false, NoExecStack);
//}

// Force static initialization.
extern "C" void LLVMInitializeI8080TargetMC() {

// Register the MC asm info.
  RegisterMCAsmInfoFn X(TheI8080Target, createI8080MCAsmInfo);

// Register the MC codegen info.
//  TargetRegistry::RegisterMCCodeGenInfo(TheI8080Target,
//                                        createI8080MCCodeGenInfo);

// Register the MC instruction info.
  TargetRegistry::RegisterMCInstrInfo(TheI8080Target,
createI8080MCInstrInfo);
// Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(TheI8080Target,
                                    createI8080MCRegisterInfo);
// Register the MC subtarget info.
TargetRegistry::RegisterMCSubtargetInfo(TheI8080Target,
createI8080MCSubtargetInfoImpl);

// Register the MCInstPrinter
TargetRegistry::RegisterMCInstPrinter(TheI8080Target,
                                        createI8080MCInstPrinter);
// Register the ASM Backend.
TargetRegistry::RegisterMCAsmBackend(TheI8080Target,
createI8080AsmBackend);

// Register the assembly streamer.
//TargetRegistry::RegisterAsmStreamer(TheI8080Target,
//createMCAsmStreamer);

TargetRegistry::RegisterObjectTargetStreamer(TheI8080Target, createI8080TargetStreamer);

// Register the object streamer.
TargetRegistry::RegisterELFStreamer(TheI8080Target, createI8080ELFStreamer);
// Register the MCCodeEmitter
TargetRegistry::RegisterMCCodeEmitter(TheI8080Target, createI8080MCCodeEmitter);
}
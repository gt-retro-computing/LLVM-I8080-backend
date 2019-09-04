#ifndef I8080MCTARGETDESC_H
#define I8080MCTARGETDESC_H

#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCTargetOptions.h"
#include "llvm/ADT/Triple.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/DataTypes.h"

namespace llvm {
	class Target;
	class MCInstrInfo;
	class MCRegisterInfo;
	class MCSubtargetInfo;
	class MCContext;
	class MCCodeEmitter;
	class MCAsmInfo;
	class MCCodeGenInfo;
	class MCRegisterClass;
	class MCInstPrinter;
	class MCObjectWriter;
	class MCAsmBackend;
	class StringRef;
	class raw_ostream;
	extern Target TheI8080Target;
	MCCodeEmitter *createI8080MCCodeEmitter(const MCInstrInfo &MCII,
		const MCRegisterInfo &MRI, MCContext &Ctx);
	MCAsmBackend *createI8080AsmBackend(const Target &T, const MCSubtargetInfo &STI, const MCRegisterInfo &MRI, const MCTargetOptions &Options);
	std::unique_ptr<MCObjectTargetWriter> createI8080ELFObjectWriter(uint8_t OSABI);
} // End llvm namespace

#define GET_REGINFO_ENUM
#include "I8080GenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "I8080GenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
//#include "I8080GenSubtargetInfo.inc"

#endif 
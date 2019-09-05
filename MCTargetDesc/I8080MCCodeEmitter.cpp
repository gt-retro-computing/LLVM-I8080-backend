#define DEBUG_TYPE "mccodeemitter"

#include "MCTargetDesc/I8080BaseInfo.h"
#include "MCTargetDesc/I8080MCTargetDesc.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCFixup.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/MC/MCCodeEmitter.h"

using namespace llvm;
namespace {
class I8080MCCodeEmitter : public MCCodeEmitter {
  I8080MCCodeEmitter(const I8080MCCodeEmitter &) = delete;

  void operator=(const I8080MCCodeEmitter &) = delete;

  const MCInstrInfo &InstrInfo;

  unsigned getMachineOpValue(const MCInst &MI, const MCOperand &MO,
                             SmallVectorImpl<MCFixup> &Fixups, const MCSubtargetInfo &STI) const;

public:
  I8080MCCodeEmitter(const MCInstrInfo &MII) : InstrInfo(MII) {}

  ~I8080MCCodeEmitter() {}

  uint64_t getBinaryCodeForInstr(const MCInst &MI,
                                 SmallVectorImpl<MCFixup> &Fixups,
                                 const MCSubtargetInfo &STI) const;

  void EmitByte(unsigned char C, unsigned &CurByte, raw_ostream &OS) const {
    OS << (char) C;
    ++CurByte;
  }

  void EmitBEConstant(uint64_t Val, unsigned Size, unsigned &CurByte,
                      raw_ostream &OS) const {
    assert(Size <= 8 && "size too big in emit constant");

    for (int i = (Size - 1) * 8; i >= 0; i -= 8)
      EmitByte((Val >> i) & 255, CurByte, OS);
  }

  void encodeInstruction(const MCInst &Inst, raw_ostream &OS, SmallVectorImpl<MCFixup> &Fixups,
                         const MCSubtargetInfo &STI) const override;
};
} // end anonymous namespace

MCCodeEmitter *llvm::createI8080MCCodeEmitter(const llvm::MCInstrInfo &MCII, const llvm::MCRegisterInfo &MRI,
                                              llvm::MCContext &Ctx) {
  return new I8080MCCodeEmitter(MCII);
}


unsigned I8080MCCodeEmitter::getMachineOpValue(const MCInst &MI, const MCOperand &MO,
                                               SmallVectorImpl<MCFixup> &Fixups, const MCSubtargetInfo &STI) const {
  if (MO.isReg()) {
    return getI8080RegisterNumbering(MO.getReg());
  }
  if (MO.isImm()) {
    return static_cast<unsigned>(MO.getImm());
  }
  //TODO Fixups
  return 0;
}

void I8080MCCodeEmitter::encodeInstruction(const MCInst &Inst, raw_ostream &OS, SmallVectorImpl<MCFixup> &Fixups,
                                           const MCSubtargetInfo &STI) const {
  const MCInstrDesc &desc = InstrInfo.get(Inst.getOpcode());
  uint32_t magicValue = desc.getNumOperands();
  uint32_t CurByte = 0;
  unsigned Value = getBinaryCodeForInstr(Inst, Fixups, STI);
  EmitBEConstant(Value, desc.Size, CurByte, OS);
}

#include "I8080GenMCCodeEmitter.inc"
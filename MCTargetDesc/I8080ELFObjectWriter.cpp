//
// Created by codetector on 9/3/19.
//
#include "MCTargetDesc/I8080BaseInfo.h"
#include "MCTargetDesc/I8080FixupKinds.h"
#include "MCTargetDesc/I8080MCTargetDesc.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
    class I8080ELFObjectWriter : public MCELFObjectTargetWriter {
    public:
        I8080ELFObjectWriter(uint8_t OSABI);

        virtual ~I8080ELFObjectWriter();

    protected:
        unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                const MCFixup &Fixup, bool IsPCRel) const override;
    };
}

I8080ELFObjectWriter::I8080ELFObjectWriter(uint8_t OSABI) : MCELFObjectTargetWriter(false, OSABI, ELF::EM_IMSAI_8080, false){}

I8080ELFObjectWriter::~I8080ELFObjectWriter() {}

unsigned I8080ELFObjectWriter::getRelocType(MCContext &Ctx, const MCValue &Target, const MCFixup &Fixup,
                                             bool IsPCRel) const {
    // TODO: Reloc???
    return (unsigned)Fixup.getKind();
}

std::unique_ptr<MCObjectTargetWriter> llvm::createI8080ELFObjectWriter(uint8_t OSABI) {
    return std::make_unique<I8080ELFObjectWriter>(OSABI);
}

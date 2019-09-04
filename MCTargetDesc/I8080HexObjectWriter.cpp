//
// Created by codetector on 9/4/19.
//

#include "I8080MCTargetDesc.h"
#include "llvm/MC/MCObjectWriter.h"

using namespace llvm;

namespace {
class I8080HexObjectWriter : MCObjectTargetWriter {
public:
    ~I8080HexObjectWriter(){}
    Triple::ObjectFormatType getFormat() const override {
        return Triple::Hex;
    }
};

}

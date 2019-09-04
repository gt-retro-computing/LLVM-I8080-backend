#include "I8080MCAsmInfo.h"
#include "llvm/ADT/StringRef.h"

using namespace llvm;

void I8080MCAsmInfo::anchor() {}

I8080MCAsmInfo::I8080MCAsmInfo(const Triple &TT) {
    //TODO: Assembly formatting
	SupportsDebugInformation = true;
	Data16bitsDirective = "\t.short\t";
	Data32bitsDirective = "\t.long\t";
	Data64bitsDirective = 0;
	ZeroDirective = "\t.space\t";
	CommentString = "#";
	AscizDirective = ".asciiz";
	HiddenVisibilityAttr = MCSA_Invalid;
	HiddenDeclarationVisibilityAttr = MCSA_Invalid;
	ProtectedVisibilityAttr = MCSA_Invalid;
}

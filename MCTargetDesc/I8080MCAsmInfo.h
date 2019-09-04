
#ifndef I8080TARGETASMINFO_H
#define I8080TARGETASMINFO_H

#include "llvm/ADT/Triple.h"
#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {
	class StringRef;
	class Target;
	class I8080MCAsmInfo : public MCAsmInfoELF {
	virtual void anchor();
	public:
	 explicit I8080MCAsmInfo(const Triple &TT);
	};
} // namespace llvm

#endif 
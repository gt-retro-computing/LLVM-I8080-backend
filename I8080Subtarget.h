#ifndef I8080SUBTARGET_H
#define I8080SUBTARGET_H

#include "I8080.h"
//#include "I8080FrameLowering.h"
//#include "I8080ISelLowering.h"
//#include "I8080InstrInfo.h"
//#include "I8080SelectionDAGInfo.h"
#include "llvm/Target/TargetMachine.h"

#define GET_SUBTARGETINFO_HEADER
#include "I8080GenSubtargetInfo.inc"

class I8080Subtarget : public I8080GenSubtargetInfo {
//virtual void anchor();
// private:
//	const DataLayout DL;	// Calculates type size & alignment.
//	I8080InstrInfo InstrInfo;
//	I8080TargetLowering TLInfo;
//	I8080SelectionDAGInfo TSInfo;
//	I8080FrameLowering FrameLowering;
//	InstrItineraryData InstrItins;
 public:
// 	I8080Subtarget(const std::string &TT, const std::string &CPU, const std::string &FS);
//
// 	const InstrItineraryData *getInstrItineraryData() const override {
//		return &InstrItins;
//	}
//
//	const I8080InstrInfo *getInstrInfo() const override { return &InstrInfo; }
//
//	const I8080RegisterInfo *getRegisterInfo() const override {
//		return &InstrInfo.getRegisterInfo();
//	}
//
//	const I8080TargetLowering *getTargetLowering() const override {
//		return &TLInfo;
//	}
//
//	const I8080FrameLowering *getFrameLowering() const override {
//		return &FrameLowering;
//	}
//
//	const I8080SelectionDAGInfo *getSelectionDAGInfo() const override {
//		return &TSInfo;
//	}
//
//	const DataLayout *getDataLayout() const override { return &DL; }
//
//	void ParseSubtargetFeatures(StringRef CPU, StringRef FS);
};
//
#endif
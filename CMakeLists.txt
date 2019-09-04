set(LLVM_TARGET_DEFINITIONS I8080.td)

tablegen(LLVM I8080GenAsmMatcher.inc -gen-asm-matcher)
tablegen(LLVM I8080GenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM I8080GenCallingConv.inc -gen-callingconv)
tablegen(LLVM I8080GenDAGISel.inc -gen-dag-isel)
tablegen(LLVM I8080GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM I8080GenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM I8080GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM I8080GenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(I8080CommonTableGen)

add_llvm_target(I8080CodeGen
        I8080AsmPrinter.cpp
        I8080FrameLowering.cpp
        I8080ISelDAGToDAG.cpp
        I8080Subtarget.cpp
        I8080TargetMachine.cpp
        )

add_subdirectory(InstPrinter)
add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
add_subdirectory(AsmParser)
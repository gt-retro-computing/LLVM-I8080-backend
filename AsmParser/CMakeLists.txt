include_directories( ${CMAKE_CURRENT_BINARY_DIR}/.. ${CMAKE_CURRENT_SOURCE_DIR}/.. )

add_llvm_library(LLVMI8080AsmParser
        I8080AsmParser.cpp
        )

add_dependencies(LLVMI8080AsmParser I8080CommonTableGen)
//
// Created by codetector on 9/3/19.
//

#ifndef LLVM_I8080FIXUPKINDS_H
#define LLVM_I8080FIXUPKINDS_H

using namespace llvm;

namespace llvm {
namespace I8080 {
enum Fixups {
  FirstTargetFixupKind,
  LastTargetFixupKind,
  NumTargetFixupKinds = LastTargetFixupKind - FirstTargetFixupKind
};
}
}

#endif //LLVM_I8080FIXUPKINDS_H

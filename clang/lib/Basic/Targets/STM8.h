//===--- STM8.h - Declare STM8 target feature support -----------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares STM8 TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_STM8_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_STM8_H

#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/Support/Compiler.h"
#include "llvm/TargetParser/Triple.h"

namespace clang {
namespace targets {

// STM8
class LLVM_LIBRARY_VISIBILITY STM8TargetInfo : public TargetInfo {
public:
  STM8TargetInfo(const llvm::Triple &Triple, const TargetOptions &) : TargetInfo(Triple) {
    TLSSupported = false;
    PointerWidth = 24;
    PointerAlign = 8;
    IntWidth = 16;
    IntAlign = 8;
    LongWidth = 32;
    LongAlign = 8;
    LongLongWidth = 64;
    LongLongAlign = 8;
    SuitableAlign = 8;
    DefaultAlignForAttributeAligned = 8;
    HalfWidth = 16;
    HalfAlign = 8;
    FloatWidth = 32;
    FloatAlign = 8;
    DoubleWidth = 32;
    DoubleWidth = 8;
    DoubleFormat = &llvm::APFloat::IEEEsingle();
    LongDoubleWidth = 32;
    LongDoubleAlign = 8;
    LongDoubleFormat = &llvm::APFloat::IEEEsingle();
    SizeType = UnsignedLong;
    PtrDiffType = SignedLong;
    IntPtrType = SignedLong;
    Char16Type = UnsignedInt;
    WIntType = SignedInt;
    Int16Type = SignedInt;
    Char32Type = UnsignedLong;
    SigAtomicType = SignedChar;
    resetDataLayout("e-p:24-i8:8-i16:8-i32:8-i64:8-f32:8-f64:8-n8:16-a:8");
  };

  void getTargetDefines(const LangOptions &Opts, MacroBuilder &Builder) const override;
  ArrayRef<Builtin::Info> getTargetBuiltins() const override;
  BuiltinVaListKind getBuiltinVaListKind() const override;
  bool validateAsmConstraint(const char *&Name, TargetInfo::ConstraintInfo &info) const override;
  std::string_view getClobbers() const override;
  ArrayRef<const char *> getGCCRegNames() const override;
  ArrayRef<GCCRegAlias> getGCCRegAliases() const override;
};

} // namespace targets
} // namespace clang

#endif // !LLVM_CLANG_LIB_BASIC_TARGETS_STM8_H

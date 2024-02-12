//===--- STM8.cpp - Implement STM8 target feature support -----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements STM8 TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#include "STM8.h"
#include "clang/Basic/MacroBuilder.h"

namespace clang {
namespace targets {

void STM8TargetInfo::getTargetDefines(const LangOptions &Opts, MacroBuilder &Builder) const {
  Builder.defineMacro("__STM8__");
}

ArrayRef<Builtin::Info> STM8TargetInfo::getTargetBuiltins() const {
  return std::nullopt;
}

TargetInfo::BuiltinVaListKind STM8TargetInfo::getBuiltinVaListKind() const {
  return TargetInfo::VoidPtrBuiltinVaList;
}

bool STM8TargetInfo::validateAsmConstraint(const char *&Name, TargetInfo::ConstraintInfo &info) const {
  return false;
}

std::string_view STM8TargetInfo::getClobbers() const { return ""; }

ArrayRef<const char *> STM8TargetInfo::getGCCRegNames() const {
  static const char *const GCCRegNames[] = {
    "A", "X", "Y", "PC", "SP"
  };
  return llvm::ArrayRef(GCCRegNames);
}

ArrayRef<TargetInfo::GCCRegAlias> STM8TargetInfo::getGCCRegAliases() const {
  return std::nullopt;
}


} // namespace targets
} // namespace clang

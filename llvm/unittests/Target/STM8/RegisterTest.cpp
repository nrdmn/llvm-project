#include "STM8TargetMachine.h"
#include "STM8InstrInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"

#define GET_REGINFO_ENUM
#include "STM8GenRegisterInfo.inc"
#undef GET_REGINFO_ENUM

#include "gtest/gtest.h"

using namespace llvm;

namespace {

std::unique_ptr<TargetMachine> createTargetMachine() {
  Triple TT("stm8--");

  LLVMInitializeSTM8TargetInfo();
  LLVMInitializeSTM8Target();
  LLVMInitializeSTM8TargetMC();

  std::string Error;
  const Target *TheTarget = TargetRegistry::lookupTarget(TT, Error);

  return std::unique_ptr<TargetMachine>(
      TheTarget->createTargetMachine(TT, "generic", "", TargetOptions(), std::nullopt,
                                     std::nullopt, CodeGenOptLevel::Default));
}

} // anonymous namespace


TEST(RegisterTest, XLowerRegister) {
  std::unique_ptr<TargetMachine> TM = createTargetMachine();

  STM8Subtarget ST(TM->getTargetTriple(), std::string(TM->getTargetCPU()),
                 std::string(TM->getTargetFeatureString()),
                 *static_cast<const STM8TargetMachine *>(TM.get()));
  auto II = std::make_unique<STM8InstrInfo>(ST);

  const auto& RI = ST.getRegisterInfo();
  ASSERT_TRUE(RI);

  EXPECT_EQ(RI->getSubReg(STM8::R_X, STM8::sub_lo), STM8::R_XL);
}

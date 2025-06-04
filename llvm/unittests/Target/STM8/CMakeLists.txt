include_directories(
  ${LLVM_MAIN_SRC_DIR}/lib/Target/STM8
  ${LLVM_BINARY_DIR}/lib/Target/STM8
  )

set(LLVM_LINK_COMPONENTS
  STM8CodeGen
  STM8Desc
  STM8Info
  )

add_llvm_target_unittest(STM8Tests
  RegisterTest.cpp
)

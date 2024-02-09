add_llvm_component_library(LLVMSTM8Desc
  STM8MCTargetDesc.cpp
  STM8MCAsmInfo.cpp

  LINK_COMPONENTS
  MC

  ADD_TO_COMPONENT
  STM8
)

add_dependencies(LLVMSTM8Desc STM8CommonTableGen)


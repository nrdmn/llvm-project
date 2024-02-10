add_llvm_component_library(LLVMSTM8Desc
  STM8MCAsmInfo.cpp
  STM8MCTargetDesc.cpp

  LINK_COMPONENTS
  MC

  ADD_TO_COMPONENT
  STM8
)

add_dependencies(LLVMSTM8Desc STM8CommonTableGen)


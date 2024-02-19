add_llvm_component_group(STM8)

set(LLVM_TARGET_DEFINITIONS STM8.td)

tablegen(LLVM STM8GenDAGISel.inc -gen-dag-isel)
tablegen(LLVM STM8GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM STM8GenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM STM8GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM STM8GenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(STM8CommonTableGen)

add_llvm_target(STM8CodeGen
  STM8AsmPrinter.cpp
  STM8FrameLowering.cpp
  STM8ISelDAGToDAG.cpp
  STM8ISelLowering.cpp
  STM8RegisterInfo.cpp
  STM8Subtarget.cpp
  STM8TargetMachine.cpp

  DEPENDS
  intrinsics_gen

  LINK_COMPONENTS
  Core

  ADD_TO_COMPONENT
  STM8
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)

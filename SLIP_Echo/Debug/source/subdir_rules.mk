################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/%.obj: ../source/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7R4 --code_state=32 --float_support=VFPv3D16 -me --include_path="C:/Users/tejas/workspace_v10/SLIP_Echo" --include_path="C:/Users/tejas/workspace_v10/SLIP_Echo/include" --include_path="C:/Users/tejas/workspace_v10/SLIP_Echo/source" --include_path="C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/%.obj: ../source/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7R4 --code_state=32 --float_support=VFPv3D16 -me --include_path="C:/Users/tejas/workspace_v10/SLIP_Echo" --include_path="C:/Users/tejas/workspace_v10/SLIP_Echo/include" --include_path="C:/Users/tejas/workspace_v10/SLIP_Echo/source" --include_path="C:/ti/ccs1000/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --enum_type=packed --abi=eabi --preproc_with_compile --preproc_dependency="source/$(basename $(<F)).d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



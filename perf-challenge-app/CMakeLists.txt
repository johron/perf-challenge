set(project_name "perf-challenge-app")

include("Participants.cmake")

set(precompiled_header
    "src/precompiled/stdafx.h")

set(script_files 
	"Participants.cmake")

set(root_files
    "src/main.cpp")

set(all_source_files
	${script_files}
    ${precompiled_header}
	${participant_files}
    ${root_files})

add_executable(${project_name} MACOSX_BUNDLE ${all_source_files})

target_link_libraries(${project_name} "perf-challenge-lib")

source_group("Scripts" FILES ${script_files})
source_group("Source" FILES ${root_files})
source_group("Source\\Precompiled" FILES ${precompiled_header})

set_target_properties(${project_name} PROPERTIES FOLDER "Perf-Challenge")
set_target_properties(${project_name} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${precompiled_header})

cotire(${project_name})

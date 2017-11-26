set(project_name "perf-challenge-lib")

set(precompiled_header
    "src/precompiled/stdafx.h")

set(root_files
	"src/ISolver.h"
	"src/ITestDataProvider.h"
    "src/Registry.cpp"
	"src/Registry.h"
	"src/TestData.h")

set(all_source_files
    ${precompiled_header}
    ${root_files})

add_library(${project_name} STATIC ${all_source_files})

source_group("Source" FILES ${root_files})
source_group("Source\\Precompiled" FILES ${precompiled_header})

set_target_properties(${project_name} PROPERTIES FOLDER "Perf-Challenge")
set_target_properties(${project_name} PROPERTIES COTIRE_CXX_PREFIX_HEADER_INIT ${precompiled_header})

cotire(${project_name})

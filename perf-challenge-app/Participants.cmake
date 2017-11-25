macro(find_subdirs result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  SET(${result} ${dirlist})
endmacro()

set(file_prefix "${CMAKE_CURRENT_SOURCE_DIR}/src/participants")
find_subdirs(subdirs ${file_prefix})

foreach(dir ${subdirs})
	file(GLOB file_list "${file_prefix}/${dir}/*")
	foreach(file ${file_list})
		list(APPEND participant_files "${file}")
		source_group("Source\\Participants\\${dir}" FILES "${file}")
	endforeach()
endforeach()

set(registry_file "${file_prefix}/Participants.h")
file(WRITE ${registry_file} 
"// ====================================================
// THIS CODE IS GENERATED - PLEASE DO NOT MANUALLY EDIT
// ====================================================
#pragma once 
#include \"../../../perf-challenge-lib/src/Registry.h\"\n\n")

foreach(dir ${subdirs})
	file(APPEND ${registry_file} 
"#include \"participants/${dir}/Implementation.h\"\n")
endforeach()

file(APPEND ${registry_file}
"
namespace Perf {
	std::unique_ptr<Perf::Registry> RegisterParticipants() {
		auto registry = std::make_unique<Perf::Registry>();\n")

foreach(dir ${subdirs})
	file(APPEND ${registry_file} 
"		registry->addParticipant(\"${dir}\", std::make_unique<${dir}::Implementation>());\n")
endforeach()

file(APPEND ${registry_file}
"		return std::move(registry);
	}
}")



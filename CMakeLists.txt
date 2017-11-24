cmake_minimum_required(VERSION 3.1)
project("perf-challenge" VERSION 1.0 LANGUAGES C CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "Predefined Targets")
set_property(GLOBAL PROPERTY AUTOGEN_TARGETS_FOLDER "Autogen Targets")

add_subdirectory("perf-challenge-lib")
add_subdirectory("perf-challenge-app")

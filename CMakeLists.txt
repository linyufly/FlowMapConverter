cmake_minimum_required(VERSION 2.8)

project(FlowMapConverter)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(FlowMapConverterTest flow_map_converter_test.cc
                                    flow_map_converter.cc)

target_link_libraries(FlowMapConverterTest ${VTK_LIBRARIES})

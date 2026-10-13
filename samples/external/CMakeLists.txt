#######################
# Interface to OpenCV #
#######################

if(MSVC)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "ARM64|arm64|aarch64")
      set(OpenCV_ARCH arm64)
      set(OpenCV_TARGET opencv4120)
      set(OpenCV_WORLD_LIB opencv_world4120)
    else()
      set(OpenCV_ARCH x64)
      set(OpenCV_TARGET opencv346)
      set(OpenCV_WORLD_LIB opencv_world346)
    endif()

    set(OpenCV_ARCH_DIR ${CMAKE_CURRENT_SOURCE_DIR}/opencv/)
    set(OpenCV_INCLUDE_DIRS ${OpenCV_ARCH_DIR}/include ${OpenCV_ARCH_DIR}/include/opencv2)
    set(OpenCV_LIBRARY_DIR ${OpenCV_ARCH_DIR}/lib)
    set(OpenCV_BINARY_DIR ${OpenCV_ARCH_DIR}/bin)

    if(NOT EXISTS ${OpenCV_LIBRARY_DIR}/${OpenCV_WORLD_LIB}.lib)
      message(FATAL_ERROR "No ${OpenCV_ARCH} OpenCV found at ${OpenCV_LIBRARY_DIR}/${OpenCV_WORLD_LIB}.lib")
    endif()

    add_library(${OpenCV_TARGET} INTERFACE)
    target_include_directories(${OpenCV_TARGET} INTERFACE ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(${OpenCV_TARGET} INTERFACE
      $<$<CONFIG:Debug>:${OpenCV_LIBRARY_DIR}/${OpenCV_WORLD_LIB}d.lib>
      $<$<NOT:$<CONFIG:Debug>>:${OpenCV_LIBRARY_DIR}/${OpenCV_WORLD_LIB}.lib>
    )
    set_target_properties(${OpenCV_TARGET} PROPERTIES
      DYNAMIC_LIBRARY_DIR "${OpenCV_BINARY_DIR}")

    add_library(OpenCV INTERFACE)
    target_link_libraries(OpenCV INTERFACE ${OpenCV_TARGET})
    set_target_properties(OpenCV PROPERTIES
      DYNAMIC_LIBRARY_DIR "${OpenCV_BINARY_DIR}")

    message(STATUS "OpenCV (${OpenCV_ARCH}): ${OpenCV_ARCH_DIR}")
else()

    find_package(OpenCV REQUIRED
        PATHS /usr /usr/local
        PATH_SUFFIXES share/OpenCV share/opencv4)
    add_library(OpenCV INTERFACE)
    target_include_directories(OpenCV INTERFACE ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(OpenCV INTERFACE ${OpenCV_LIBRARIES})

    message("OpenCV_INCLUDE_DIRS ${OpenCV_INCLUDE_DIRS}")
    message("OpenCV_LIBRARIES ${OpenCV_LIBRARIES}")
    message("OpenCV_LIBS ${OpenCV_LIBS}")

    find_package(CUDA 11.3 REQUIRED)
    add_library(CUDA INTERFACE)
    target_include_directories(CUDA INTERFACE ${CUDA_INCLUDE_DIRS})
    target_link_libraries(CUDA INTERFACE "${CUDA_LIBRARIES};cuda")

    message("CUDA_INCLUDE_DIRS ${CUDA_INCLUDE_DIRS}")
    message("CUDA_LIBRARIES ${CUDA_LIBRARIES}")

    find_package(TensorRT 8 REQUIRED)
    add_library(TensorRT INTERFACE)
    target_include_directories(TensorRT INTERFACE ${TensorRT_INCLUDE_DIRS})
    target_link_libraries(TensorRT INTERFACE ${TensorRT_LIBRARIES})

    message("TensorRT_INCLUDE_DIRS ${TensorRT_INCLUDE_DIRS}")
    message("TensorRT_LIBRARIES ${TensorRT_LIBRARIES}")


endif()

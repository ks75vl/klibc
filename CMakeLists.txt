# Copyright 2024 ks75vl.
# 
# Filename: CMakeLists
#   Author: ks75vl
#  Created: 07/07/2024 20:08:22 +07:00

if(ESP_PLATFORM)
    include(${CMAKE_CURRENT_LIST_DIR}/esp/esp.cmake)
endif()
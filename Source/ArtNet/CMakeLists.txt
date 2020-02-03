SET (ARTNET_SRCS 
Private/ArtNet.cpp
Private/ArtNetNode.cpp
Public/ArtNet.h
Public/ArtNetNode.h
${PROJECT_SOURCE_DIR}/.clang-format
)

add_library(ArtNet SHARED ${ARTNET_SRCS})
target_link_libraries(ArtNet Qt5::Core Qt5::Network)
target_include_directories(ArtNet PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Public)
target_compile_definitions(ArtNet PRIVATE ARTVIS_ARTNET_BUILD)

add_custom_command(
	TARGET ArtNet POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:Qt5::Core>
    $<TARGET_FILE_DIR:ArtNet>
)

add_custom_command(
	TARGET ArtNet POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:Qt5::Network>
    $<TARGET_FILE_DIR:ArtNet>
)
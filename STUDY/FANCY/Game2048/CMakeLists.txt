set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/exeFile)
project(Game)

aux_source_directory(. SFileList)

add_executable(${PROJECT_NAME} ${SFileList})

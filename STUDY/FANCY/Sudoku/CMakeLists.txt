project(Sudoku)

aux_source_directory(. SFileList)

add_executable(${PROJECT_NAME} ${SFileList})

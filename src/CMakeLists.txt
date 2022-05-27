add_subdirectory(algorithms/union)
add_subdirectory(algorithms/sorts)

add_executable(${PROJECT_NAME} 
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    union
    sorts
    )
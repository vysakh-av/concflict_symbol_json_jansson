cmake_minimum_required(VERSION 2.8)
#set (LINKER_FLAGS "-Wl -Bsymbolic-functions")
#set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${LINKER_FLAGS}")
project (json_conflict_lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

#json_c_lib
set (STATIC_JSON_LIB libjson-c.a libjson.a)
add_library(json_c_lib STATIC json_c_lib.c)
target_compile_options(json_c_lib PUBLIC -g)
target_link_libraries(json_c_lib ${STATIC_JSON_LIB})

#json_c_lib shared library.
add_library(json_c_lib_shared SHARED json_c_lib.c)
target_compile_options(json_c_lib_shared PUBLIC -g)
target_link_libraries(json_c_lib_shared json-c json)

# jansson_c_lib shared library.
# jansson lib linked as static library.
add_library(jansson_c_lib SHARED jansson_c_lib.c)
target_compile_options(jansson_c_lib PUBLIC -g)
set (STATIC_JAN_LIB libjansson.a)
#target_link_libraries(jansson_c_lib ${STATIC_JAN_LIB})
target_link_libraries(jansson_c_lib jansson)

#app
add_executable (app app.c)
target_compile_options(app PUBLIC -g)
target_compile_definitions(app PUBLIC  -D_JANSSON_ENABLED )
set(PROJECT_STATIC_LIBS -L/usr/local/lib/ libjson_c_lib.a -L. libjson-c.a libjson.a)
target_link_libraries(app jansson_c_lib  json_c_lib_shared)
cmake_minimum_required(VERSION 3.15)
project(tag_gateway)

set(CMAKE_CXX_STANDARD 17)

# Enable SSL
add_definitions(-DCROW_ENABLE_SSL)
find_package(OpenSSL REQUIRED)

add_executable(tag_gateway ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
target_link_libraries(tag_gateway PUBLIC OpenSSL::SSL)
target_include_directories(tag_gateway PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

INSTALL(TARGETS tag_gateway DESTINATION bin)
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/static DESTINATION /var/www/tag_gateway)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/ssl/server.cert DESTINATION /etc/tag_gateway/cert/)
INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/ssl/server.key DESTINATION /etc/tag_gateway/cert/)

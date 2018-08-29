
file(GLOB SRCS "*.h" "*.cpp")
file(GLOB HEADERS "*.h")

include_directories(../dbus)

find_package(PkgConfig REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5DBus REQUIRED)

add_library(libdde-auth SHARED ${SRCS} ../dbus)
set_target_properties(libdde-auth PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../)
target_include_directories(libdde-auth PUBLIC ../interface ../dbus)
target_link_libraries(libdde-auth PRIVATE
  ${Qt5DBus_LIBRARIES}
  ${Qt5Core_LIBRARIES}
)

# bin
install(TARGETS libdde-auth DESTINATION lib/)

## dev files
install (FILES ${HEADERS}
         DESTINATION include/libdde-auth)

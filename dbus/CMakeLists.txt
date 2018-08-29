file(GLOB INTERFACES "*.h")

## dev files
install (FILES ${INTERFACES}
         DESTINATION include/libdde-auth)

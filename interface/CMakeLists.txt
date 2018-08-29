file(GLOB INTERFACES deepinauthframework.h)

## dev files
install (FILES ${INTERFACES}
         DESTINATION include/libdde-auth)

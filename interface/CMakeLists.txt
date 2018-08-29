file(GLOB INTERFACES deepinauthinterface.h)

## dev files
install (FILES ${INTERFACES}
         DESTINATION include/libdde-auth)

#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=Linaro-gcc
CCC=Linaro-g++
CXX=Linaro-g++
FC=gfortran
AS=Linaro-as

# Macros
CND_PLATFORM=Cross-Linaro-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/5ee0878/buttons.o \
	${OBJECTDIR}/_ext/5ee0878/gpio.o \
	${OBJECTDIR}/_ext/5ee0878/i2c.o \
	${OBJECTDIR}/_ext/5ee0878/lcd.o \
	${OBJECTDIR}/_ext/5ee0878/output.o \
	${OBJECTDIR}/_ext/5ee0878/tools.o \
	${OBJECTDIR}/bombardement.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_2

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_2: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_2 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/5ee0878/buttons.o: ../cppGPIO/src/buttons.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ee0878
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ee0878/buttons.o ../cppGPIO/src/buttons.cpp

${OBJECTDIR}/_ext/5ee0878/gpio.o: ../cppGPIO/src/gpio.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ee0878
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ee0878/gpio.o ../cppGPIO/src/gpio.cpp

${OBJECTDIR}/_ext/5ee0878/i2c.o: ../cppGPIO/src/i2c.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ee0878
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ee0878/i2c.o ../cppGPIO/src/i2c.cpp

${OBJECTDIR}/_ext/5ee0878/lcd.o: ../cppGPIO/src/lcd.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ee0878
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ee0878/lcd.o ../cppGPIO/src/lcd.cpp

${OBJECTDIR}/_ext/5ee0878/output.o: ../cppGPIO/src/output.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ee0878
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ee0878/output.o ../cppGPIO/src/output.cpp

${OBJECTDIR}/_ext/5ee0878/tools.o: ../cppGPIO/src/tools.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/5ee0878
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5ee0878/tools.o ../cppGPIO/src/tools.cpp

${OBJECTDIR}/bombardement.o: bombardement.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bombardement.o bombardement.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppapplication_2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

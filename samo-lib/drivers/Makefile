# Copyright (c) 2009 Openmoko Inc
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


SAMO_LIB := $(shell readlink -es ../samo-lib || readlink -es ../../samo-lib || readlink -es ../../../samo-lib)

include ${SAMO_LIB}/Mk/definitions.mk


INCLUDES += -I${DRIVERS_INCLUDE}
INCLUDES += -I${FATFS_INCLUDE}
INCLUDES += -I${MINI_LIBC_INCLUDE}
INCLUDES += -I${SAMO_LIB_INCLUDE}

BUILD_PREFIX := build/

vpath %.c src

TARGETS = lib/libdrivers.a

# list of library modules
OBJECTS += drv1.o
#OBJECTS += drv2.o


.PHONY: all
all:  ${TARGETS}

lib/libdrivers.a: lib build $(addprefix ${BUILD_PREFIX},${OBJECTS})
	${AR} r "$@" $(addprefix ${BUILD_PREFIX},${OBJECTS})

lib:
	${MKDIR} "$@"
build:
	${MKDIR} "$@"

clean:
	$(RM) -r build lib
	${RM} *~ *.o *.d *.lst *.elf *.map *.asm33

include ${SAMO_LIB}/Mk/rules.mk
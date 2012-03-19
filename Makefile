#
# General Hash Function Algorithms Master MakeFile
# By Arash Partow - 2000
#
# URL: http://www.partow.net/programming/hashfunctions/index.html
#
# Copyright Notice:
# Free use of this library is permitted under the
# guidelines and in accordance with the most
# current version of the Common Public License.
# http://www.opensource.org/licenses/cpl1.0.php
#

COMPILER      = -c++
OPTIONS       = -ansi -g -pedantic -Wall -o
OPTIONS_LIBS  = -ansi -pedantic -Wall -c

all: GeneralHashFunctions.o sketch space_saving accurate_count count_min improved_count_min

GeneralHashFunctions.o: GeneralHashFunctions.cpp GeneralHashFunctions.h
	$(COMPILER) $(OPTIONS_LIBS) GeneralHashFunctions.cpp

sketch: GeneralHashFunctions.cpp sketch.cpp sketch.h
	$(COMPILER) $(OPTIONS) sketch sketch.cpp GeneralHashFunctions.o

space_saving: GeneralHashFunctions.cpp space_saving.cpp space_saving.h
	$(COMPILER) $(OPTIONS) space_saving space_saving.cpp GeneralHashFunctions.o

accurate_count: GeneralHashFunctions.cpp accurate_count.cpp accurate_count.h
	$(COMPILER) $(OPTIONS) accurate_count accurate_count.cpp GeneralHashFunctions.o

count_min: GeneralHashFunctions.cpp count_min.cpp count_min.h
	$(COMPILER) $(OPTIONS) count_min count_min.cpp GeneralHashFunctions.o

improved_count_min: GeneralHashFunctions.cpp improved_count_min.cpp improved_count_min.h
	$(COMPILER) $(OPTIONS) improved_count_min improved_count_min.cpp GeneralHashFunctions.o

clean:
	rm -f core *.o *.bak *stackdump *#
  
#
# The End !
#

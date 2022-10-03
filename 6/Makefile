TARGET = ./main
INCLUDE_DIRS = print
SOURCE_FILES = main.c \
			   print/*.c

.PHONY: all build rebuild run clean

build: ${TARGET}

rebuild: clean build

${TARGET}: ${INCLUDE_DIRS} ${SOURCE_FILES}
	gcc -g -Wpedantic -Wall -Wextra -Werror -I ${INCLUDE_DIRS} ${SOURCE_FILES} -o ${TARGET}

run: ${TARGET}
	${TARGET}

clean:
	rm ${TARGET}

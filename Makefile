####### Output directory

####### SRC Files
SRC_DIRS	  = ./src/base:./test/one
SRC_DIRS_INNER = $(subst :, ,$(SRC_DIRS))
SRC_FILES  = $(foreach dir,$(SRC_DIRS_INNER),$(wildcard $(dir)/*.c $(dir)/*.cpp))

###### OBJ Files
OBJ_PATHS = $(foreach dir,$(SRC_DIRS_INNER),$(addprefix ./out/,$(dir)))
OBJ_TMP_FILES  = $(subst .c,.o,$(SRC_FILES))
OBJ_FILES = $(addprefix ./out/,$(OBJ_TMP_FILES))

####### tools and flags
DEFINES       = -DOS_LINUX -DUNICODE -DLINUX 
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT -fno-inline -fexceptions $(DEFINES) 
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT -fno-inline -fexceptions $(DEFINES) 
INCPATH       = -I./include -I./src -I./src/base

CC            = gcc
CXX           = g++
LINK          = gcc
LFLAGS        = -g
LIBS          = -lpthread 

AR            = ar cqs
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Implicit rules
./out/%.o : %.c
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

##### Target
TARGET        = unittest 
STATICLIB     = 

####### Build rules
all:buildOutPaths $(TARGET) 
buildOutPaths:
	$(MKDIR) $(OBJ_PATHS)

$(TARGET): $(OBJ_FILES)
	$(LINK) $(LFLAGS) -o $@  $(OBJ_FILES) $(LIBS)

$(STATICLIB):$(OBJ_FILES)
	$(AR) $@ $(OBJ_FILES)
clean: 
	$(DEL_FILE) $(OBJ_FILES)
####### Compile
####### Install
install:  
uninstall: 
FORCE:


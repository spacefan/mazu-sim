SHELL=/bin/bash
TOP_DIR=$(shell TOP_DIR=Unable_To_Find_Top_Dir; \
				CUR_DIR=$$(pwd); \
				while [ "$$CUR_DIR" != "/" ]; \
				do { \
					if [ -a $$CUR_DIR/BOBI ]; then \
					TOP_DIR=$$CUR_DIR; \
					fi; \
				    CUR_DIR=$$(dirname $$CUR_DIR); } \
				done;\
				echo $$TOP_DIR)
include $(TOP_DIR)/modules-path_var.mk
#TARGET=libhello.so
TARGET=libcadac.a
# FLAGS
CXXFLAGS = -Wall -g -MD -save-temps -fPIC --std=c++17 -Wextra -Wshadow
CXXFLAGS += -I. -larmadillo -I./env
CXXFLAGS += -I$(module_math_utils)
CXXFLAGS += -I$(module_cadac)
LDFLAGS =

# Source code
CPP_SOURCES += $(TOP_DIR)/modules/cadac/datadeck.cpp
CPP_SOURCES += $(TOP_DIR)/modules/cadac/cadac_util.cpp \
			   $(TOP_DIR)/modules/cadac/schmitt_trigger.cpp \
			   $(TOP_DIR)/modules/cadac/env/wind.cpp \
			   $(TOP_DIR)/modules/cadac/env/wind_constant.cpp \
			   $(TOP_DIR)/modules/cadac/env/wind_no.cpp \
			   $(TOP_DIR)/modules/cadac/env/wind_tabular.cpp \
			   $(TOP_DIR)/modules/cadac/env/atmosphere76.cpp \
			   $(TOP_DIR)/modules/cadac/env/atmosphere_nasa2002.cpp \
			   $(TOP_DIR)/modules/cadac/env/atmosphere_weatherdeck.cpp \
			   $(TOP_DIR)/modules/cadac/component.cpp \
               $(TOP_DIR)/modules/cadac/signal_process.cpp \
               $(TOP_DIR)/modules/cadac/vehicle_var.cpp \
               $(TOP_DIR)/modules/cadac/vehicle.cpp \
			   $(TOP_DIR)/modules/cadac/time_management.cpp \
			   $(TOP_DIR)/modules/cadac/time_util.cpp \
			   $(TOP_DIR)/modules/cadac/body.cpp \
			   $(TOP_DIR)/modules/cadac/joint.cpp
OBJECTS += $(patsubst %.cpp, %.o, $(CPP_SOURCES))

all: $(TARGET) $(CPP_SOURCES)

%.o: %.cpp %.h
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(TARGET): $(OBJECTS)
#	$(CC) $(LDFLAGS) -o $@ $<
	$(AR) rcs $@ $^

-include $(OBJECTS:.o=.d)

.PHONY : clean
clean:
	find . -name "*.so" -type f -delete
	find . -name "*.a" -type f -delete
	find . -name "*.o" -type f -delete
	find . -name "*.ii" -type f -delete
	find . -name "*.d" -type f -delete
	find . -name "*.s" -type f -delete
	rm -rf build

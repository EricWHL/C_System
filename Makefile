TOP_DIR		= .

LCFLAGS += -I$(TOP_DIR)/base
LCFLAGS += -I$(TOP_DIR)/inc
LCFLAGS += -I$(TOP_DIR)/core
LCFLAGS += -I$(TOP_DIR)/tools
LCFLAGS += -I$(TOP_DIR)/tools/CodeGen
LCFLAGS += -lpthread

SUBDIRS		=\
			base \
			core \
			src \
			tools \
			tools/CodeGen \

include $(TOP_DIR)/mk/target.mk

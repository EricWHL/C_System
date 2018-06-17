TOP_DIR		= .

OBJ_DIR		= $(TOP_DIR)/obj

LCFLAGS += -I$(TOP_DIR)/base
LCFLAGS += -I$(TOP_DIR)/inc
LCFLAGS += -I$(TOP_DIR)/plugins


SUBDIRS		=\
			base \
			plugins \
			src\

include $(TOP_DIR)/mk/target.mk

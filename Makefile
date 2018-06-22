TOP_DIR		= .

LCFLAGS += -I$(TOP_DIR)/base
LCFLAGS += -I$(TOP_DIR)/inc
LCFLAGS += -I$(TOP_DIR)/core

SUBDIRS		=\
			base \
			core \
			src\

include $(TOP_DIR)/mk/target.mk

TOP_DIR		= .

LCFLAGS += -I$(TOP_DIR)/base
LCFLAGS += -I$(TOP_DIR)/inc
LCFLAGS += -I$(TOP_DIR)/plugins

SUBDIRS		=\
			base \
			plugins \
			src\

include $(TOP_DIR)/mk/target.mk

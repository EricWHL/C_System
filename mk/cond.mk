$(info  cond.mk execute start)

DEBUG = 0

define newline


endef

ifeq ($(DEBUG), 1)
	INFO := DEBUG newline _assertmk
else
	INFO := newline
endif


$(info  $(INFO))

$(info  cond.mk execute end)

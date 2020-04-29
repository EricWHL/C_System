$(info  cond.mk execute start)

DEBUG = 1

define newline


endef




ifdef DEBUG
INFO := DEBUG newline
else
INFO := newline
endif

$(info  $(INFO))

$(info  cond.mk execute end)

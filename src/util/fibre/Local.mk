ifdef FD_HAS_HOSTED
# Enable for both Linux and macOS
ifneq ($(filter 1,$(FD_HAS_LINUX) $(FD_HAS_ARM)),)
$(call make-lib,fd_fibre)
$(call add-objs,fd_fibre,fd_fibre)
$(call make-unit-test,test_fibre,test_fibre,fd_fibre fd_util)
$(call run-unit-test,test_fibre)
endif
endif

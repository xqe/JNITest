
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := printcpp
LOCAL_SRC_FILES := PrintCpp.cpp

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
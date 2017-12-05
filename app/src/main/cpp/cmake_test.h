//
// Created by xieqe on 2017/12/4.
//

#ifndef JNITEST_CMAKE_TEST_H
#define JNITEST_CMAKE_TEST_H

#include <jni.h>
#include <string>
#include <iostream>
#include <android/log.h>
#define LOG_TAG "XQE_JNI"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

//define LOG output in android
using namespace std;

void printString(JNIEnv* env,jobject obj);


#endif //JNITEST_CMAKE_TEST_H

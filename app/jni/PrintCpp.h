//
// Created by xieqe on 2017/10/12.
//

#ifndef JNITEST001_JNI_PRINTCPPSTRING_H
#define JNITEST001_JNI_PRINTCPPSTRING_H

#include <jni.h>

jstring PrintCpp_print(JNIEnv* env,jobject obj);
static jboolean PrintCpp_setPersonInfo(JNIEnv* env,jobject obj,jobject databean);
void PrintCpp_setListener(JNIEnv* env,jobject obj,jobject listener);

void onSuccess(JNIEnv* env);
void onFailed(JNIEnv* env);

jclass nativeListener;
#endif //JNITEST001_JNI_PRINTCPPSTRING_H

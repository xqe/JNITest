//
// Created by xieqe on 2017/10/12.
//

#ifndef JNITEST001_JNI_PRINTCPPSTRING_H
#define JNITEST001_JNI_PRINTCPPSTRING_H

#include <jni.h>

jstring PrintCpp_print(JNIEnv* env,jobject obj);
jboolean PrintCpp_setPerson(JNIEnv* env,jobject obj,jobject databean);
#endif //JNITEST001_JNI_PRINTCPPSTRING_H

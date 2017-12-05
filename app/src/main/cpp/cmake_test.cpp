#include "cmake_test.h"
//
// Created by xieqe on 2017/12/4.
//

extern "C"{

JNINativeMethod methods_printString[] =
{
    {"PrintLogFromCpp","()V",(void*) printString}
};

int jniRegisterNativeMethods(JNIEnv* env,const char* className,const JNINativeMethod* gMethods,int numMethods)
{
    jclass clazz = env->FindClass(className);
    env->RegisterNatives(clazz,gMethods,numMethods);
    LOGE("jniRegisterNativeMethods");
    return 1;
}

jint JNI_OnLoad(JavaVM* vm,void* reserved)
{
    LOGE("JNI_OnLoad");
    JNIEnv *pEnv = NULL;
    //get JNI version
    if ( vm->GetEnv((void**)&pEnv, JNI_VERSION_1_4) != JNI_OK)
    {

        LOGE("JNI_OnLoad error");
        return JNI_ERR;
    }

    jniRegisterNativeMethods(
            pEnv, "com/example/jnitest001/nativeClass/CmakeTest", methods_printString, sizeof(methods_printString) / sizeof(methods_printString[0]));

    return JNI_VERSION_1_4;
}
}

void printString(JNIEnv* env,jobject obj)
{
	LOGE("log from cpp");
}

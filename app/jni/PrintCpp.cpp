//
// Created by xieqe on 2017/10/12.
//
#include "PrintCpp.h"
#include <android/log.h>
#include <stdlib.h>
#include <stdio.h>
#define LOG_TAG "XQE_JNI"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

using namespace std;

extern "C"{


    JNINativeMethod methods_PrintCpp[] =
    {
        {"print","()Ljava/lang/String;",(void*) PrintCpp_print},
        {"setPerson","(Lcom/inpor/jnitest001nativeAdapter/Person;)Z",(void*)PrintCpp_setPerson}
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
        //获取JNI版本
        if ( vm->GetEnv((void**)&pEnv, JNI_VERSION_1_4) != JNI_OK)
        {
        	return JNI_ERR;
        }

		jniRegisterNativeMethods(
			pEnv, "com/inpor/jnitest001/nativeclass/PrintCpp", methods_PrintCpp, sizeof(methods_PrintCpp) / sizeof(methods_PrintCpp[0]));

        return JNI_VERSION_1_4;
    }
}

jstring PrintCpp_print(JNIEnv* env,jobject obj)
{
        jstring str = env->NewStringUTF("hahhahah");
        LOGE("PrintCppString_print:",str);
        return str;
}

jboolean PrintCpp_setPerson(JNIEnv* env,jobject obj,jobject databean)
{


}

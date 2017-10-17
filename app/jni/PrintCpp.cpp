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
        {"setPersonInfo","(Lcom/example/jnitest001/nativeAdapter/Person;)Z",(void*)PrintCpp_setPersonInfo},
        {"addListener","(Lcom/example/jnitest001/nativeAdapter/NativeListener;)V",(void*)PrintCpp_setListener}
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
        	return JNI_ERR;
        }

		jniRegisterNativeMethods(
			pEnv, "com/example/jnitest001/nativeclass/PrintCpp", methods_PrintCpp, sizeof(methods_PrintCpp) / sizeof(methods_PrintCpp[0]));

        return JNI_VERSION_1_4;
    }
}

jstring PrintCpp_print(JNIEnv* env,jobject obj)
{
    jstring str = env->NewStringUTF("string from cpp");
    if(str == NULL)
    {
        onFailed(env);
        str = env->NewStringUTF("error");
        return str;
    }
    const char* p = env->GetStringUTFChars(str,0);
    LOGE("PrintCpp_print:%s",p);
    //env->DeleteLocalRef(str);
    //onSuccess(env);
    return str;
}

static jboolean PrintCpp_setPersonInfo(JNIEnv* env,jobject obj,jobject personInfo)
{
	jclass clazz = env->GetObjectClass(personInfo);

	//get name 
	jfieldID nameID = env->GetFieldID(clazz, "name", "Ljava/lang/String;");
	jstring name =(jstring)env->GetObjectField(clazz,nameID);
    const char* nameData = env->GetStringUTFChars(name,0);
	LOGE("PrintCpp_setPersonInfo:%s",nameData);

	//get num
	jfieldID numID = env->GetFieldID(clazz, "num", "I");
	jint num = env->GetIntField(clazz, numID);
	LOGE("PrintCpp_setPersonInfo:%d", num);

	//get Male
	jfieldID maleID = env->GetFieldID(clazz,"isFeMale","Z");
	jboolean isFemale = env->GetBooleanField(clazz,maleID);
	LOGE("PrintCpp_setPersonInfo:%d", isFemale);

	//get id
	jfieldID idID = env->GetFieldID(clazz,"id","J");
	long id = (long)env->GetLongField(clazz,idID);
	LOGE("PrintCpp_setPersonInfo:%ld", id);

	//get static string
	jfieldID infoStrID = env->GetStaticFieldID(clazz,"infoStr","Ljava/lang/String;");
	jstring infoStr = (jstring)env->GetStaticObjectField(clazz,infoStrID);
	const char* infoStrData = env->GetStringUTFChars(infoStr,0);
    LOGE("PrintCpp_setPersonInfo:%s",infoStrData);


	//call method
    LOGE("-------call method---------");
	jmethodID showInfoMethodID = env->GetStaticMethodID(clazz,"showInfo","()V");
	env->CallStaticVoidMethod(clazz,showInfoMethodID);
    return true;
}

void PrintCpp_setListener(JNIEnv* env,jobject obj,jobject listener)
{
    nativeListener = env->GetObjectClass(listener);
}

void onSuccess(JNIEnv* env)
{
    /*
    jclass person = env->FindClass("com/example/jnitest001/nativeAdapter/Person");
    jfieldID nameID = env->GetFieldID(person, "name", "Ljava/lang/String;");
    //env->SetStringField()

    jfieldID numID = env->GetFieldID(person, "num", "I");
    env->SetIntField(person,numID,001);
    */

    jmethodID successID = env->GetMethodID(nativeListener,"onSuccess","(I)V");
    env->CallVoidMethod(nativeListener,successID,12);
}

void onFailed(JNIEnv* env)
{
    jmethodID failedID = env->GetMethodID(nativeListener,"onFailed","()V");
    env->CallVoidMethod(nativeListener,failedID);
}


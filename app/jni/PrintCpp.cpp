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
        {"getPerson","()Lcom/example/jnitest001/nativeAdapter/Person;",(void*)PrintCpp_getPerson},
        {"addListener","(Lcom/example/jnitest001/nativeAdapter/NativeListener;)V",(void*)PrintCpp_setListener},
        {"destory","()V",(void*)PrintCpp_destory}
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
    const char* p = env->GetStringUTFChars(str,0);
    LOGE("PrintCpp_print:%s",p);
    //env->DeleteLocalRef(str);
    return str;
}

jboolean PrintCpp_setPersonInfo(JNIEnv* env,jobject obj,jobject personInfo)
{
	jclass clazz = env->GetObjectClass(personInfo);
    if(clazz == NULL)
    {
        onFailed(env);
        return false;
    }
	//get name 
	jfieldID nameID = env->GetFieldID(clazz, "name", "Ljava/lang/String;");
	jstring name =(jstring)env->GetObjectField(personInfo,nameID);
    const char* nameData = env->GetStringUTFChars(name,0);
	LOGE("PrintCpp_setPersonInfo:%s",nameData);

	//get num
	jfieldID numID = env->GetFieldID(clazz, "num", "I");
	jint num = env->GetIntField(personInfo, numID);
	LOGE("PrintCpp_setPersonInfo:%d", num);

	//get Male
	jfieldID maleID = env->GetFieldID(clazz,"isFeMale","Z");
	jboolean isFemale = env->GetBooleanField(personInfo,maleID);
	LOGE("PrintCpp_setPersonInfo:%d", isFemale);

	//get id
	jfieldID idID = env->GetFieldID(clazz,"id","J");
	long id = (long)env->GetLongField(personInfo,idID);
	LOGE("PrintCpp_setPersonInfo:%ld", id);

	//get static string
	jfieldID infoStrID = env->GetStaticFieldID(clazz,"infoStr","Ljava/lang/String;");
	jstring infoStr = (jstring)env->GetStaticObjectField(clazz,infoStrID);
	const char* infoStrData = env->GetStringUTFChars(infoStr,0);
    LOGE("PrintCpp_setPersonInfo:%s",infoStrData);

	//call method
    jmethodID showMethodID = env->GetMethodID(clazz,"show","()V");
    env->CallVoidMethod(personInfo,showMethodID);

	jmethodID showInfoMethodID = env->GetStaticMethodID(clazz,"showInfo","()V");
	env->CallStaticVoidMethod(clazz,showInfoMethodID);

	jclass printCpp = env->GetObjectClass(obj);
	jmethodID testMethodID = env->GetMethodID(printCpp,"test","()V");
	env->CallVoidMethod(obj,testMethodID);

    onSuccess(env);
    return true;
}

static jobject PrintCpp_getPerson(JNIEnv* env,jobject obj)
{
    jclass clazz = env->FindClass("com/example/jnitest001/nativeAdapter/Person");
    jobject person = env->AllocObject(clazz);

    //set field
    jfieldID nameID = env->GetFieldID(clazz,"name","Ljava/lang/String;");
    env->SetObjectField(person,nameID,env->NewStringUTF("xqe_native"));

    jfieldID numID = env->GetFieldID(clazz,"num","I");
    env->SetIntField(person,numID,001);

    jfieldID idID = env->GetFieldID(clazz,"id","J");
    env->SetLongField(person,idID,987654321);

    jfieldID maleID = env->GetFieldID(clazz,"isFeMale","Z");
    env->SetBooleanField(person,maleID,true);

    return person;
}

void PrintCpp_setListener(JNIEnv* env,jobject obj,jobject listener)
{
    nativeListener = env->NewGlobalRef(listener);
}

void PrintCpp_destory(JNIEnv* env,jobject obj)
{
    env->DeleteGlobalRef(nativeListener);
    LOGE("PrintCpp destory");
}

void onSuccess(JNIEnv* env)
{
    jclass clazz = env->GetObjectClass(nativeListener);
    jmethodID successID = env->GetMethodID(clazz,"onSuccess","(I)V");
    env->CallVoidMethod(nativeListener,successID,12);
}

void onFailed(JNIEnv* env)
{
    jclass clazz = env->GetObjectClass(nativeListener);
    jmethodID failedID = env->GetMethodID(clazz,"onFailed","()V");
    env->CallVoidMethod(nativeListener,failedID);
}


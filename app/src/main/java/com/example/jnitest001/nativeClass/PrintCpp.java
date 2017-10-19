package com.example.jnitest001.nativeClass;

import android.util.Log;

import com.example.jnitest001.nativeAdapter.NativeListener;
import com.example.jnitest001.nativeAdapter.Person;

/**
 * Created by xieqe on 2017/10/12.
 */

public class PrintCpp {
    static{
        System.loadLibrary("printcpp");
    }
    public native String print();

    public native boolean setPersonInfo(Person person);

    public static native Person getPerson();

    public native void addListener(NativeListener listener);

    public native void destory();

    public void test(){
        Log.e("PrintCpp", "native call");
    }

    public static void throwException(){
        throw new NullPointerException("NullPointerException for test in java");
    }
}

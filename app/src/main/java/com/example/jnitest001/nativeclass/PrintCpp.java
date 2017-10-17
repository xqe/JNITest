package com.example.jnitest001.nativeclass;

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

    public static native boolean setPersonInfo(Person person);

    public native void addListener(NativeListener listener);
}

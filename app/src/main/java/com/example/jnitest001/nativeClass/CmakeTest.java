package com.example.jnitest001.nativeClass;

/**
 * Created by xieqe on 2017/12/4.
 */

public class CmakeTest {
    static{
        System.loadLibrary("cmake_test_lib");
    }

    public native void PrintLogFromCpp();
}

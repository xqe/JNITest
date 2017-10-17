package com.inpor.jnitest001.nativeclass;

import com.inpor.jnitest001.nativeAdapter.Person;

/**
 * Created by xieqe on 2017/10/12.
 */

public class PrintCpp {
    static{
        System.loadLibrary("printcpp");
    }
    public native String print();

    public native boolean setPerson(Person person);
}

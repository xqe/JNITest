package com.example.jnitest001.nativeAdapter;

import android.util.Log;

/**
 * Created by xieqe on 2017/10/16.
 */

public class Person {
    public String name = "xqe";
    public int num = 0;
    public long id = 0;
    public boolean isFeMale = false;
    public static String infoStr = "pserson";

    public Person(){

    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public boolean isMale() {
        return isFeMale;
    }

    public void setFeMale(boolean male) {
        isFeMale = male;
    }

    @Override
    public String toString() {

        String str = "Person{" +
                "name='" + name + '\'' +
                ", num=" + num +
                ", id=" + id +
                ", isMale=" + isFeMale +
                '}';
        Log.e("Person", "toString: " + str);
        return str;
    }

    public static void showInfo(){
        Log.e("Person", "native call static method");
    }

    public void show(){
        Log.e("Person", "show: " + this.toString() );
    }
}

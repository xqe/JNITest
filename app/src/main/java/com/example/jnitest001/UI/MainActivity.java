package com.inpor.jnitest001.UI;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.inpor.jnitest001.R;
import com.inpor.jnitest001.nativeclass.PrintCpp;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        PrintCpp printCpp = new PrintCpp();
        String result = printCpp.print();
        Log.i("===", "onCreate: "+result);
    }
}

package com.example.jnitest001.UI;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;
import com.example.jnitest001.R;
import com.example.jnitest001.nativeAdapter.NativeListener;
import com.example.jnitest001.nativeAdapter.Person;
import com.example.jnitest001.nativeClass.PrintCpp;

import butterknife.Bind;
import butterknife.ButterKnife;


public class MainActivity extends AppCompatActivity implements NativeListener{

    private static final String TAG = "MainActivity";
    @Bind(R.id.textView)
    TextView textView;

    PrintCpp printCpp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);
        testJNI();
    }

    public void testJNI(){
        printCpp = new PrintCpp();
        printCpp.addListener(MainActivity.this);
        String result = printCpp.print();
        textView.setText(result);
        Log.i(TAG, "testJNI: " + result);
        Person person = new Person();
        person.setName("xqe");
        person.setNum(123);
        person.setFeMale(true);
        person.setId(123456789);
        boolean isSuccess = printCpp.setPersonInfo(person);

        Person personNative = PrintCpp.getPerson();
        personNative.toString();
        Log.i(TAG, "testJNI: " + isSuccess);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        printCpp.destory();
        ButterKnife.unbind(this);
    }

    @Override
    public void onSuccess(int code) {
        Log.i(TAG, "onSuccess: " + code);
    }

    @Override
    public void onFailed() {
        Log.i(TAG, "onFailed: ");
    }
}

package com.example.jnitest001.UI;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;
import com.example.jnitest001.R;
import com.example.jnitest001.nativeAdapter.NativeListener;
import com.example.jnitest001.nativeAdapter.Person;
import com.example.jnitest001.nativeclass.PrintCpp;

import butterknife.Bind;
import butterknife.ButterKnife;


public class MainActivity extends AppCompatActivity implements NativeListener{

    private static final String TAG = "MainActivity";
    @Bind(R.id.textView)
    TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);
        testJNI();
    }

    public void testJNI(){
        new Thread(){
            @Override
            public void run() {
                super.run();
                PrintCpp printCpp = new PrintCpp();
                printCpp.addListener(MainActivity.this);
                String result = printCpp.print();
                textView.setText(result);
                Log.i(TAG, "testJNI: " + result);
                Person person = new Person();
                person.setName("xqe");
                person.setNum(123);
                person.setFeMale(true);
                person.setId(123456789);
                boolean isSuccess = PrintCpp.setPersonInfo(person);
                Log.i(TAG, "testJNI: " + isSuccess);
            }
        }.start();

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
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

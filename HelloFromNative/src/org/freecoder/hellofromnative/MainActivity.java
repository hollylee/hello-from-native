package org.freecoder.hellofromnative;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.widget.TextView;

public class MainActivity extends Activity {

    static {
        System.loadLibrary("hello_from_native");
    }
    
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        TextView nativeText = (TextView)findViewById(R.id.native_text);
        nativeText.setText("Hello from native: " + getCpuFeature());
        
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }
    
    private native String getCpuFeature();
}

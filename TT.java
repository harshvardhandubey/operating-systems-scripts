import java.lang.Thread;
class ThreadDemo extends Thread {
private Thread t;
private String threadName;
ThreadDemo( String name) {
threadName = name;
System.out.println(&quot;Creating &quot; + threadName );
}
public void run() {
System.out.println(&quot;Running &quot; + threadName );
try {
for(int i = 4; i &gt; 0; i--) {
System.out.println(&quot;Thread: &quot; + threadName + &quot;, &quot; + i);
// Let the thread sleep for a while.
Thread.sleep(50);
}
}catch (InterruptedException e) {
System.out.println(&quot;Thread &quot; + threadName + &quot; interrupted.&quot;);
}
System.out.println(&quot;Thread &quot; + threadName + &quot; exiting.&quot;);
}
public void start () {
System.out.println(&quot;Starting &quot; + threadName );
if (t == null) {
t = new Thread (this, threadName);
t.start ();
}
}
}
public class TT {
public static void main(String args[]) {
ThreadDemo T1 = new ThreadDemo( &quot;Thread 1&quot;);
T1.start();
ThreadDemo T2 = new ThreadDemo( &quot;Thread 2&quot;);
T2.start();
}
}
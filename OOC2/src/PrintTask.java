import java.util.Random;


public class PrintTask implements Runnable {

    private final String taskName;
    private final int sleepTime;
    private final static Random generator = new Random();

    public PrintTask(String name) {
        taskName = name;
        sleepTime = generator.nextInt(5000);
    }

    @Override
    public void run() {
        try {
            System.out.printf("%s going to sleep for %d milliseconds.\n", taskName, sleepTime);
            Thread.sleep(sleepTime);
        } catch (InterruptedException eeception) {
            System.out.printf("%s %s terminated due to interruption\n", taskName);
        }
        System.out.printf("%s done sleeping\n", taskName);
    }
}

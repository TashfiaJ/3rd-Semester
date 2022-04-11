
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class SharedArrayTest{
    public static void main(String[] args) {
        SimpleArray sharedSimpleArray = new SimpleArray(6);
        ArrayWriter aw1 = new ArrayWriter(1,sharedSimpleArray);
        ArrayWriter aw2 = new ArrayWriter(11,sharedSimpleArray);

        ExecutorService executorService = Executors.newCachedThreadPool();

        executorService.execute(aw1);
        executorService.execute(aw2);

        executorService.shutdown();

        try{
            boolean taskEnded = executorService.awaitTermination(1, TimeUnit.MINUTES);
            if(taskEnded){
                System.out.println(sharedSimpleArray);
            }
            else{
                System.out.println("Timed out..");
            }
        } catch (InterruptedException interruptedException) {
            interruptedException.printStackTrace();
        }
    }

}


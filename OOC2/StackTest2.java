public class StackTest2{
    private Double[] doubleElements = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
    private Integer[] integerElements = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    private Stack<Double>doubleStack;
    private Stack<Integer>integerStack;

    public void testStacks(){
        doubleStack=new Stack<>(5);
        integerStack=new Stack<>(10);
        testPush("doubleStack",doubleStack,doubleElements);
        testPop(doubleStack);
        testPush("integerStack",integerStack,integerElements);
        testPop(integerStack);
    }
    public <T>void testPush(String name, Stack<T>stack2, T[] elements){
        try{
            System.out.println("Pushing elements onto doubleStack");
            for(T element:elements){
                System.out.printf("%s ",element);
                stack2.push(element);
            }
            System.out.println();
        }
        catch (FullStackException fullStackException2){
            System.err.println();
            fullStackException2.printStackTrace();
        }
    }
    public<T> void testPop(Stack<T>stack2)
    {
        try
        {
            System.out.println( "\nPopping elements from doubleStack" );
            T popValue; // store element removed from stack

            // remove all elements from Stack
            while ( true )
            {
                popValue = stack2.pop(); // pop from doubleStack
                System.out.printf( "%s ", popValue );
            }
        }
        catch( EmptyStackException emptyStackException2 )
        {
            System.err.println();
            emptyStackException2.printStackTrace();
        }
    }

    public static void main(String[] args) {
        StackTest2 application=new StackTest2();
        application.testStacks();
    }
}

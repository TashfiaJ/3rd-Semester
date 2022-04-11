public class GenericMethodTest {
    public static <E>void printArray(E[] inputArray){
        for(E element: inputArray){
            System.out.printf("%s ",element);
        }
        System.out.println();
    }
    public static void main(String[]args){
        Integer[] IntegerArray={1,2,3,4,5,6};
        Double[] doubleArray={1.1,2.2,3.3};
        Character[] characterArray={'a','b','c'};
        System.out.println("Array IntegerArray contains: ");
        printArray(IntegerArray);
        System.out.println("Array doubleArray contains: ");
        printArray(doubleArray);
        System.out.println("Array characterArray contains: ");
        printArray(characterArray);
    }
}

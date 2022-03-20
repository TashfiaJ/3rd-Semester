public class OverloadedMethods
{
    public static void printArray(Integer[] intputArray){
        for(Integer element:intputArray){
            System.out.printf("%s ",element);
        }
        System.out.println();
    }
    public static void printArray(Double[] intputArray){
        for(Double element:intputArray){
            System.out.printf("%s ",element);
        }
        System.out.println();
    }
    public static void printArray(Character[] intputArray){
        for(Character element:intputArray){
            System.out.printf("%s ",element);
        }
        System.out.println();
    }
    public static void main(String[] args) {
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

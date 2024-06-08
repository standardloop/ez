public class Main {
  public static void main(String[] args) {
    Person people[];
    people = new Person[2];
    people[0] = new Person("Josh", 26);
    people[1] = new Person("EZ", 26);

    for(int i = 0; i < 2; i++) 
    {
        System.out.println(people[i].getName() + " is " + people[i].getAge() + " years old.");
    }
  }
}

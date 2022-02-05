public interface ABC{
    public void doIt(float x);
}

public class B implements ABC{
    public void doIt(float x){
        System.out.println("le doItuble de x est " +2*x);
    }
}

public class C implements ABC{
    public void doIt(float x){
        for(int i=0; i<x; i++)
        {
            System.out.println("coucou");
        }
    }
}

public class A implements ABC{
    public void doIt(float x){
        if(x != 0)
        {
            System.out.println("l'inverse de x est " +1/x);
        }
    }
}

public class AA extends A{
    public void doIt(float x){
        super.doIt(x);
        if(x>0)
        {
            System.out.println("racine carré" +Math.sqrt(x));
        }
    }
}

public class D{
    public Collection<ABC> myABCList = new Vector<ABC>;
    public void doAll(float x){
        ABC obj;
        Iterator it = myABCList.Iterator();
        while((it.hasNext())){
             obj = (ABC) it.next();
             obj.doIt(x);
        }
    }

    public void add (ABC e)
    {
        myABCList.addElement(e);
    } 
}

D d = new D();
A a = new A();
B b = new B();
AA aa = new AA();
d.add(a);
d.add(b);
d.add(aa);
d.doAll(4);

/*
l'inverse de 4 est 0.25
le double de 4 est 8
l'inverse de 4 est 0.25
*/
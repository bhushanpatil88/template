#include <bits/stdc++.h>
using namespace std;


class A;


class C{
  public:
  void func1(A &obj);
};

class B{
  public:
  void display(A &obj);
};


class A{
    private:
    int a=10;
    protected:
    int b = 20;
    public:
    
    int c = 30;
    
    // friend class
    friend class B;
    
    // friend function
    friend void func(A& obj);
    
    // friend member function of another class
    friend void C::func1(A& obj);
};



void B::display(A &obj){
  cout<<obj.a<<" "<<obj.b<<" "<<obj.c<<'\n';
}



void C::func1(A &obj){
    cout<<obj.a<<" "<<obj.b<<" "<<obj.c<<'\n';
}

void func(A& obj){
    cout<<obj.a<<" "<<obj.b<<" "<<obj.c<<'\n';
}





int main()
{
    A obj_a;
    B obj_b;
    func(obj_a);
    obj_b.display(obj_a);
    C obj_c;
    obj_c.func1(obj_a);
    return 0;
}

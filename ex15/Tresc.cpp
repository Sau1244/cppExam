int main()
{
    typedef B<A> B_A;
    using TypeName = B<B_A>;
    TypeName a = TypeName(TypeName{});
    TypeName b(a);
}

/*
Copy 1BI1AE()
Copy 1BIS_I1AEE()
~A()
~A()
~A()
~A()
~A()
~A()
 */

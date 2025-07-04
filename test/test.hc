// Test HolyC code for Windows compiler
class TestClass {
    I64 value;
};

U0 TestFunction(I64 x) {
    "Testing Windows compiler: %d\n", x;
}

U0 Main() {
    TestClass *t = MAlloc(sizeof(TestClass));
    t->value = 42;
    
    TestFunction(t->value);
    Free(t);
}

Main;
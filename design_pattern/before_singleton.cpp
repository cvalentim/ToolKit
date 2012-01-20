// A global variable is default initialized -
// when it is declared - but it is not ini-
// tialized in earnest until its first use.
// This requires that the initialization
// code be replicated throughout the appli-
// cation.

class GlobalClass {
   int  m_value;
public:
   GlobalClass( int v=0 )  { m_value = v; }
   int  get_value()        { return m_value; }
   void set_value( int v ) { m_value = v; }
};

// Default initialization
GlobalClass*   global_ptr = 0;

void foo( void ) {
   // Initialization on first use
   if ( ! global_ptr )
      global_ptr = new GlobalClass;
   global_ptr->set_value( 1 );
   cout << "foo: global_ptr is "
        << global_ptr->get_value() << '\n';
}

void bar( void ) {
   if ( ! global_ptr )
      global_ptr = new GlobalClass;
   global_ptr->set_value( 2 );
   cout << "bar: global_ptr is "
        << global_ptr->get_value() << '\n';
}

int main( void ) {
   if ( ! global_ptr )
      global_ptr = new GlobalClass;
   cout << "main: global_ptr is "
        << global_ptr->get_value() << '\n';
   foo();
   bar();
}

// main: global_ptr is 0
// foo: global_ptr is 1
// bar: global_ptr is 2

// The number and type of "user interface" (or
// dependent) objects is hard-wired in the
// Subject class.  The user has no ability to
// affect this configuration.

class DivObserver {
   int  m_div;
public:
   DivObserver( int div ) { m_div = div; }
   void update( int val ) {
      cout << val << " div " << m_div << " is "
           << val / m_div << '\n';
}  };

class ModObserver {
   int  m_mod;
public:
   ModObserver( int mod ) { m_mod = mod; }
   void update( int val ) {
      cout << val << " mod " << m_mod << " is "
           << val % m_mod << '\n';
}  };

class Subject {
   int  m_value;
   DivObserver  m_div_obj;
   ModObserver  m_mod_obj;
public:
   Subject() : m_div_obj(4), m_mod_obj(3) { }
   void set_value( int value ) {
      m_value = value;
      notify();
   }
   void notify() {
      m_div_obj.update( m_value );
      m_mod_obj.update( m_value );
}  
};

int main( void ) {
   Subject  subj;
   subj.set_value( 14 );
}

// 14 div 4 is 3
// 14 mod 3 is 2

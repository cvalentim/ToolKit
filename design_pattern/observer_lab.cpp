// Purpose.  Observer design pattern lab.
//
// Problem.  Undue coupling exists between Subject and Observer.  Subject
// has the number and type of Observer objects hard-wired in its class
// declaration.  Subject knows (or unilaterally decides) what information
// each Observer instance needs, and then "pushes" that information to the
// Observer (rather than having the Observer "pull" whatever it needs)
// whenever a change occurs.
//
// Assignment.
// o Add an Observer base class for Hex, Oct, and Roman
// o Remove the Observer objects from Subject, and replace them with an
//   array of 10 pointers to the Observer base class
// o Add an "attach" method to Subject so that Observer objects can register
//   themselves 
// o Add a "notify" method to Subject that broadcasts to all registered
//   Observers whenever a change occurs
// o Add a "getState" method to Subject for Observer objects to use
// o Call Subject's notify() from Subject's setState().
// o Add a Subject* data member to the Observer hierarchy.
// o The Observer hierarchy constructors should accept a Subject* as an
//   argument.  The derived class ctors can either pass the Subject* they
//   receive to their base class ctor, or, they can initialize the Subject*
//   data member themselves.
// o Observer objects should attach themselves to their Subject in their
//   constructor.
// o Rewrite the Observer "update" method so that it requests what it wants
//   from Subject instead of receiving an input argument.
// o In main(), create one of each type of Observer

#include <iostream.h>

class HexObserver {
public:
   void update( int val ) {
      cout << "hex: 0x" << hex << val << endl;
   }
};

class OctObserver {
public:
   void update( int val ) {
      cout << "oct:  0" << oct << val << endl;
   }
};

class RomanObserver {
public:
   void update( int val );
};


class Subject {
public:
   void setState( int val ) {
      subjectState = val;
      hexObserver.update( subjectState );
      octObserver.update( subjectState );
      romanObserver.update( subjectState );
   }
private:
   int            subjectState;
   HexObserver    hexObserver;
   OctObserver    octObserver;
   RomanObserver  romanObserver;
};

void main( void ) {
   Subject  subj;
   int      value;

   cout << "Input integer: ";
   while (cin >> value) {
      subj.setState( value );
      cout << "\nInput integer: ";
   }
}

// Input integer: 31
// hex: 0x1f
// oct:  037
// roman: XXXI
// 
// Input integer: 32
// hex: 0x20
// oct:  040
// roman: XXXII
// 
// Input integer: 48
// hex: 0x30
// oct:  060
// roman: XLVIII

void RomanObserver::update( int val ) {
   static char* table[3][4] =
      {"CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
   cout << "roman: ";
   if (val > 3999) {
      cout << "****" << endl;
      return;
   }
   while (val >= 1000) {
      cout << "M";
      val -= 1000;
   }
   for (int multiplier = 100, index = 0; multiplier >= 1;
                                         multiplier /= 10, index++) {
      if (val >= 9 * multiplier) {
         cout << table[index][0];
         val -= 9 * multiplier;
      } else if (val >= 5 * multiplier) {
         cout << table[index][1];
         val -= 5 * multiplier;
      } else if (val >= 4 * multiplier) {
         cout << table[index][2];
         val -= 4 * multiplier;
      }
      while (val >= 1 * multiplier) {
         cout << table[index][3];
         val -= 1 * multiplier;
      }
   }
   cout << endl;
}

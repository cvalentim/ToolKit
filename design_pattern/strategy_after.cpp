// Purpose.  Strategy                   #include <iostream.h>
//                                      #include <stdlib.h>
// Discussion.  The class Stat has a    #include <time.h>
// Bubble sort algorithm hard-wired in
// it.  It would be nice if the choice  class SortImp;
// of algorithm were configurable.
// The Strategy pattern suggests "de-   class Stat {
// fine a family of algo's, encapsu-    public:
// late each one, and make them inter-     Stat();
// changeable" via an abstract base        void upGrade();
// class.                                  void downGrade();
                                           void readVector( int[], int );
class Stat {     /* Bubble sort */         int getMin() { return min_; }
public:                                    int getMax() { return max_; }
   void readVector( int v[], int n ) {     int getMed() { return med_; }
      sort_( v, n );                    private:
      min_ = v[0];   max_ = v[n-1];        int min_, max_, med_;
      med_ = v[n/2]; }                     SortImp*  imp_;
   int getMin() { return min_; }        };
   int getMax() { return max_; }
   int getMed() { return med_; }        class SortImp { public:
private:                                   virtual void sort( int[], int ) = 0;
   int min_, max_, med_;                };
   void sort_( int v[], int n ) {
      for (int i=n-1; i > 0; i--)       class SortBubble : public SortImp {
         for (int j=0; j < i; j++)      public:
            if (v[j] > v[j+1]) {           void sort( int v[], int n );
               int t = v[j];            };
               v[j] = v[j+1];
               v[j+1] = t; }            class SortShell : public SortImp {
      cout << "Bubble: ";               public:
      for (int k=0; k < n; k++)            void sort( int v[], int n );
         cout << v[k] << ' ';           };
      cout << endl;
   }                                    #include "strategy2.inc"
};
                                        Stat::Stat() { imp_ = new SortBubble; }
void main( void )                       void Stat::upGrade()   { delete imp_;
{                                          imp_ = new SortShell; }
   const int NUM = 9;                   void Stat::downGrade() { delete imp_;
   int       array[NUM];                   imp_ = new SortBubble; }
   time_t    t;                         void Stat::readVector(int v[], int n) {
   srand((unsigned) time(&t));             imp_->sort( v, n );
   cout << "Vector: ";                     min_ = v[0];   max_ = v[n-1];
   for (int i=0; i < NUM; i++) {           med_ = v[n/2]; }
      array[i] = rand() % 9 + 1;
      cout << array[i] << ' '; }        void main( void )
   cout << endl;                        {
                                           const int NUM = 9;
   Stat  obj;                              int       array[NUM];
   obj.readVector( array, NUM );           time_t    t;
   cout << "min is " << obj.getMin()       srand((unsigned) time(&t));
      << ", max is " << obj.getMax()       cout << "Vector: ";
      << ", median is " << obj.getMed()    for (int i=0; i < NUM; i++) {
      << endl;                                array[i] = rand() % 9 + 1;
}                                             cout << array[i] << ' '; }
                                           cout << endl;
/***** current implementation *****/
// Vector: 6 9 9 8 6 5 7 9 2               Stat  obj;
// Bubble: 2 5 6 6 7 8 9 9 9               obj.upGrade();
// min is 2, max is 9, median is 7         obj.readVector( array, NUM );
/*** an upgraded implementation ***/       cout << "min is " << obj.getMin()
// Vector: 4 8 6 4 6 7 4 7 2                  << ", max is " << obj.getMax()
// Shell:  2 4 4 4 6 6 7 7 8                  << ", median is " << obj.getMed()
// min is 2, max is 8, median is 6            << endl;
                                        }

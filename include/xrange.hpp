#ifndef _XRANGE_HPP_
#define _XRANGE_HPP_

#include <limits>
#include <cmath>

namespace cpphpp{
  template <typename T> bool
  nearzero(T x){
    return x <= std::numeric_limits<T>::epsilon();
  }
  
  template <typename T>
  struct xrange_t{
    T start,stop,step;
    
    struct xrange_num{
      typedef xrange_num mytype;
      xrange_num(T _x, T _step, bool _isend=false) :
        x(_x), step(_step), isend(_isend) {}
      const T& operator*() const {return x;}
      T& operator++() { x+=step; return *this; }
      operator const T&() const { return x;}
      operator T&() { return x;}
      bool operator==(const mytype& in)  const {
        if (isend) {
          return (step > 0 ? in.x >= x : in.x <= x);
        } else if (in.isend) {
          return (step > 0 ? in.x <= x : in.x >= x);
        } else {
          return in.x == x;
        }
      }
      bool operator!=(const mytype& in)const{
        return ! (*this == in);}
    private:
      bool isend;
      //HACKING TIME
      T x, step;
    };
    //constructors
    xrange_t(T _start,T _end, T _step=1) :
      start(_start), stop(_end), step(_step){}
    xrange_t(T _end) : xrange_t(0,_end){}
    //for for range loops...and the like
    xrange_num begin() const { return xrange_num(start,step); }
    xrange_num end() const { return xrange_num(stop,step,true); }
    size_t N() const {
      return std::floor((stop-start)/step);}
  };
  /*factories...for ease of use without explicit template
   * arguments everywhere.
   * the only fucking annoyance is of course, one needs
   * to either
   * 1) specify their arguments' types explicitly
   * 2) specify the template directly
   * 
   * C++, full of lovely, leaky abstractions.
   */
  
  template <typename T>
  xrange_t<T> xrange(T start, T stop, T step=1){
    return xrange_t<T>(start,stop,step);
  }
  template <typename T>
  xrange_t<T> xrange(T stop){
    return xrange_t<T>(0,stop);
  }

  /*because why not*/
  template <typename T>
  size_t
  len(const xrange_t<T>& in){return in.N();}
}

#endif //_XRANGE_HPP_

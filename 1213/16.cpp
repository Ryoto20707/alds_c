#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

template<class T>
std::ostream& operator << (std::ostream& os, std::vector<T> vec){
  std::size_t n = vec.size();
  if(n == 0){
    return os;
  }
  for(int i = 0; i<n - 1; ++i){
    os << vec[i] << " ";
  }
  os << vec[n - 1];
  return os;
}

typedef std::vector<int> stat;

//m+n-1 C r
int solve(int m, int n){
  int lhs = m + n;
  int rhs = n;
  long long r = 1;

  
  for(int i = lhs; i != lhs - rhs ; --i){
    // std::cout << i << " ";
    r *= i;
  }
  for(int i = 1; i != rhs + 1; ++i){
    // std::cout << i << " ";
    r /= i;
  }
  return r;
}

#ifndef BOOST_TEST_MAIN
int main(int const argc, char const** argv){

  int m, n;
  std::cin >> m;
  std::cin >> n;

  std::cout << solve(m - n, n - 1) << std::endl;

}
#endif

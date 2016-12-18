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


#ifndef BOOST_TEST_MAIN
int main(int const argc, char const** argv){
  int n;
  std::cin >> n;
  std::vector<int> v;

  for(int i = 0; i<n; ++i){
    int x;
    std::cin >> x;
    v.push_back(x);
  }
  int count = 0;
  for(int i = 0; i != v.size(); ++i){
    for(int j = i; j != v.size(); ++j){
      if(v[i]<v[j]){
	++count;
      }
    }
  }
  std::cout << count << std::endl;
}
#endif

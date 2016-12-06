#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

template<class T>
void printvec(std::vector<T> vec){
  std::size_t n = vec.size();
  for(int i = 0; i<n - 1; ++i){
    std::cout << vec[i] << " ";
  }
  std::cout << vec[n - 1] << std::endl;
}

template<class T>
void printstack(std::stack<T> const st){
  std::stack<T> st2 = st; // copy
  while(!st2.empty()){
    std::cout << st2.top() << " ";
    st2.pop();
  }
  std::cout << std::endl;
}

template<class T>
void printqueue(std::queue<T> const q){
  std::stack<T> q2 = q; // copy
  while(!q2.empty()){
    std::cout << q2.top() << " ";
    q2.pop();
  }
  std::cout << std::endl;
}

int solve(std::vector<int> & v){
  if(v.size() == 1){
    return v[0];
  }else if(v.size() > 1){
    int halflen = v.size()/2;
    std::vector<int>::iterator iter = v.begin() + halflen;
    std::vector<int> fh(v.begin(), iter), th(iter, v.end());
    int fhmx = solve(fh);
    std::cout << fhmx << std::endl;
    
    int thmx = solve(th);

    std::cout << thmx << std::endl;
    int val = std::max(fhmx, thmx);
    return val;
  }
}

int main(int const argc, char const** argv){
  int n;
  std::vector<int> vec;
  std::cin >> n;
  for(int i = 0; i < n; ++i){
    int j;
    std::cin >> j;
    vec.push_back(j);
  }

  std::cout << solve(vec) << std::endl;
  
}

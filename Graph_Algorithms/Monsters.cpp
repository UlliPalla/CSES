input/code.cpp: In function 'int main()':
input/code.cpp:148:18: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
  148 |     for(int i=0;i<sol.size();i++)
      |                 ~^~~~~~~~~~~
input/code.cpp:58:11: warning: 'a_x' may be used uninitialized [-Wmaybe-uninitialized]
   58 |     q.push({a_x,a_y});
      |     ~~~~~~^~~~~~~~~~~
input/code.cpp:12:8: note: 'a_x' was declared here
   12 |     ll a_x,a_y;
      |        ^~~
input/code.cpp:58:11: warning: 'a_y' may be used uninitialized [-Wmaybe-uninitialized]
   58 |     q.push({a_x,a_y});
      |     ~~~~~~^~~~~~~~~~~
input/code.cpp:12:12: note: 'a_y' was declared here
   12 |     ll a_x,a_y;
      |            ^~~
input/code.cpp:114:30: warning: 'b_x' may be used uninitialized [-Wmaybe-uninitialized]
  114 |     cout<<"YES\n"<<dist_P[b_x][b_y];
      |                              ^
input/code.cpp:79:8: note: 'b_x' was declar...
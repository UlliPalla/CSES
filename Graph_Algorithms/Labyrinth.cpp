input/code.cpp: In function 'int main()':
input/code.cpp:105:18: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
  105 |     for(int i=0;i<sol.size();i++)
      |                 ~^~~~~~~~~~~
input/code.cpp:46:11: warning: 'a_x' may be used uninitialized [-Wmaybe-uninitialized]
   46 |     q.push({a_x,a_y});
      |     ~~~~~~^~~~~~~~~~~
input/code.cpp:12:8: note: 'a_x' was declared here
   12 |     ll a_x,a_y;
      |        ^~~
input/code.cpp:46:11: warning: 'a_y' may be used uninitialized [-Wmaybe-uninitialized]
   46 |     q.push({a_x,a_y});
      |     ~~~~~~^~~~~~~~~~~
input/code.cpp:12:12: note: 'a_y' was declared here
   12 |     ll a_x,a_y;
      |            ^~~
input/code.cpp:63:16: warning: 'b_x' may be used uninitialized [-Wmaybe-uninitialized]
   63 |     if(dist[b_x][b_y]==LONG_LONG_MAX)
      |                ^
input/code.cpp:13:8: note: 'b_x' was declared here
   13...
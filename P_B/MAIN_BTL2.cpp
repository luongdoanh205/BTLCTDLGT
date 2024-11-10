#include <bits/stdc++.h>
#include "./STACK_BTL.cpp" 
#include "./VECTOR.cpp"
#include "./DO_THI_BTL.cpp"
using namespace std;
int main(){
	Graph g(0);
    g.readFromFile("doThi.txt");
    g.display();  
	g.DFS(); 
    g.writeToFile("outDT.txt");
    return 0;
} 

#include <bits/stdc++.h>
#include "./STACK_BTL.cpp" 
#include "./VECTOR.cpp"
#ifndef __GRAPH__
#define __GRAPH__ 
using namespace std;
class Graph {
private:
    int vertices;                    
    Vector<Vector<int>> adjMatrix; 

public:
    Graph(int V) : vertices(V), adjMatrix(V, Vector<int>(V, 0)) {}

    void readFromFile(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Khong thay tep " << filename << endl;
            return;
        }

        file >> vertices;  
        adjMatrix.resize(vertices, Vector<int>(vertices, 0));

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                file >> adjMatrix[i][j];
            }
        }

        file.close();
    }
    
	void writeToFile(const string &filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Khong thay tep " << filename << endl;
            return;
        }

        file << vertices << endl;  

        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                file << adjMatrix[i][j] << " ";
            }
            file << endl;
        }

        file.close();
    }

    void display() const {
        cout << "Ma tran ke :" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
	void DFS() {
		int start, target;
		cout << "nhap dinh dau tien :";
		cin >> start;
		cout << "nhap dinh thu 2 :";
		cin >> target;
		start--;
		target--;
	    Stack<int> stack1;
	    Vector<bool> visited(vertices, false);
	    Vector<int> path;
	
	    stack1.push(start);
	    visited[start] = true;
	
	    bool found = false;
	
	    cout << "duong di DFS tu " << start+1 << " den " << target+1 << ":" << endl;
	    
	    while (!stack1.isEmpty()) {
	        int vertex = stack1.Top();
	        stack1.pop();
	        path.push_back(vertex);
	
	        if (vertex == target) {
	            found = true;
	            break;
	        }
	
	        for (int i = 0; i < vertices; i++) {
	            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
	                stack1.push(i);
	                visited[i] = true;
	            }
	        }
	    }
	
	    if (found) {
	        for (int v : path) {
	            cout << v+1 << " ";
	        }
	        cout << endl;
	    } else {
	        cout << "Khong co duong di tu dinh " << start+1 << " den " << target+1 << "." << endl;
	    }
	}
 
};
#endif


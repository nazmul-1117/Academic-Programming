//Depth First Search using Adjacency Matrix

import java.util.*;
class DFSusingMatrix {

	private int V;
	private int E;
	private boolean[] visited;
	private Stack<Integer> st;

	public DFSusingMatrix(int V) {
		this.V = V;
		visited = new boolean[V];
		st = new Stack<>();
	}

	public void DFS(GraphMatrix g, int s) {

	    int[][] graph = g.getAdjMatrix();
		visited[s] = true;
		st.push(s);

		System.out.println("DFS using Natrix: " );

		while(!st.empty()) {
			int u = st.pop();
			System.out.print(u + " ");
            
            //get adjacency list of u node.
			for(int i=0; i < this.V; i++) {
			    
			    // if u have any adjacency list and it was not visited then add it on queue;
				if((graph[u][i]==1) && (!visited[i])) {
					visited[i] = true;
					st.push(i);
				}
			}
		}
		System.out.println();
	}
}
//Depth First Search using Adjacency List

import java.util.*;
class DFSusingList {

	private int V;
	private int E;
	private boolean[] visited;
    private Stack<Integer> st;
    
	public DFSusingList(int V) {
		this.V = V;
		visited = new boolean[V];
		st = new Stack<>();
	}

	public void DFS(GraphList g, int s) {

		LinkedList<Integer>[] graph =  g.getAdjList();
		visited[s] = true;
		st.push(s);

		System.out.println("DFS using List: " );

		while(!st.empty()) {
			int u = st.pop();
			System.out.print(u + " ");
            
            // get Adjacency list of u;
            for (int v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    st.push(v);
                }
            }
		}
	}
}
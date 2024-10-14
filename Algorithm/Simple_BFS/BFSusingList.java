//Breath First Search using Adjacency List

import java.util.*;
class BFSusingList {

	private int V;
	private int E;
	private boolean[] visited;
	private Queue<Integer> q;

	public BFSusingList(int V) {
		this.V = V;
		visited = new boolean[V];
		q = new LinkedList<>();
	}

	public void BFS(GraphList g, int s) {

		LinkedList<Integer>[] graph =  g.getAdjList();

		visited[s] = true;
		q.add(s);

		System.out.println("BFS using List: " );

		while(!q.isEmpty()) {
			int u = q.poll();
			System.out.print(u + " ");
            
             //get adjacency list of u node.
			for(int v: graph[u]) {
			    
			    // if it is not visited then explor it
				if( !visited[v] ) {
					visited[v] = true;
					q.add(v);
				}
			}
		}
	}
}
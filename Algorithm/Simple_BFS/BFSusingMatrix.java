//Breath First Search using Adjacency Matrix

import java.util.*;
class BFSusingMatrix {

	private int V;
	private int E;
	private boolean[] visited;
	private Queue<Integer> q;

	public BFSusingMatrix(int V) {
		this.V = V;
		visited = new boolean[V];
		q = new LinkedList<>();
	}

	public void BFS(GraphMatrix g, int s) {

		int[][] graph = g.getAdjMatrix();

		visited[s] = true;
		q.add(s);

		System.out.println("BFS using Natrix: " );

		while(!q.isEmpty()) {
			int u = q.poll();
			System.out.print(u + " ");
            
            //get adjacency list of u node.
			for(int i=0; i < this.V; i++) {
			    
			    // if u have any adjacency list and it was not visited then add it on queue;
				if((graph[u][i]==1) && (!visited[i])) {
					visited[i] = true;
					q.add(i);
				}
			}
		}
		System.out.println();
	}
}
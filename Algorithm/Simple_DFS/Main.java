
public class Main{
    
	public static void main(String[] args) {
		int V=5;
		int E=4;
		
        // create both graph Adjacency list and Matrix
		GraphMatrix graphMatrix = new GraphMatrix(V);
		GraphList graphList = new GraphList(V);
		
        // create add edges class for add edge
		AddEdges addEdges = new AddEdges(V);
		
		// Edge added for both graph
		addEdges.addEdgeMatrix(graphMatrix);
		addEdges.addEdgeList(graphList);
		
		System.out.println("Graph Created");
		
		// print the both graph
		addEdges.displayMatrix(graphMatrix);
		addEdges.displayList(graphList);
		
		
		// Apply DFS for Natrix;
		int startNode = 2;
		DFSusingMatrix dfsMatix = new DFSusingMatrix(V);
		dfsMatix.DFS(graphMatrix, startNode);
		
		// Apply DFS for List;
	   // startNode = 4;
		DFSusingList dfsList = new DFSusingList(V);
		dfsList.DFS(graphList, startNode);
		
	}
}

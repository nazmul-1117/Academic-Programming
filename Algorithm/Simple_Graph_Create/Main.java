
public class Main{
    
	public static void main(String[] args) {
		int V=4;
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
		
	}
}

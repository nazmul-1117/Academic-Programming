//this class is for adjacency matrix;

class GraphMatrix{
    private int V;
    private int E;
    
    private int[][] adjMatrix;
    
    public GraphMatrix(int V){
        this.V = V;
        this.E = 0;
         adjMatrix = new int[V][V];
         
         System.out.println("I am from Graph Matrix");
    }
    
    // edges add for bi-directional graph
    public void addEdges(int src, int dest, int weight){
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;
    }
    
    // normal return the matrix for display the graph
    public int[][] getAdjMatrix(){
        return adjMatrix;
    }
}
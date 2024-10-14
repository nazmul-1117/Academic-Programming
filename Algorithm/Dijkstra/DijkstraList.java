

class DijkstraList{
    
    private int V;
    private int E;
    private int[][] gp;
    
    public DijkstraList(int V){
        this.V = V;
        this.E = 0;
    }
    
    void printSolution(int dist[]){
        
        System.out.println("Vertex \t\t Distance from Source");
        for (int i = 0; i < V; i++){
            System.out.println(i + " \t\t " + dist[i]);   
        }
    }
}
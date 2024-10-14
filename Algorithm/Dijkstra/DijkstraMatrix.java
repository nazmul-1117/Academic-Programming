
class DijkstraMatrix{
    
    private int V;
    private int E;
    private int[][] gp;
    
    public DijkstraMatrix(int V){
        this.V = V;
        this.E = 0;
    }
    
    void printSolution(int dist[]){
        
        System.out.println("Vertex \t\t Distance from Source");
        for (int i = 0; i < V; i++){
            System.out.println(i + " \t\t " + dist[i]);   
        }
    }
    
    int minimumDistanceIndex(int[] distance, boolean[] visited){
        
        int minData = Integer.MAX_VALUE;
        int minIndex = -1;
        
        for(int i=0; i<V; i++){
            
            if(!visited[i] && minData >= distance[i]){
                minData = distance[i];
                minIndex = i;
            }
        }
        
        return minIndex;
    }
    
    void dijkstra(GraphMatrix g, int src){
        gp = g.getAdjMatrix();
        
        int[] distance = new int[V];
        boolean[] visited = new boolean[V];
        
        for(int i=0; i<V; i++){
            distance[i] = Integer.MAX_VALUE;
            visited[i] = false; 
        }
        
        distance[src] = 0;
        
        //traversing all node;
        for(int count=0; count<V; count++){
            
            //get the minimum distance node index, like priority queue;
            int u = minimumDistanceIndex(distance, visited);
            visited[u] = true;
            
            // explore and update the adjacency node cost;
            for(int v=0; v<V; v++){
                
                int weight = gp[u][v];
                if(!visited[v] && weight != 0 && distance[u] + weight < distance[v]){
                     distance[v] = distance[u] + weight;
                }
            }
        }
        printSolution(distance);
    }
}
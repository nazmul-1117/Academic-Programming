
import java.util.*;

// simple undirected graph

//              0-------1
//              |       |
//              |       |
//              |       |
//              3-------2

class AddEdges{
    private int V;
    private int E;
    
    public AddEdges(int V){
        this.V = V;
        this.E = 0;
    }
    
    public void addEdgeMatrix(GraphMatrix g){
        g.addEdges(0, 1);
        g.addEdges(1, 2);
        g.addEdges(2, 3);
        g.addEdges(3, 0);
    }
    
      public void addEdgeList(GraphList g){
        g.addEdges(0, 1);
        g.addEdges(1, 2);
        g.addEdges(2, 3);
        g.addEdges(3, 0);
    }
    
    
    public void displayMatrix(GraphMatrix g){
        
        System.out.println("\nAdjacency Matrix: ");
        int[][] mat = g.getAdjMatrix();
        
        for (int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                System.out.print("" + mat[i][j] + " ");
            }
            System.out.println();
        } 
        System.out.println();
    }
    
    public void displayList(GraphList g){
        
        System.out.println("Adjacency List: ");
        LinkedList<Integer>[] list = g.getAdjList();
        
        for (LinkedList<Integer> i : list) {
            System.out.println(i);
        }
        System.out.println();
    }
    
}
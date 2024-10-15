
import java.util.*;
import java.io.*;

// simple undirected graph

//              0-------1
//              |       |
//              |       |
//              |       |
//              3-------2

class AddEdges{
    private int V;
    private int E;
    
    private int src;
    private int dest;
    
    private Scanner scanner;
    private File file;
    
    public AddEdges(int V){
        this.V = V;
        this.E = 0;
    }
    
    public void addEdgeMatrix(GraphMatrix g){
        
        file = new File("Graph.txt");
        
        try {
            
            if(file.createNewFile()){
            System.out.println("File Created");
            
            }else{
                System.out.println("File Exists");
            }
            scanner = new Scanner(file);
            
            while(scanner.hasNextInt()){
                String edge = scanner.nextLine();
                src = (int)edge.charAt(0)-'0';
                dest = (int)edge.charAt(2)-'0';
                
                g.addEdges(src, dest);
            }
        } catch(IOException e) {
        
        }
    }
    
      public void addEdgeList(GraphList g){
       
        file = new File("Graph.txt");
        
        try {
            
            if(file.createNewFile()){
            System.out.println("File Created");
            
            }else{
                System.out.println("File Exists");
            }
            scanner = new Scanner(file);
            
            while(scanner.hasNextInt()){
                String edge = scanner.nextLine();
                src = (int)edge.charAt(0)-'0';
                dest = (int)edge.charAt(2)-'0';
                
                g.addEdges(src, dest);
            }
        
        } catch(IOException e) {
        
        }
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
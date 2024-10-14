//this class is for adjacency List;

import java.util.*;

class GraphList{
    private int V;
    private int E;
    
    private LinkedList<Integer>[] adjList;
    
    public GraphList(int V){
        this.V = V;
        this.E = 0;
        adjList = new LinkedList[V];
        
        // for each node create a singly linked list
        for(int i=0; i<V; i++){
            adjList[i] = new LinkedList<>();
        }
         
         System.out.println("I am from Graph List");
    }
    
    // add edge for bi-directional graph
    public void addEdges(int src, int dest){
        adjList[src].add(dest);
        adjList[dest].add(src);
    }
    
    // normal return the List for display the graph
    public LinkedList<Integer>[] getAdjList(){
        return adjList;
    }
}
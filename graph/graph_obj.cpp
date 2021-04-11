
struct graph_typa_1 {
	int V;
	int E;
	*int[][] lines;
} 



public class Adjmatrix {
	
	private int V;
	private int E;
	private *int[][] adj = new int[V][V];
	
	public Adjmatrix (graph_typa_1 graph);
}

public Adjmatrix::Adjmatrix (graph_typa_1 graph){
		if ( sizeof(*(graph.int))%(2*sizeof(int)) != 0 ){
			printf("you have a wrong format of input")
		}
		
		## to set adj matrix to all 0
		
		V = graph.V;
		E = graph.E;
		int[][] &gra = *(graph.int);
		
		## loop to transform graph.lines to adj matrix
	}
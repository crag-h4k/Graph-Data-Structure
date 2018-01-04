using namespace std;

class graph{
public:
	static const size_t MAX = 20;
	graph();
	~graph();
	void add_edge(int source, int target, int weight = 0);
	void add_vertex(char * vertexLabel);
	void shortestPath(int start);
	void reset(int *&dist);
	void DFS(int start);


private:
	int** edges;
	char** labels;
	int numVertices;
	bool is_edge(int source, int target);
	void DFS(int start, bool marked[]);

};

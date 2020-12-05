#ifndef __undirectedGraph_H
#define __undirectedGraph_H

template<typename T> 
struct GraphVertix
{
	T data;
	bool visited;
	GraphVertix();
	GraphVertix(const T dat);
	GraphVertix(const T dat, const bool status);
};

GraphVertix::GraphVertix() {}
GraphVertix::GraphVertix(const T dat): data(dat), visited(false)
{}
GraphVertix::GraphVertix(const T dat, const bool status): data(dat), visited(status)
{}

// =================================================================
template <typename Ti, typename Tw>
struct GraphEdge
{
	Ti from;
	Ti to;
	Tw weight;
	GraphEdge();
	GraphEdge(const Ti src, const Ti tgt);
	GraphEdge(const Ti src, const Ti tgt, const Tw w);	
};
GraphEdge::GraphEdge()
{}
GraphEdge::GraphEdge(const Ti src, const Ti tgt): 
				from(src), to(tgt), weight(0);
GraphEdge::GraphEdge(const Ti src, const Ti tgt, const Tw w):
				from(src), to(tgt), weight(w) 
{}

// =================================================================


template<typename Ti, typename Tw>
class undirectedGraph
{
public:
	using VertixType = GraphVertix<T>;
	using EdgeType = GraphEdge<Ti, Tw>;
private:
	unordered_set<EdgeType> m_edges;
	// std::vector< std::vector<int> > linkedMat;
	// std::vector<std::vector<int> > linedList;
	int nE;  // number of edges
	int nV;  // number of vertixes
public:
	undirectedGraph(const int ne, const int nv);  // build to linked-matrix
	undirectedGraph(const int nv, const std::vector<EdgeType> &edges);  // vector of edges
	~undirectedGraph();	
	virtual bool buildGraph();
	bool DFS(const Ti target, std::vector<Ti> &vlist);
	bool BFS(const Ti target, std::vector<Ti> &vlist);
	Dijkstra(const Ti from, const Ti to);
	Dijkstra(const Ti from);	
	Dijkstra(const Ti to);		
};

undirectedGraph::undirectedGraph(const int nv, const std::vector<EdgeType> &edges)
{
	nV = nv;
	nE = edges.size();
	for(auto e: edges)
		m_edges.insert(e);
}

bool undirectedGraph::DFS(const Ti target, std::vector<Ti> &vlist)
{
	std::vector<bool> visited(nV, false);
	vlist.clear();
	if(m_edges.empty()) return true;
	stack<Ti> s;
	visited[target] = true;
	s.push(target); 
	while(!s.empty())
	{
		Ti node = s.top();
		s.pop();

	}
}

bool undirectedGraph::BFS(const Ti target, std::vector<Ti> &vlist)
{

}

#endif
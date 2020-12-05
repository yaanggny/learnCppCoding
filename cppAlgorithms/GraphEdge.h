#ifndef __GraphEdge_H
#define __GraphEdge_H

/*
undirected graph; Dijkstra algorithm
Reference:  
https://blog.csdn.net/junya_zhang/article/details/83617762
https://blog.csdn.net/qq_35644234/article/details/60870719
https://zhuanlan.zhihu.com/p/37473665
https://www.cnblogs.com/wxgblogs/p/5572391.html
https://www.cnblogs.com/Java-Starter/p/9452026.html
https://www.cnblogs.com/huxiaobai/p/10910689.html
*/

// =================================================================
template <typename Ti>
struct EdgeBase
{
	Ti from;
	Ti to;
	EdgeBase();
	EdgeBase(const Ti src, const Ti tgt);
};
EdgeBase::EdgeBase()
{}
EdgeBase::EdgeBase(const Ti src, const Ti tgt): from(src), to(tgt)
{}


// =================================================================
template <typename Ti, typename Tw>
struct undirectedEdge: public EdgeBase // EdgeBase<Ti>
{
	Tw weight;
	undirectedEdge();
	undirectedEdge(const Ti src, const Ti tgt);
	undirectedEdge(const Ti src, const Ti tgt, const Tw w);
};
undirectedEdge::undirectedEdge()
{}
undirectedEdge::undirectedEdge(const Ti src, const Ti tgt): 
				EdgeBase(src, tgt), weight(0)
{}				
undirectedEdge::undirectedEdge(const Ti src, const Ti tgt, const Tw w):
				EdgeBase(src, tgt), weight(w) 
{}


#endif
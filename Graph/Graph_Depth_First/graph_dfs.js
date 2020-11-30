
class GraphDFS {
  constructor(numVertex) {
    this.numVertex = numVertex
    this.adj = Array.from({ length: numVertex }, () => [])
  }

  DFSUtil(indexNode, visited) {
    visited[indexNode] = true
    console.log(`${indexNode} `)

    this.adj[indexNode].forEach(element => {
      if (!visited[element]) {
        this.DFSUtil(element, visited)
      }
    })
  }

  addEdge(nodeIndex, nodeValue) {
    this.adj[nodeIndex].push(nodeValue)
  }

  DFS(initialNode) {
    const visited = Array.from({ length: this.numVertex }, () => false)

    this.DFSUtil(initialNode, visited)
    console.log()
  }
}
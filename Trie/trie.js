
const ALPHABET_SIZE = 26

class TrieNode {
  constructor() {
    this.isEndOfWord = false
    this.children = [0]
  }
}

class Trie {
  constructor() {
    this.root = new TrieNode()
  }

  insert(key) {
    let crawl = this.root

  }
}

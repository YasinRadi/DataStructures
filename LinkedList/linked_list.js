
class Node {

  constructor(data = null, next = null) {
    this.data = data
    this.next = next
  }
}

class LinkedList {

  constructor() {
    this.length = 0
    this.head = null
    this.tail = null
  }

  checkIndexBounds(idx) {
    return idx >= 0 && idx <= this.length
  }

  add(value = null, node = null) {
    let tmp = null

    if (value !== null) {
      tmp = new Node(value)
    } else if (node !== null) {
      tmp = node
    }

    if (this.head === null) {
      this.head = tmp
    } else {
      this.tail.next = tmp
    }

    this.tail = tmp
    this.length++
  }

  displayNodes() {
    let node = this.head
    let s = ''

    while (node !== null) {
      s += `${node.data} `
      node = node.next
    }

    return s
  }

  getNodeBeforeIndex(idx) {
    if (!this.checkIndexBounds(idx)) return

    let curr = this.head
    let pre = null

    for (let i = 0; i < idx; i++) {
      pre = curr
      curr = curr.next
    }

    return pre
  }

  addAtStart(value = null, node = null) {
    let tmp = null

    if (value !== null) {
      tmp = new Node(value)
    } else if (node !== null) {
      tmp = node
    }

    if (this.head === null) {
      this.add(null, node)
      return
    }

    tmp.next = this.head
    this.head = tmp
    this.length++
  }

  addAtIndex(idx, value = null, node = null) {
    if (!this.checkIndexBounds(idx)) return

    const pre = this.getNodeBeforeIndex(idx)
    const curr = pre.next
    
    if (value !== null) {
      let n = new Node(value)
      pre.next = n
      n.next = curr
    } else if (node !== null) {
      pre.next = node
      node.next = curr
    }
    
    this.length++
  }

  pop() {
    const pre = this.getNodeBeforeIndex(this.length - 1)
    const curr = pre.next
    this.tail = pre
    pre.next = null
    //delete curr
    this.length--
  }

  popFirst() {
    const node = this.head
    this.head = this.head.next
    //delete node
    this.length--
  }

  popFromIndex(idx) {
    if (!this.checkIndexBounds(idx)) return

    const pre = this.getNodeBeforeIndex(idx)
    const curr = pre.next
    pre.next = curr.next
    //delete curr
    this.length--
  }
}

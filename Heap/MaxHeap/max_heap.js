
const parent = i => Math.floor((i - 1) / 2)
const left = i => 2 * i + 1
const right = i => 2 * i + 2

class MaxHeap {
  constructor(max_cap) {
    this.size = 0
    this.capacity = max_cap
    this.A = new Array(max_cap)
  }

  getMax() {
    return this.A[0]
  }

  fixHeapProperty(i) {
    while (i !== 0 && this.A[parent(i)] < this.A[i]) {
      [this.A[i], this.A[parent(i)]] = [this.A[parent(i)], this.A[i]]
      i = parent(i)
    }
  }

  insert(key) {
    if (this.size === this.capacity) {
      console.log(`\nOverflow: could not insert key.`)
      return
    }

    const i = this.size++
    this.A[i] = key

    this.fixHeapProperty(i)
  }

  setKey(i, newVal) {
    this.A[i] = newVal
    this.fixHeapProperty(i)
  }

  extractMax() {
    if (this.size <= 0) {
      return Number.MAX_SAFE_INTEGER
    }

    if (this.size === 1) {
      this.size--
      return this.A[0]
    }

    const root = this.A[0]
    this.A[0] = this.A[--this.size]
    this.maxHeapify(0)
  }

  deleteKey(i) {
    this.setKey(i, Number.MAX_SAFE_INTEGER)
    this.extractMax()
  }

  maxHeapify(i) {
    const l = left(i)
    const r = right(i)
    let max = i

    if (l < this.size && this.A[l] > this.A[i]) {
      max = l
    }

    if (r < this.size && this.A[r] > this.A[m]) {
      max = r
    }

    if (m !== i) {
      [this.A[i], this.A[m]] = [this.A[m], this.A[i]]
      this.maxHeapify(m)
    }
  }

  display() {
    this.A.forEach(element => console.log(`${element} `))
    console.log()
  }
}
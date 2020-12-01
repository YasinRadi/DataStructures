use std::{vec::Vec, fmt::Debug, cmp::PartialEq};

pub struct List<T> {
    /// Num of items in list
    size: usize,

    /// Capacity of the list
    capacity: usize,

    /// List of items
    items: Vec::<T>,
}

impl<T: Copy> List<T> where T: Debug + PartialEq {
    pub fn new() -> List<T> {
        List::<T> {
            size: 0,
            capacity: 1,
            items: Vec::<T>::with_capacity(1),
        }
    }

    pub fn add(&mut self, v: T) {
        // Check that new size fits capacity
        if self.size + 1 >= self.capacity {
            self.capacity *= 2;
        }

        // If capacity has changed, resize
        if self.capacity > self.items.len() {
            let mut tmp: Vec<T> = Vec::<T>::new();
            for i in 0..self.size {
                tmp.insert(i, self.items[i]);
            }

            self.items = tmp.clone();
        }

        // Assign new element and increase size
        self.items.insert(self.size, v);
        self.size += 1;
    }

    pub fn display(&self) {
        println!("{:?}", self.items);
    }

    pub fn size(&self) -> usize {
        self.size
    }

    pub fn get(&self, idx: usize) -> Option<T> {
        if idx <= self.size { 
            Some(self.items[idx]) 
        } else {
            None
        }
    }

    pub fn index_of_ref(&self, v: &T) -> i32 {
        let mut idx: i32 = -1;
        for i in 0..self.size {
            if *v == self.items[i] {
                idx = i as i32;
            }
        }

        idx
    }

    pub fn index_of_val(&self, v: T) -> i32 {
        self.index_of_ref(&v)
    }

    pub fn remove_by_idx(&mut self, idx: usize) {
        if idx <= self.size {
            for i in 0..self.size - 1 {
                self.items[i] = self.items[i + 1];
            }

            self.size -= 1;
            self.items[self.size] = self.items[self.capacity - 1];
        }
    }

    pub fn remove_by_value(&mut self, v: &T) {
        let idx = self.index_of_ref(v);
        if idx != -1 {
            self.remove_by_idx(idx as usize);
        }
    }

    pub fn is_empty(&self) -> bool {
        self.size == 0
    }

    pub fn contains(&self, v: T) -> bool {
        self.index_of_val(v) != -1
    }

    pub fn first(&self) -> Option<T> {
        if self.is_empty() {
            None
        } else {
            Some(self.items[0])
        }
    }

    pub fn last(&self) -> Option<T> {
        if self.is_empty() {
            None
        } else {
            Some(*self.items.last().unwrap())
        }
    }

    pub fn set(&mut self, idx: usize, v: &T) {
        if idx <= self.size {
            self.items[idx] = *v;
        }
    }

    pub fn capacity(&self) -> usize {
        self.capacity
    }
}

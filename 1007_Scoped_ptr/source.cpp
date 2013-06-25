template <typename T>
class scoped_ptr {
 public:
  explicit scoped_ptr(T* p = 0);
  ~scoped_ptr();

  void reset(T* p = 0);
  T* get() const;

  T& operator*() const;
  T* operator->() const;

 private:
  T* ptr;
};

template<typename T>
scoped_ptr<T>::scoped_ptr(T* p) : ptr(p) {}

template<typename T>
scoped_ptr<T>::~scoped_ptr() {
  delete ptr;
}

template<typename T>
void scoped_ptr<T>::reset(T* p) {
  if (ptr != p) {
    delete ptr;
    ptr = p;
  }
}

template<typename T>
T* scoped_ptr<T>::get() const {
  return ptr;
}

template<typename T>
T& scoped_ptr<T>::operator*() const {
  return *ptr;
}

template<typename T>
T* scoped_ptr<T>::operator->() const {
  return ptr;
}


//
// Created by Maria.Baburina on 5/24/2017.
//

struct T1 {
  T1() {}
  T1(int) {}
};

struct T2 : public T1 {
  using TBase = T1;
  using TBase::TBase; // error is here
  T2(){}
};

int main() {
  T2 t(1);
}
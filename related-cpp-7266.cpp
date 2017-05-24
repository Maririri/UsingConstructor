//
// Created by Maria.Baburina on 5/24/2017.
//

template<typename ...>
struct XX
{
  struct detail
  {
    detail(int)
    {

    }
  };
};

template<typename ...T>
struct ZZ
{
  using detail = typename XX<T...>::detail;

  struct case_a{};
  struct case_b{};

  ZZ(case_a)
      : ptr_x(new detail(0)) // false positive
  { }

  ZZ(case_b)
      : ptr_x(new typename XX<T...>::detail(0)) // okay
  { }

  typename XX<T...>::detail *ptr_x;
};


template<typename>
struct X
{
  struct detail
  {
    detail(int)
    {

    }
  };
};
template<typename T>
struct Z
{
  using detail = typename XX<T>::detail;

  struct case_a{};
  struct case_b{};

  Z(case_a)
      : ptr_x(new detail(0)) // false positive
  { }

  Z(case_b)
      : ptr_x(new typename X<T>::detail(0)) // okay
  { }

  typename X<T>::detail *ptr_x;
};
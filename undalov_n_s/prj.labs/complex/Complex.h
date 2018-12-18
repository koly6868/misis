#ifndef COMPLEX_2018
#define COMPLEX_2018

#include <sstream>

struct Complex
{
public:
  explicit Complex() = default;
  explicit Complex(const double real);
  Complex(const double real, const double imaginary);
  Complex(const Complex& val);
  ~Complex() = default;

  Complex& operator=(const Complex& val);
  bool operator==(const Complex& rhs) const;
  bool operator!=(const Complex& rhs) const;

  Complex& operator+=(const Complex& rhs);
  Complex& operator-=(const Complex& rhs);
  Complex& operator/=(const Complex& rhs);
  Complex& operator*=(const Complex& rhs);

  Complex& operator+=(const double rhs);
  Complex& operator-=(const double rhs);
  Complex& operator*=(const double rhs);
  Complex& operator/=(const double rhs);

  Complex operator+(const Complex& rhs);
  Complex operator-(const Complex& rhs);
  Complex operator*(const Complex& rhs);
  Complex operator/(const Complex& rhs);

  Complex operator+(const double rhs);
  Complex operator-(const double rhs);
  Complex operator*(const double rhs);
  Complex operator/(const double rhs);

  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream& readFrom(std::istream& istrm);

private:
  double re_{ 0.0 };
  double im_{ 0.0 };

  static const char leftBrace_{ '{' };
  static const char separator_{ ',' };
  static const char rightBrace_{ '}' };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
  return rhs.readFrom(istrm);
}
#endif // COMPLEX_2018

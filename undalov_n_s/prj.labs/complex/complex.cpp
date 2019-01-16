#include "complex.h"
#include <stdexcept>
#include <math.h>

Complex& Complex::operator=(const Complex& val)
{
  if (this != &val)
  {
    re_ = val.re_;
    im_ = val.im_;
  }
  return *this;
}



bool Complex::operator==(const Complex& rhs) const
{
  return abs(re_ - rhs.re_) < std::numeric_limits<double>::epsilon()
    && abs(im_ - rhs.im_) < std::numeric_limits<double>::epsilon();
}



bool Complex::operator!=(const Complex& rhs) const
{
  return !operator==(rhs);
}



Complex& Complex::operator+=(const double rhs)
{
  return operator+=(Complex(rhs));
}



Complex::Complex(const double real)
  : Complex(real, 0.0)
{
}



Complex::Complex(const double real, const double imaginary)
  : re_(real)
  , im_(imaginary)
{
}



Complex::Complex(const Complex & val)
  : re_(val.re_)
  , im_(val.im_)
{
}



Complex& Complex::operator+=(const Complex& rhs)
{
  re_ += rhs.re_;
  im_ += rhs.im_;
  return *this;
}



Complex& Complex::operator-=(const double rhs)
{
  re_ -= rhs;
  return *this;
}



Complex& Complex::operator-=(const Complex& rhs)
{
  re_ -= rhs.re_;
  im_ -= rhs.im_;
  return *this;
}



Complex& Complex::operator*=(const double rhs)
{
  re_ *= rhs;
  im_ *= rhs;
  return *this;
}



Complex& Complex::operator/=(const double rhs)
{
  if (abs(rhs - 0) < std::numeric_limits<double>::epsilon()) throw std::invalid_argument("Div on 0");
  re_ /= rhs;
  im_ /= rhs;
  return *this;
}



Complex Complex::operator+(const Complex & rhs)
{
  return Complex(re_ + rhs.re_, im_ + rhs.im_);
}



Complex Complex::operator-(const Complex & rhs)
{
  return Complex(re_ - rhs.re_, im_ - rhs.im_);
}



Complex Complex::operator*(const Complex & rhs)
{
  return Complex(re_ * rhs.re_ - im_ * rhs.im_, re_ * rhs.im_ + im_ * rhs.re_);
}



Complex Complex::operator/(const Complex & rhs)
{
  if ((abs(rhs.im_ - 0) < std::numeric_limits<double>::epsilon()) 
    && (abs(rhs.re_ - 0) < std::numeric_limits<double>::epsilon())) throw std::invalid_argument("Div on 0");
  return Complex((re_*rhs.re_ + im_ * rhs.im_) / (rhs.re_*rhs.re_ + rhs.im_*rhs.im_),
    (rhs.re_ *im_ - re_ * rhs.im_) / (rhs.re_*rhs.re_ + rhs.im_*rhs.im_));
}



Complex Complex::operator+(const double rhs)
{

  return Complex(re_ + rhs, im_);
}



Complex Complex::operator-(const double rhs)
{
  return Complex(re_ - rhs, im_);
}



Complex Complex::operator*(const double rhs)
{
  return Complex(re_ * rhs, im_ * rhs);
}



Complex Complex::operator/(const double rhs)
{
  if (abs(rhs - 0) < std::numeric_limits<double>::epsilon()) throw std::invalid_argument("Div on 0");
  return Complex(re_ / rhs, im_ / rhs);
}



Complex& Complex::operator*=(const Complex& rhs)
{
  double re = re_;
  re_ = re_ * rhs.re_ - im_ * rhs.im_;
  im_ = re * rhs.im_ + im_ * rhs.re_;
  return *this;
}



Complex& Complex::operator/=(const Complex & rhs)
{
  if ((abs(rhs.im_ - 0) < std::numeric_limits<double>::epsilon())
    && (abs(rhs.re_ - 0) < std::numeric_limits<double>::epsilon())) throw std::invalid_argument("Div on 0");
  double oldRe = re_;
  re_ = (re_*rhs.re_ + im_ * rhs.im_) / (rhs.re_*rhs.re_ + rhs.im_*rhs.im_);
  im_ = (rhs.re_ *im_ - oldRe * rhs.im_) / (rhs.re_*rhs.re_ + rhs.im_*rhs.im_);
  return *this;
}



std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
  ostrm << leftBrace_ << re_ << separator_ << im_ << rightBrace_;
  return ostrm;
}



std::istream& Complex::readFrom(std::istream& istrm)
{
  char leftBrace(0);
  double real(0.0);
  char comma(0);
  double imaganary(0.0);
  char rightBrace(0);
  istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
  if (istrm.good())
  {
    if ((Complex::leftBrace_ == leftBrace) && (Complex::separator_ == comma) &&
      (Complex::rightBrace_ == rightBrace))
    {
      re_ = real;
      im_ = imaganary;
    }
    else
    {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

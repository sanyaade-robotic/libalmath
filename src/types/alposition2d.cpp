/*
 * Copyright (c) 2012 Aldebaran Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */

#include <almath/types/alposition2d.h>
#include <cmath>
#include <stdexcept>

namespace AL {
  namespace Math {

    Position2D::Position2D() : x(0.0f), y(0.0f) {}

    Position2D::Position2D(float pInit) : x(pInit), y(pInit) {}

    Position2D::Position2D(float pX, float pY) : x(pX), y(pY) {}

    Position2D::Position2D (const std::vector<float>& pFloats)
    {
      if (pFloats.size() == 2)
      {
        x = pFloats[0];
        y = pFloats[1];
      }
      else
      {
        x = 0.0f;
        y = 0.0f;
      }
    }

    Position2D Position2D::operator+ (const Position2D& pPos2) const
    {
      Position2D res;
      res.x = x + pPos2.x;
      res.y = y + pPos2.y;
      return res;
    }

    Position2D Position2D::operator- (const Position2D& pPos2) const
    {
      Position2D res;
      res.x = x - pPos2.x;
      res.y = y - pPos2.y;
      return res;
    }

    Position2D Position2D::operator+ () const
    {
      Position2D res;
      res.x = x;
      res.y = y;
      return res;
    }

    Position2D Position2D::operator- () const
    {
      Position2D res;
      res.x = -x;
      res.y = -y;
      return res;
    }

    Position2D& Position2D::operator+= (const Position2D& pPos2)
    {
      x += pPos2.x;
      y += pPos2.y;
      return *this;
    }

    Position2D& Position2D::operator-= (const Position2D& pPos2)
    {
      x -= pPos2.x;
      y -= pPos2.y;
      return *this;
    }


    bool Position2D::operator!=(const Position2D& pPos2) const
    {
      return !(*this==pPos2);
    }


    bool Position2D::isNear(
      const Position2D& pPos2,
      const float&      pEpsilon) const
    {
      if (
        (fabsf(x - pPos2.x) > pEpsilon) ||
        (fabsf(y - pPos2.y) > pEpsilon))
      {
        return false;
      }
      return true;
    }


    Position2D Position2D::operator* (float pVal) const
    {
      Position2D res;
      res.x = x * pVal;
      res.y = y * pVal;
      return res;
    }

    Position2D operator* (
      const float       pVal,
      const Position2D& pPos1)
    {
      return pPos1*pVal;
    }

    Position2D Position2D::operator/ (float pVal) const
    {
      if (pVal == 0.0f)
      {
        throw std::runtime_error(
          "ALPosition2D: operator/ Division by zeros.");
      }
      return *this * (1.0f/pVal);
    }

    Position2D& Position2D::operator*= (float pVal)
    {
      x *=pVal;
      y *=pVal;
      return *this;
    }

    Position2D& Position2D::operator/= (float pVal)
    {
      if (pVal == 0.0f)
      {
        throw std::runtime_error(
          "ALPosition2D: operator/= Division by zero.");
      }
      *this *= (1.0f/pVal);
      return *this;
    }


    float Position2D::distanceSquared(const Position2D& pPos2) const
    {
      return Math::distanceSquared(*this, pPos2);
    }

    float Position2D::distance(const Position2D& pPos2) const
    {
      return Math::distance(*this, pPos2);
    }

    float Position2D::norm() const
    {
      return Math::norm(*this);
    }

    Position2D Position2D::normalize() const
    {
      return Math::normalize(*this);
    }

    float Position2D::crossProduct(const Position2D& pPos2) const
    {
      return Math::crossProduct(*this, pPos2);
    }

    bool Position2D::operator==(const Position2D& pPos2) const
    {
      if ((x == pPos2.x) &&
          (y == pPos2.y))
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    std::vector<float> Position2D::toVector() const
    {
      std::vector<float> returnVector;
      returnVector.resize(2);
      returnVector[0] = x;
      returnVector[1] = y;

      return returnVector;
    }


    float distanceSquared(
      const Position2D& pPos1,
      const Position2D& pPos2)
    {
      return (pPos1.x-pPos2.x)*(pPos1.x-pPos2.x)+(pPos1.y-pPos2.y)*(pPos1.y-pPos2.y);
    }

    float distance(
      const Position2D& pPos1,
      const Position2D& pPos2)
    {
      return sqrtf(distanceSquared(pPos1, pPos2));
    }

    float norm(const Position2D& p)
    {
      return sqrtf( (p.x*p.x) + (p.y*p.y) );
    }

    Position2D normalize(const Position2D& p)
    {
      Position2D ret;
      ret = p;

      float tmpNorm = norm(p);
      if (tmpNorm == 0.0f)
      {
        throw std::runtime_error(
          "ALPosition2D: normalize Division by zeros.");
      }

      ret /= tmpNorm;
      return ret;
    }

    float crossProduct(
      const Position2D& pPos1,
      const Position2D& pPos2)
    {
      return (pPos1.x*pPos2.y - pPos1.y*pPos2.x);
    }


    void crossProduct(
      const Position2D& pPos1,
      const Position2D& pPos2,
      float&            result)
    {
      result = (pPos1.x*pPos2.y - pPos1.y*pPos2.x);
    }

  } // end namespace math
} // end namespace al


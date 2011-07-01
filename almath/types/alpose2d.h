/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
*/

#pragma once

#ifndef _LIB_ALMATH_ALMATH_ALPOSE2D_H_
#define _LIB_ALMATH_ALMATH_ALPOSE2D_H_

#include <vector>

namespace AL {
  namespace Math {

    /// <summary>
    /// A pose in a 2-dimentional space
    ///
    /// On a plane a position is totally defined
    /// by the postions x,y and the rotation theta.
    /// </summary>
    /// \ingroup Types


    struct Pose2D {
      float x;
      float y;
      float theta;

      /// <summary>
      /// Create a Pose2D initialized with 0.0f.
      /// </summary>
      Pose2D():x(0.0f), y(0.0f), theta(0.0f) {}

      /// <summary>
      /// Create a Pose2D initialize with the same float.
      /// <param name="pInit"> the float value for each member </param>
      /// </summary>
      explicit Pose2D(float pInit):x(pInit), y(pInit), theta(pInit) {}

      /// <summary>
      /// Create a Pose2D initialize with explicit value.
      /// </summary>
      /// <param name="pX"> the float value for x </param>
      /// <param name="pY"> the float value for y </param>
      /// <param name="pTheta"> the float value for theta </param>
      explicit Pose2D(float pX,float pY,float pTheta):x(pX), y(pY), theta(pTheta) {}

      /// <summary>
      /// Create a Pose2D with an std::vector.
      /// </summary>
      /// <param name="pFloats">
      /// An std::vector<float> of size 3 for respectively :
      /// x, y and theta
      /// </param>
      Pose2D (const std::vector<float>& pFloats)
      {
        if (pFloats.size() == 3)
        {
          x = pFloats[0];
          y = pFloats[1];
          theta = pFloats[2];
        }
        else
        {
          x = 0.0f;
          y = 0.0f;
          theta = 0.0f;
        }
      }

      Pose2D operator+ (const Pose2D& pPos2) const;
      Pose2D operator- (const Pose2D& pPos2) const;

      Pose2D operator+ () const;
      Pose2D operator- () const;

      Pose2D& operator+= (const Pose2D& pPos2);
      Pose2D& operator-= (const Pose2D& pPos2);

      Pose2D& operator*= (const Pose2D& pPos2);
      Pose2D operator* (const Pose2D& pPos2) const;

      bool operator==(const Pose2D& pPos2) const;
      bool operator!=(const Pose2D& pPos2) const;

      /// <summary>
      /// Compute the squared distance between the actual
      /// Pose2D and the one give in argument.
      /// This avoids doing the sqrt needed for a true distance.
      ///
      /// \f$(pPos1.x-pPos2.x)²+(pPos1.y-pPos2.y)²\f$
      /// </summary>
      /// <param name="pPos2"> the second Pose2D </param>
      /// <returns>
      /// the float squared distance between the two Pose2D
      /// </returns>
      float distanceSquared(const Pose2D& pPos2) const;

      /// <summary>
      /// Compute the distance between the actual
      /// Pose2D and the one give in argument
      ///
      /// \f$\sqrt{(pPos1.x-pPos2.x)²+(pPos1.y-pPos2.y)²}\f$
      /// </summary>
      /// <param name="pPos2"> the second Pose2D </param>
      /// <returns>
      /// the float distance between the two Pose2D
      /// </returns>
      float distance(const Pose2D& pPos2) const;

      /// <summary>
      /// Return the inverse of the Pose2D
      /// </summary>
      Pose2D inverse() const;

      /// <summary>
      /// Check if the actual Pose2D is Near the one
      /// given in argument.
      ///
      /// </summary>
      /// <param name="pPos2"> the second Pose2D </param>
      /// <param name="pEpsilon"> an optionnal epsilon distance - default: 0.0001 </param>
      /// <returns>
      /// true if the distance between the two Pose2D is less than pEpsilon
      /// </returns>
      bool isNear(const Pose2D& pPos2,
                  const float&  pEpsilon=0.0001f) const;

      /// <summary>
      /// Return the Pose2D as a vector of float [x, y, theta]
      /// </summary>
      std::vector<float> toVector() const;

    }; // end struct


    /// <summary>
    /// Compute the squared distance between two Pose2D
    ///
    /// \f$(pPos1.x-pPos2.x)²+(pPos1.y-pPos2.y)²\f$
    /// </summary>
    /// <param name="pPos1"> the first Pose2D </param>
    /// <param name="pPos2"> the second Pose2D </param>
    /// <returns>
    /// the float squared distance between the two Pose2D
    /// </returns>
    /// \ingroup Types
    float distanceSquared(const Pose2D& pPos1,
                          const Pose2D& pPos2);

    /// <summary>
    /// Compute the distance between two Pose2D
    ///
    /// \f$\sqrt{(pPos1.x-pPos2.x)²+(pPos1.y-pPos2.y)²}\f$
    /// </summary>
    /// <param name="pPos1"> the first Pose2D </param>
    /// <param name="pPos2"> the second Pose2D </param>
    /// <returns>
    /// the float distance between the two Pose2D
    /// </returns>
    /// \ingroup Types
    float distance(const Pose2D& pPos1,
                   const Pose2D& pPos2);

    /// <summary>
    /// Compute the inverse of a Pose2D
    /// </summary>
    /// <param name="pPos"> the initial Pose2D </param>
    /// <returns> the inverse Pose2D </returns>
    /// \ingroup Types
    Pose2D Pose2DInverse(const Pose2D& pPos);

    /// <summary>
    /// Compute the inverse of a Pose2D
    /// </summary>
    /// <param name="pPos"> the initial Pose2D </param>
    /// <param name="pRes"> the inverse Pose2D </param>
    /// \ingroup Types
    void Pose2DInverse( const Pose2D& pPos,
                              Pose2D& pRes);

  } // end namespace math
} // end namespace AL
#endif  // _LIB_ALMATH_ALMATH_ALPOSE2D_H_

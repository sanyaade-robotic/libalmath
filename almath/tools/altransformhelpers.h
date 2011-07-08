/*
** Author(s):
**  - Chris Kilner
**  - Cyrille Collette
**  - David Gouaillier
**
** Copyright (C) 2011 Aldebaran Robotics
*/

#pragma once

#ifndef _LIB_ALMATH_ALMATH_ALTRANSFORMHELPERS_H_
#define _LIB_ALMATH_ALMATH_ALTRANSFORMHELPERS_H_

#include <almath/types/alposition3d.h>
#include <almath/types/alposition6d.h>
#include <almath/types/alrotation.h>
#include <almath/types/alrotation3d.h>
#include <almath/types/alvelocity6d.h>
#include <almath/types/altransform.h>
#include <almath/types/alaxismask.h>
#include <almath/types/alpose2d.h>

namespace AL {
  namespace Math {

  /// <summary>
  /// Create a Transform from a 3D points and a Rotation.
  ///
  /// \f$ T = \left[\begin{array}{cccc} pRot.r1c1 & pRot.r1c2 & pRot.r1c3 & pX \\ pRot.r2c1 & pRot.r2c2 & pRot.r2c3 & pY \\ pRot.r3c1 & pRot.r3c2 & pRot.r3c3 & pZ \\ 0.0 & 0.0 & 0.0 & 1.0 \end{array}\right] \f$
  ///
  /// </summary>
  /// <param name="pX"> the translation along x axis </param>
  /// <param name="pY"> the translation along y axis </param>
  /// <param name="pZ"> the translation along z axis </param>
  /// <param name="pRot"> the given Rotation </param>
  /// <returns>
  /// the Transform result.
  /// </returns>
  /// \ingroup Tools
  Transform transformFromPosition3DAndRotation(
    const float&              pX,
    const float&              pY,
    const float&              pZ,
    const Rotation& pRot);

  /// <summary>
  /// Create a Transform from a Position3D and a Rotation.
  ///
  /// \f$ T = \left[\begin{array}{cccc} pRot.r1c1 & pRot.r1c2 & pRot.r1c3 & pPos.x \\ pRot.r2c1 & pRot.r2c2 & pRot.r2c3 & pPos.y \\ pRot.r3c1 & pRot.r3c2 & pRot.r3c3 & pPos.z \\ 0.0 & 0.0 & 0.0 & 1.0 \end{array}\right] \f$
  ///
  /// </summary>
  /// <param name="pPos"> the given Position3D </param>
  /// <param name="pRot"> the given Rotation </param>
  /// <returns>
  /// the Transform result.
  /// </returns>
  /// \ingroup Tools
  Transform transformFromPosition3DAndRotation(
    const Position3D& pPos,
    const Rotation&   pRot);

//  /**
//    * Function Transform Logarithme : cette fonction calcule le
//    * logarithme associe a une matrice de type Deplacement - matrice homogene 4x4 (SE3)
//    * La sortie est un torseur cinematique de se3.
//    * Le resultat n'est garanti que pour des angles dans [-pi+0.001,pi-0.001].
//    * cette fonction calcule la differentielle du logarithme associe
//    * a une matrice de type Deplacement - matrice homogene 4x4 (SE3).
//    * @param Transform Homogenous Matrix (4*4)
//    * @return Velocity6D (torseur cinematique)
//    **/
  /// <summary>
  /// Compute the logarithme of a transform.
  ///
  /// Angle must be between \f$\left[-\pi+0.001, \pi-0.001\right].\f$
  ///
  /// </summary>
  /// <param name="pT"> the given Transform </param>
  /// <returns>
  /// the Velocity6D logarithme: kinematic screw in se3
  /// </returns>
  /// \ingroup Tools
    Velocity6D transformLogarithme(const Transform& pT);

    void transformLogarithme(
      const Transform& pT,
      Velocity6D&      pVel);

    /**
    * Function Velocity Exponential : compute homogenous matrix
    * diplacement from a dt * 6D velocity vector
    * @param Velocity6D  : dt*velocity
    * @param Transform
    **/
    void velocityExponential(
      const Velocity6D& pVel,
      Transform&        pT);

    Transform velocityExponential(const Velocity6D& pVel);

    void changeRepereVelocity6D(
      const Transform&  pT,
      const Velocity6D& pVelIn,
      Velocity6D&       pVelOut);

    void changeReperePosition6D(
      const Transform&  pT,
      const Position6D& pPosIn,
      Position6D&       pPosOut);

    void changeReperePosition3D(
      const Transform& pT,
      Position3D&      pPosOut);

    void changeRepereTransposePosition3D(
      const Transform& pT,
      Position3D&      pPosOut);

    void changeReperePosition3D(
      const Transform&  pT,
      const Position3D& pPosIn,
      Position3D&       pPosOut);

    void changeRepereTransposePosition3D(
      const Transform&  pT,
      const Position3D& pPosIn,
      Position3D&       pPosOut);

    void changeRepereTransform(
      const Transform& pT,
      const Transform& pTIn,
      Transform&       pTOut);

    void changeRepereTransposeTransform(
      const Transform& pT,
      const Transform& pTIn,
      Transform&       pTOut);

    void changeRepereTransposeVelocity6D(
      const Transform&  pT,
      const Velocity6D& pVelIn,
      Velocity6D&       pVelOut);

    void changeRepereTransposePosition6D(
      const Transform&  pT,
      const Position6D& pPosIn,
      Position6D&       pPosOut);

    void transformMean(
      const Transform& pTIn1,
      const Transform& pTIn2,
      const float&               pDist,
      Transform&       pTOut);

    Transform transformMean(
      const Transform& pTIn1,
      const Transform& pTIn2);

    Transform transformMean(
      const Transform& pTIn1,
      const Transform& pTIn2,
      const float&               pDist);


    /**
    * Creates a 4*4 transform matrix from XYZ coordinates
    * indicating the translational offsets.
    */

    void transformFromPosition3D(
      const Position3D& pPosition,
      Transform&        pTransform);


    Transform transformFromPosition3D(const Position3D& pPosition);

    void rotationToTransform(
      const Rotation& pRotation,
      Transform&      pTransform);

    Transform rotationToTransform(const Rotation& pRotation);

    void rotationFromTransform(
      const Transform& pTransform,
      Rotation&        pRotation);

    Rotation rotationFromTransform(const Transform& pTransform);

    Rotation3D rotation3DFromRotation(const Rotation& pRotation1);

    /**
    * Extracts the position coordinates from a Matrix
    * into a Position3D struct
    * @param pTransform The transform form which you want to extract the coordinates.
    */
    void transformToPosition3D(
      const Transform& pTransform,
      Position3D&      pPosition);

    Position3D transformToPosition3D(const Transform& pTransform);

    /**
    * Return Position6D corresponding to 4*4 Homogenous Matrix pT
    * @param pT 4*4 Homogenous Matrix pT
    */
    void position6DFromTransform(
        const Transform& pT,
        Position6D&      pPos);

    Position6D position6DFromTransform(const Transform& pT);

    /**
    * Creates a 4*4 transform matrix from Pose2D
    */
    void transformFromPose2D(
        const Pose2D& pPose,
        Transform&    pT);

    Transform transformFromPose2D(const Pose2D& pPose);

    /**
    * Return Pose2D corresponding to the 4*4 Homogenous Matrix pT
    * @param pT 4*4 Homogenous Matrix pT
    */
    void pose2DFromTransform(
        const Transform& pT,
        Pose2D&          pPos);

    Pose2D pose2DFromTransform(const Transform& pT);

    /**
    * Creates a 4*4 Homogenous Matrix
    * from a Roll, Pitch and yaw Angle in radian
    * @param pRotation Rotation structure
    */
    Transform transformFromRotation3D(const Rotation3D& pRotation);

    /**
    * Creates a 4*4 transform matrix from a rotation(RPY) and a position
    * indicating the translational offsets.
    */
    Transform transformFromPosition6D(const Position6D& pPosition6D);

    /**
    * Return a 6 differential motion require to move
    * from a 4*4 Homogenous transform matrix Current to
    * a 4*4 Homogenous transform matrix target
    * @param  pCurrent 4*4 Homogenous transform matrix
    * @param  pTarget  4*4 Homogenous transform matrix
    * @param  result   6*1 Position6D
    */
    void transformDiffToPosition(
      const Transform& pCurrent,
      const Transform& pTarget,
      Position6D&      result);

    /**
    * Return a 6 differential motion require to move
    * from a 4*4 Homogenous transform matrix Current to
    * a 4*4 Homogenous transform matrix target
    * @param  pCurrent 4*4 Homogenous transform matrix
    * @param  pTarget  4*4 Homogenous transform matrix
    * @return  pDelta  6*1 Position6D
    */
    Position6D transformDiffToPosition(
      const Transform& pCurrent,
      const Transform& pTarget);

    void position3DFromTransformInPlace(
      const Transform& pH,
      Position3D&      pOut);

    Position3D position3DFromTransform(const Transform& pH);

    Transform rotationPosition3DToTransform(
      const Rotation&   pRot,
      const Position3D& pPos);

    /**
    * Return Rotation3D (Roll, Pitch, Yaw) corresponding to the rotational
    * part of the 4*4 Homogenous Matrix pT
    * @param pT 4*4 Homogenous Matrix pT
    */
    Rotation3D rotation3DFromTransform(const Transform& pT);

    Position3D operator*(
      const Transform&  pT,
      const Position3D& pPos);

    Transform& operator+=(
      Transform&        pT,
      const Position3D& pPos);


    /**
    * Function AxisRotationProjection :
    * finding the closest rotation Rw of R around an axis (Position3D)
    * @param Transform : useful only for Rotation part
    * @param Position3D : axis of rotation
    * @return Transform
    **/
    void axisRotationProjection(
      const Position3D& pAxis,
      Transform&        pH);


    Transform axisRotationProjection(
      const Transform&  pH,
      const Position3D& pAxis);

    std::vector<Transform> filterTransform(
      const std::vector<Transform>& pHi,
      const AXIS_MASK               pAxisMask);

    Transform axisMaskToTransformOn(
      const Transform& pHi,
      const AXIS_MASK  pAxisMask);

    void computeMixTransformWithAxisMask(
      const Transform& pDesired,
      const Transform& pReference,
      const AXIS_MASK& pAxisMask,
      Transform&       pResult);

    // Main
    void rotVecToTransform(
      const int         pAxis,
      const float       pTheta,
      const Position3D& pPos,
      Transform&        pT);

    Transform rotVecToTransform(
      const int         pAxis,
      const float       pTheta,
      const Position3D& pPos);

    /**
    @param rotation axis, angle in degree, translation 3D Vector
    @return Transform
    **/
    void rotVecToTransform(
      const Position3D& pP,
      Transform&        pT);

    Transform rotVecToTransform(const Position3D& pPosition);

    Transform rotVecToTransform(
      const int&   pAxis,
      const float& pRot);


    /**
    * Function AxisRotationProjection :
    * finding the closest rotation Rw of R around an axis (Position3D)
    * @param Transform : useful only for Rotation part
    * @param Position3D : axis of rotation
    * @return Transform
    **/
    Rotation axisRotationProjection(
      const Rotation&   pRot,
      const Position3D& pAxis);

    /**
    * Function axisRotationProjectionInPlace :
    * finding the closest rotation Rw of R around an axis (Position3D)
    * @param Position3D : axis of rotation
    * @param pH: a transform
    **/
    void axisRotationProjectionInPlace(
      const Position3D& pAxis,
      Transform&        pT);

    /**
    * Function axisRotationProjectionInPlace :
    * finding the closest rotation Rw of R around an axis (Position3D)
    * @param pRot : a rotation
    * @param Position3D : axis of rotation
    **/
    void axisRotationProjectionInPlace(
      Rotation&         pRot,
      const Position3D& pPos);

  } // namespace Math
} // namespace AL
#endif  // _LIB_ALMATH_ALMATH_ALTRANSFORMHELPERS_H_

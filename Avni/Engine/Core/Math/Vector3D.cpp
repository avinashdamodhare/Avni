////////////////////////////////////////////////////////////////////////////////////
// Vector Math
////////////////////////////////////////////////////////////////////////////////////

#include <AvniInterfaces.h>
#include <math.h>
namespace Avni
{

    float VectorDot(Vector4D & _vec1, Vector4D & _vec2)
    {
        return _vec1.X*_vec2.X + _vec1.Y*_vec2.Y + _vec1.Z*_vec2.Z + _vec1.W*_vec2.W;
    }
    float VectorDot(Vector3D & _vec1, Vector3D & _vec2)
    {
        return _vec1.X*_vec2.X + _vec1.Y*_vec2.Y + _vec1.Z*_vec2.Z;
    }
    float VectorDot(Vector2D & _vec1, Vector2D & _vec2)
    {
        return _vec1.X*_vec2.X + _vec1.Y*_vec2.Y;
    }

    Vector3D VectorCross(Vector3D & _vec1, Vector3D & _vec2)
    {
        float X = (_vec1.Y*_vec2.Z - _vec1.Z*_vec2.Y);
        float Y = (_vec1.Z*_vec2.X - _vec1.X*_vec2.Z);
        float Z = (_vec1.X*_vec2.Y - _vec1.Y*_vec2.X);
        return Vector3D(X,Y,Z);
    }

    Vector3D VectorAdd(Vector3D & _vec1, Vector3D & _vec2)
    {
        return Vector3D(_vec1.X+_vec2.X, _vec1.Y + _vec2.Y, _vec1.Z + _vec2.Z);
    }
    Vector4D VectorAdd(Vector4D & _vec1, Vector4D & _vec2)
    {
        return Vector4D(_vec1.X + _vec2.X, _vec1.Y + _vec2.Y, _vec1.Z + _vec2.Z, _vec1.W + _vec2.W);
    }
    Vector2D VectorAdd(Vector2D & _vec1, Vector2D & _vec2)
    {
        return Vector2D(_vec1.X + _vec2.X, _vec1.Y + _vec2.Y);
    }

    Vector3D VectorSub(Vector3D & _vec1, Vector3D & _vec2)
    {
        return Vector3D(_vec1.X - _vec2.X, _vec1.Y - _vec2.Y, _vec1.Z - _vec2.Z);
    }
    Vector4D VectorSub(Vector4D & _vec1, Vector4D & _vec2)
    {
        return Vector4D(_vec1.X - _vec2.X, _vec1.Y - _vec2.Y, _vec1.Z - _vec2.Z, _vec1.W - _vec2.W);
    }
    Vector2D VectorSub(Vector2D & _vec1, Vector2D & _vec2)
    {
        return Vector2D(_vec1.X - _vec2.X, _vec1.Y - _vec2.Y);
    }

    Vector3D VectorScale(Vector3D & _vec1, float _scale)
    {
        return Vector3D(_vec1.X * _scale, _vec1.Y * _scale, _vec1.Z * _scale);
    }
    Vector4D VectorScale(Vector4D & _vec1, float _scale)
    {
        return Vector4D(_vec1.X * _scale, _vec1.Y * _scale, _vec1.Z * _scale, _vec1.W * _scale);
    }
    Vector2D VectorScale(Vector2D & _vec1, float _scale)
    {
        return Vector2D(_vec1.X * _scale, _vec1.Y * _scale);
    }

    Vector3D VectorDiv(Vector3D & _vec1, float _div)
    {
        return Vector3D(_vec1.X / _div, _vec1.Y / _div, _vec1.Z / _div);
    }
    Vector4D VectorDiv(Vector4D & _vec1, float _div)
    {
        return Vector4D(_vec1.X / _div, _vec1.Y / _div, _vec1.Z / _div, _vec1.W / _div);
    }
    Vector2D VectorDiv(Vector2D & _vec1, float _div)
    {
        return Vector2D(_vec1.X / _div, _vec1.Y / _div);
    }

    Vector3D Normalize(Vector3D & _vec)
    {
        float mag = sqrtf(_vec.X * _vec.X + _vec.Y * _vec.Y + _vec.Z * _vec.Z);
        return VectorDiv(_vec, mag);
    }
    Vector2D Normalize(Vector2D & _vec)
    {
        float mag = sqrtf(_vec.X * _vec.X + _vec.Y * _vec.Y);
        return VectorDiv(_vec, mag);
    }
}
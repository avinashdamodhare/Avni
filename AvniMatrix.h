//////////////////////////////////////////////////////////////////////////////////////
// Matrix
//////////////////////////////////////////////////////////////////////////////////////
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "AvniVector.h"
#include <string.h>
namespace Avni
{
    typedef union
    {
        struct 
        {
            float m[3][3];
        };
        struct 
        {
            float m11, m12, m13;
            float m21, m22, m23;
            float m31, m32, m33;
        };
        /*struct
        {
            Vector3D row1;
            Vector3D row2;
            Vector3D row3;
        };*/
    }MatrixU3x3;
    typedef union
    {
        struct
        {
            float m[4][4];
        };
        struct
        {
            float m11, m12, m13, m14;
            float m21, m22, m23, m24;
            float m31, m32, m33, m34;
            float m41, m42, m43, m44;
        };
        /*struct
        {
            Vector4D row1;
            Vector4D row2;
            Vector4D row3;
            Vector4D row4;
        };*/
    }MatrixU4x4;

    class Matrix3x3
    {
        public :    
            Matrix3x3()
            {
                for (int i = 0; i < 9; ++i)
                {
                    mat.m[i / 3][i % 3] = 0.0f;
                }
            }

            Matrix3x3(  float _m11, float _m12, float _m13,
                        float _m21, float _m22, float _m23,
                        float _m31, float _m32, float _m33)
            {
                mat.m11 = _m11; mat.m12 = _m12; mat.m13 = _m13;
                mat.m21 = _m21; mat.m22 = _m22; mat.m23 = _m23;
                mat.m31 = _m31; mat.m32 = _m32; mat.m33 = _m32;
            }

            ~Matrix3x3() {}

            MatrixU3x3 mat;
    };

    class Matrix4x4
    {
        public:
            Matrix4x4()
            {
                for (int i = 0; i < 16; ++i)
                {
                    mat.m[i / 4][i % 4] = 0.0f;
                }
            }
            Matrix4x4(  float _m11, float _m12, float _m13, float _m14,
                        float _m21, float _m22, float _m23, float _m24,
                        float _m31, float _m32, float _m33, float _m34,
                        float _m41, float _m42, float _m43, float _m44)
            {
                mat.m11 = _m11; mat.m12 = _m12; mat.m13 = _m13; mat.m14 = _m14;
                mat.m21 = _m21; mat.m22 = _m22; mat.m23 = _m23; mat.m24 = _m24;
                mat.m31 = _m31; mat.m32 = _m32; mat.m33 = _m33; mat.m34 = _m34;
                mat.m41 = _m41; mat.m42 = _m42; mat.m43 = _m43; mat.m44 = _m44;
            }

			void operator =(Matrix4x4 matrix)
			{
				memcpy(this->mat.m,matrix.mat.m,sizeof(float)*16);
			}

			void Identity()
			{
				mat.m11 = 1.0f; mat.m12 = 0.0f; mat.m13 = 0.0f; mat.m14 = 0.0f;
				mat.m21 = 0.0f; mat.m22 = 1.0f; mat.m23 = 0.0f; mat.m24 = 0.0f;
				mat.m31 = 0.0f; mat.m32 = 0.0f; mat.m33 = 1.0f; mat.m34 = 0.0f;
				mat.m41 = 0.0f; mat.m42 = 0.0f; mat.m43 = 0.0f; mat.m44 = 1.0f;
			}

            MatrixU4x4 mat;
    };

    void MatrixMul(Matrix3x3 &result, Matrix3x3 _mat1, Matrix3x3 _mat2);
    void MatrixMul(Matrix4x4 &result, Matrix4x4 _mat1, Matrix4x4 _mat2);
    void MatrixGetCameraMatrix(Matrix4x4 &result, Vector3D _Eyepos, Vector3D _lookat, Vector3D _UpDir);
    void MatrixGetProjectionMatrix(Matrix4x4 & result,float _fov,float _aspect,float zfar, float znear);
	void MatrixOrthoOffCenterLH(Matrix4x4 & result,float l, float r, float b, float t,float zf, float zn);
}
#endif //_MATRIX_H_

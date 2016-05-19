//////////////////////////////////////////////////////////////////////////////////
// Matrices implementation  
//////////////////////////////////////////////////////////////////////////////////

#include <AvniInterfaces.h>
#include <math.h>
namespace Avni
{
    void MatrixMul(Matrix3x3& result, Matrix3x3 _mat1, Matrix3x3 _mat2)
    {

		for (int i=0; i<3; i++)
		{
			for (int j=0; j<3; j++)
			{
				result.mat.m[i][j] = 0.0f;
				for (int k=0; k<3; k++)
				{
					result.mat.m[i][j] += _mat1.mat.m[i][k] * _mat2.mat.m[k][j];
				}
			}
		}

    }

    void MatrixMul(Matrix4x4& result,Matrix4x4 _mat1, Matrix4x4 _mat2)
    {
		for (int i=0; i<4; i++)
		{
			for (int j=0; j<4; j++)
			{
				result.mat.m[i][j] = 0.0f;
				for (int k=0; k<4; k++)
				{
					result.mat.m[i][j] += _mat1.mat.m[i][k] * _mat2.mat.m[k][j];
				}
			}
		}
    }

    // this is a camera matrix looking into the scene that is "LH"
    void MatrixGetCameraMatrix(Matrix4x4& result, Vector3D _Eyepos, Vector3D _lookat, Vector3D _UpDir) 
    {
		Vector3D zint  = VectorSub(_lookat , _Eyepos);
		Vector3D Zaxis = Normalize(zint);

		Vector3D xint  = VectorCross(_UpDir, Zaxis);
        Vector3D Xaxis = Normalize(xint);

        Vector3D Yaxis = VectorCross(Zaxis , Xaxis);

        // Rotation matrix
        result.mat.m11 = Xaxis.X;   result.mat.m12 = Yaxis.X; result.mat.m13 = Zaxis.X;
        result.mat.m21 = Xaxis.Y;   result.mat.m22 = Yaxis.Y; result.mat.m23 = Zaxis.Y;
        result.mat.m31 = Xaxis.Z;   result.mat.m32 = Yaxis.Z; result.mat.m33 = Zaxis.Z;

        // Translation
        result.mat.m41 = -1 * VectorDot(Xaxis,_Eyepos);
        result.mat.m42 = -1 * VectorDot(Yaxis, _Eyepos);
        result.mat.m43 = -1 * VectorDot(Zaxis, _Eyepos);
        result.mat.m44 = 1.0f;

        result.mat.m14 = 0.0f;
        result.mat.m24 = 0.0f;
        result.mat.m34 = 0.0f;

    }
    //////////////////////////////////////////////////////////////////////////////////////
    // Projection Matrix                                                                //
    //////////////////////////////////////////////////////////////////////////////////////
    //  xScale     0             0               0                                      //
    //  0        yScale          0               0                                      //
    //  0          0          zf / (zf - zn)     1                                      //
    //  0          0     - zn*zf / (zf - zn)     0                                      //
    //  where:                                                                          //
    //  yScale = cot(fovY / 2)                                                          //
    //  xScale = yScale / aspect ratio*/                                                //
    ///////////////////////////////////////////////////////////////////////////////////////

    void MatrixGetProjectionMatrix(Matrix4x4 & result,float _fov,float _aspect,float zfar, float znear)
    {
        memset(result.mat.m,0,sizeof(float)*16);

        result.mat.m22 = 1.0f / tanf(_fov / 2);
        result.mat.m11 = result.mat.m22 / _aspect;
        result.mat.m33 = zfar/(zfar-znear);
        result.mat.m34 = 1.0f;
        result.mat.m43 = ((-1) * zfar * znear)/ (zfar - znear);
       
    }

	void MatrixOrthoOffCenterLH(Matrix4x4 & result,float l, float r, float b, float t,float zf, float zn)
	{
		if (r != l && t != b && zf != zn)
		{
			result.mat.m11 = 2/(r-l);
			result.mat.m22 = 2/(t-b);
			result.mat.m33 = 1/(zf-zn);
			result.mat.m41 = (l+r)/(l-r);
			result.mat.m42 = (t+b)/(b-t);
			result.mat.m43 = zn/(zn-zf);
		}
	}
}
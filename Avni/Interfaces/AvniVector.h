//////////////////////////////////////////////////////////////////////////////////////////
// Vector3D
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef _VECTOR_H_
#define _VECTOR_H_

namespace Avni
{
    class Vector3D
    {
        public :
            Vector3D::Vector3D()
                : X(0.0f)
                , Y(0.0f)
                , Z(0.0f)
            {}
            Vector3D::Vector3D(float _X, float _Y, float _Z)
                : X(_X)
                , Y(_Y)
                , Z(_Z)
            {}
            Vector3D::~Vector3D()
            {
            }

			// Initialize
			void Initialize(float _X,float _Y, float _Z)
			{
				X = _X;		Y = _Y;		Z = _Z;
			}

            // Getters
            float GetX()    { return X; }
            float GetY()    { return Y; }
            float GetZ()    { return Z; }

            // Setters
            void  SetX(float _X) { X = _X; }
            void  SetY(float _Y) { Y = _Y; }
            void  SetZ(float _Z) { Z = _Z; }

			void operator *(int _mul)
			{
				X *= _mul;
				Y *= _mul;
				Z *= _mul;
			}

			void operator =(Vector3D _Vec)
			{
				Initialize(_Vec.X,_Vec.Y,_Vec.Z);
			}

            float X;
            float Y;
            float Z;
    };

    class Vector4D
    {
    public:
        Vector4D::Vector4D()
            : X(0.0f)
            , Y(0.0f)
            , Z(0.0f)
            , W(0.0f)
        {}
		Vector4D::Vector4D(float _X, float _Y, float _Z)
			: X(_X)
			, Y(_Y)
			, Z(_Z)
			, W(0.0f)
		{}
        Vector4D::Vector4D(float _X, float _Y, float _Z, float _W)
            : X(_X)
            , Y(_Y)
            , Z(_Z)
            , W(_W)
        {}
        Vector4D::~Vector4D()
        {
        }

		// Initialize
		void Initialize(float _X,float _Y, float _Z, float _W)
		{
			X = _X;		Y = _Y;		Z = _Z;		W = _W;
		}

        // Getters
        float GetX() { return X; }
        float GetY() { return Y; }
		float GetZ() { return Z; }
        float GetW() { return W; }

        // Setters
        void  SetX(float _X) { X = _X; }
        void  SetY(float _Y) { Y = _Y; }
        void  SetZ(float _Z) { Z = _Z; }
        void  SetW(float _W) { Z = _W; }

		void operator =(Vector4D vec)
		{
			this->Initialize(vec.GetX(),vec.GetY(),vec.GetZ(),vec.GetW());
		}

		void operator =(Vector3D vec)
		{
			this->Initialize(vec.GetX(),vec.GetY(),vec.GetZ(),0.0f);
		}

        float X;
        float Y;
        float Z;
        float W;
    };

    class Vector2D
    {
    public:
        Vector2D::Vector2D()
            : X(0.0f)
            , Y(0.0f)
        {}
        Vector2D::Vector2D(float _X, float _Y)
            : X(_X)
            , Y(_Y)
        {}
        Vector2D::~Vector2D()
        {}

		// Initialize
		void Initialize(float _X,float _Y)
		{
			X = _X;		Y = _Y;
		}

        // Getters
        float GetX() { return X; }
        float GetY() { return Y; }

        // Setters
        void  SetX(float _X) { X = _X; }
        void  SetY(float _Y) { Y = _Y; }

        float X;
        float Y;
    };

    float VectorDot(Vector4D & _vec1, Vector4D & _vec2);
    float VectorDot(Vector3D & _vec1, Vector3D & _vec2);
    float VectorDot(Vector2D & _vec1, Vector2D & _vec2);

    Vector3D VectorCross( Vector3D & _vec1, Vector3D & _vec2);

    Vector3D VectorAdd(Vector3D & _vec1, Vector3D & _vec2);
    Vector4D VectorAdd(Vector4D & _vec1, Vector4D & _vec2);
    Vector2D VectorAdd(Vector2D & _vec1, Vector2D & _vec2);

    Vector3D VectorSub(Vector3D & _vec1, Vector3D & _vec2);
    Vector4D VectorSub(Vector4D & _vec1, Vector4D & _vec2);
    Vector2D VectorSub(Vector2D & _vec1, Vector2D & _vec2);

    Vector3D VectorScale(Vector3D & _vec1, float _scale);
    Vector4D VectorScale(Vector4D & _vec1, float _scale);
    Vector2D VectorScale(Vector2D & _vec1, float _scale);

    Vector3D VectorDiv(Vector3D & _vec1, float _div);
    Vector4D VectorDiv(Vector4D & _vec1, float _div);
    Vector2D VectorDiv(Vector2D & _vec1, float _div);

    Vector3D Normalize(Vector3D & _vec);
    Vector2D Normalize(Vector2D & _vec);
    Vector4D Normalize(Vector4D & _vec);
}

#endif //_VECTOR_H_

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Basic Shader
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct VS_INPUT
{
    float4	Pos		: POSITION;
    float3	color	: COLOR;
};

struct VS_OUT
{
    float4	Pos		: SV_POSITION;
    float4	color	: COLOR;
};

float4x4 ModelViewProj : register(c0);

VS_OUT main( VS_INPUT input )
{
	VS_OUT output;
	output.Pos		= mul(input.Pos,ModelViewProj);
	output.color	= float4(input.color,0.0f);
	return output;
}
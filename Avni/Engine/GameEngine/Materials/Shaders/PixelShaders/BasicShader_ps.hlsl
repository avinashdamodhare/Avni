////////////////////////////////////////////////////////////////////////////////////////////////
// Basic Shader
////////////////////////////////////////////////////////////////////////////////////////////////

struct VS_OUT
{
    float4	Pos		: SV_POSITION;
    float4	color	: COLOR;
};

float4 main(VS_OUT input) : SV_TARGET
{
	return input.color;
}
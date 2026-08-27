// ピクセルシェーダーの入力
struct PS_INPUT
{
	float4 Position        : SV_POSITION;
	float2 TexCoords0      : TEXCOORD0;
};

// ピクセルシェーダーの出力
struct PS_OUTPUT
{
	float4 Color0          : SV_Target;
};


// C++ 側で設定するテクスチャの定義
SamplerState	DiffuseMapTexture      : register(s0);
Texture2D		Texture01			   : register(t0);
Texture2D       Texture02              : register(t1);

cbuffer         ConstantBuffer         : register(b3)
{
    float4 f;
};

// main関数
PS_OUTPUT main(PS_INPUT PSInput)
{
	PS_OUTPUT PSOutput;
    
	
	float4 TextureDiffuseColor;
    float4 TextureDiffuseColor2;
    float dissolveRange = 0.1f;
    
	// テクスチャカラーの読み込み
	TextureDiffuseColor = Texture01.Sample(DiffuseMapTexture, PSInput.TexCoords0);
	
	//テクスチャから色をサンプリングする
    TextureDiffuseColor2 = Texture02.Sample(DiffuseMapTexture, PSInput.TexCoords0);

	// 出力カラー = テクスチャカラー
	PSOutput.Color0 = TextureDiffuseColor;
    
	  //ディゾルブ
    float dissolveValue = Texture02.Sample(DiffuseMapTexture, PSInput.TexCoords0);
    
    //しきい値のセット
    float threshold = f.x * (1.0f + dissolveRange) - dissolveRange;
    //アルファ値の計算
    float rate = saturate((dissolveValue - threshold) / dissolveRange);
    
    PSOutput.Color0.a = rate;
    PSOutput.Color0.rgb = lerp(PSOutput.Color0.rgb, float3(1.0f, 1.0f, 1.0f), 1 - pow(rate, 2));
	// 出力パラメータを返す
	return PSOutput;
}

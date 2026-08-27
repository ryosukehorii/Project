
// 基本パラメータ
struct DX_D3D11_VS_CONST_BUFFER_BASE
{
	float4		AntiViewportMatrix[4];		// アンチビューポート行列
	float4		ProjectionMatrix[4];		// ビュー　→　プロジェクション行列
	float4		ViewMatrix[3];				// ワールド　→　ビュー行列
	float4		LocalWorldMatrix[3];		// ローカル　→　ワールド行列

	float4		ToonOutLineSize;			// トゥーンの輪郭線の大きさ
	float		DiffuseSource;				// ディフューズカラー( 0.0f:マテリアル  1.0f:頂点 )
	float		SpecularSource;				// スペキュラカラー(   0.0f:マテリアル  1.0f:頂点 )
	float		MulSpecularColor;			// スペキュラカラー値に乗算する値( スペキュラ無効処理で使用 )
	float		Padding;
};

// 基本パラメータ
cbuffer cbD3D11_CONST_BUFFER_VS_BASE			: register(b1)
{
	DX_D3D11_VS_CONST_BUFFER_BASE				g_Base;
};

// 頂点座標に加算する値
cbuffer cbADDPOSITION_CBUFFER : register(b4)
{
    float4 g_AddPosition[4];
};


// 頂点シェーダーの入力
struct VS_INPUT
{
	float4 Position        : POSITION;	// 座標( ローカル空間 )
	float3 Normal          : NORMAL0;	// 法線( ローカル空間 )
	float4 Diffuse         : COLOR0;	// ディフューズカラー
	float4 Specular        : COLOR1;	// スペキュラカラー
	float4 TexCoords0      : TEXCOORD0;	// テクスチャ座標
};

//// 頂点シェーダーの出力
//struct VS_OUTPUT
//{
//	float4 Position        : SV_POSITION;
//    float3 Normal          : NORMAL0;
//	float2 TexCoords0      : TEXCOORD0;
//};

// 頂点シェーダーの出力
struct VS_OUTPUT
{
    float4 Position   : SV_POSITION; // 座標( プロジェクション空間 )
    float2 TexCoords0 : TEXCOORD0; // テクスチャ座標
    float3 VPosition  : TEXCOORD1; // 座標( ビュー空間 )
    float3 VNormal    : NORMAL0; // 法線( ビュー空間 )
};

// main関数
VS_OUTPUT main(VS_INPUT VSInput)
{
	VS_OUTPUT VSOutput;
	float4 lWorldPosition;
	float4 lViewPosition;
    float3 lViewNrm;
    float3 lWorldNrm;
	
    lWorldPosition.x = dot(VSInput.Position, g_Base.LocalWorldMatrix[0]);
    lWorldPosition.y = dot(VSInput.Position, g_Base.LocalWorldMatrix[1]);
    lWorldPosition.z = dot(VSInput.Position, g_Base.LocalWorldMatrix[2]);
    lWorldPosition.w = 1.0f;
	
	// ワールド座標をビュー座標に変換
	lViewPosition.x = dot(lWorldPosition, g_Base.ViewMatrix[0]);
	lViewPosition.y = dot(lWorldPosition, g_Base.ViewMatrix[1]);
	lViewPosition.z = dot(lWorldPosition, g_Base.ViewMatrix[2]);
	lViewPosition.w = 1.0f;

	// ビュー座標を射影座標に変換
	VSOutput.Position.x = dot(lViewPosition, g_Base.ProjectionMatrix[0]);
	VSOutput.Position.y = dot(lViewPosition, g_Base.ProjectionMatrix[1]);
	VSOutput.Position.z = dot(lViewPosition, g_Base.ProjectionMatrix[2]);
	VSOutput.Position.w = dot(lViewPosition, g_Base.ProjectionMatrix[3]);

	// 頂点座標変換 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++( 終了 )



	// 出力パラメータセット ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++( 開始 )

	
    VSOutput.VNormal.x = dot(VSInput.Normal, g_Base.LocalWorldMatrix[0].xyz);
    VSOutput.VNormal.y = dot(VSInput.Normal, g_Base.LocalWorldMatrix[1].xyz);
    VSOutput.VNormal.z = dot(VSInput.Normal, g_Base.LocalWorldMatrix[2].xyz);
	
	
	// 法線をビュー空間の角度に変換 =========================================( 開始 )

	// ローカルベクトルをワールドベクトルに変換
    

	// ワールドベクトルをビューベクトルに変換
    lViewNrm.x = dot(VSOutput.VNormal, g_Base.ViewMatrix[0].xyz);
    lViewNrm.y = dot(VSOutput.VNormal, g_Base.ViewMatrix[1].xyz);
    lViewNrm.z = dot(VSOutput.VNormal, g_Base.ViewMatrix[2].xyz);

	// 法線をビュー空間の角度に変換 =========================================( 終了 )
	
	
	// 頂点座標を保存
    VSOutput.VPosition = lViewPosition.xyz;

	// 法線を保存
    VSOutput.VNormal = lViewNrm;
	
	// テクスチャ座標をセット
	VSOutput.TexCoords0.x = VSInput.TexCoords0.x;
	VSOutput.TexCoords0.y = VSInput.TexCoords0.y;
	// 出力パラメータセット ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++( 終了 )


	// 出力パラメータを返す
	return VSOutput;
}

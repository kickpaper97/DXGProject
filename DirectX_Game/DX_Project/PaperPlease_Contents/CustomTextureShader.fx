#include "../GameEngineCoreShader/Transform.fx"
#include "../GameEngineCoreShader/RenderBase.fx"

struct GameEngineVertex2D
{
    float4 POSITION : POSITION;
    float4 TEXCOORD : TEXCOORD;
};


struct PixelOutPut
{
    // 픽셀쉐이더에 보내느 ㄴ역
    float4 POSITION : SV_POSITION;
    float4 TEXCOORD : TEXCOORD;
};

// 상수버퍼를 만들때는 최대한
// 16바이트 만드는게 좋다.
// 그래픽카드라는것은 실수를 연산하기 위해서 만들어 졌어요.
// hlsl에서는 bool같은건 사용하지 않는 것이 더 좋다.
cbuffer SpriteRendererInfo : register(b3)
{
    int FlipLeft = 0;
    int FlipUp = 0;
    float Temp1;
    float Temp2;
};

// 최적화는 
// 횟수가 중요합니다.

cbuffer SpriteData : register(b1)
{
    float Pos2DX;
    float Pos2DY;
    float Scale2DX;
    float Scale2DY;
};

cbuffer TexcoordData : register(b2)
{
    int IsUseTexCoord = 0;
    float CurTexCoord;
    float temp1;
    float temp2;
   
};



// 파일명과 함수명을 일치시키고 버텍스 쉐이더면 무조건 뒤에 _VS를 붙입니다.
// 의미있는 버텍스 쉐이더이다.
PixelOutPut CustomTextureShader_VS(GameEngineVertex2D _Input)
{
 
    
    // 쉐이더 문법 모두 0인 자료형으로 초기화 하는것
    PixelOutPut Result = (PixelOutPut) 0;
    
    // 내가 원하는 값을 이안에 넣어줄수 있어야 한다.
    
    Result.POSITION = mul(_Input.POSITION, WorldViewProjectionMatrix);
    
    // Result.TEXCOORD = _Input.TEXCOORD;
    
    // 6의 버텍스가 들어올것이다.
    
    float4 CalUV = _Input.TEXCOORD;
    
    float test = mul(CurTexCoord, _Input.TEXCOORD);
    
    // hlsl은 사용하지 않은 녀석은 인식하지 못합니다.
    // 결과에 유의미한 영향을 주는 리소스가 아니면 hlsl은 최적화를 통해서 그 리소스를 배제한다.
    // 결과에 영향을 안주는 상수버퍼가 의미가 있어? 그런 상수버퍼는 내가 알아서 삭제할께.
    if (0 != FlipLeft)
    {
        CalUV.x *= -1;
        CalUV.x += 1;
    }

    if (0 != FlipUp)
    {
        CalUV.y *= -1;
        CalUV.y += 1;
    }
    
    
    
    
        Result.TEXCOORD.x = (CalUV.x * Scale2DX) + Pos2DX;
        Result.TEXCOORD.y = (CalUV.y * Scale2DY) + Pos2DY;
    
   
    // 버텍스 들은 어떻게 되어있나?
    
        return Result;
    }

// b버퍼 14
// t텍스처 
// s샘플러 
// 둘의 슬롯은 공유되지 않는다.

// 보통 샘플러와 텍스처는 1쌍으로 사용되기 때문에
// 샘플러는 텍스처의 색상을 가져올때 보간을 해주거나 특수한 공식등을 내부에서
// 사용해주는 용도가 있다.

// 우리 규칙


cbuffer ColorData : register(b1)
{
    float4 PlusColor; // 최종색상에 더한다.
    float4 MulColor; // 최종색상에 곱한다.
};


cbuffer PassPortMaskData : register(b3)
{
    int IsStamp = 0;
    float4 PassPortPos;
    float4 PassportScale;
    
};

cbuffer FaceFadeData : register(b5)
{
    int isFaceFade = 0;
    int FadeNum =0;
    float4 tem;
}

Texture2D DiffuseTex : register(t0);
Texture2D MaskTex : register(t1);
Texture2D PassPortTex : register(t2);

SamplerState DiffuseTexSampler : register(s0);

float4 CustomTextureShader_PS(PixelOutPut _Input) : SV_Target0
{
   
    float4 Color = DiffuseTex.Sample(DiffuseTexSampler, _Input.TEXCOORD.xy);
    
    // 블랜드라는 작업을 해줘야 한다.
    
    
    int2 ScreenPos = int2(_Input.POSITION.x, _Input.POSITION.y);
    int2 MaskScreenPos = int2(_Input.POSITION.x, _Input.POSITION.y);
    
    float4 CalUV = _Input.TEXCOORD;
    
    // ScreenPos

    // 1280 720 MaskScreenScale;
    // Half 기준은 MaskScreenScale / 2
    // 256 256 RenderScreenScale;
    
    // BaseScreenPos // 액터의 위치.
    
    // ScreenPos -= BaseScreenPos;
    if (0 != IsUseTexCoord && CalUV.x>=CurTexCoord)
    {
        clip(-1);
    }
    
    
    
    if (MaskMode == 1&&IsStamp!=1)
    {
        MaskScreenPos.x = MaskScreenPos.x + RendererScreenPos.x;
        MaskScreenPos.y = MaskScreenPos.y + RendererScreenPos.y;

        MaskScreenPos.x += MaskScreenScale.x * 0.5f;
        MaskScreenPos.y += MaskScreenScale.y * 0.5f;
        MaskScreenPos.x -= MaskPivot.x;
        MaskScreenPos.y += MaskPivot.y;
           
        
    }
    
    
    if (IsStamp == 1)
    {
            
        
        ScreenPos.x = ScreenPos.x + PassPortPos.x;
        ScreenPos.y = ScreenPos.y + PassPortPos.y;
        ScreenPos.x += PassportScale.x * 0.5f;
        ScreenPos.y += PassportScale.y * 0.5f;
        ScreenPos.x -= MaskPivot.x;
        ScreenPos.y += MaskPivot.y;
        
        if (IsMask == 1 && MaskTex[MaskScreenPos].r <= 0.0f)
        {
            clip(-1);
        }
        
        if (IsMask == 1 &&  PassPortTex[ScreenPos].a <= 0.0f)
        {

            clip(-1);
        }
        
    }
    
    if (IsMask == 1 && MaskTex[MaskScreenPos].r <=0.0f)
    {
      
       clip(-1);
    }
    
    
     
    
    
   
    
    
    
   
   
    
        if (0.0f >= Color.a)
        {
            clip(-1);
        }
    
        if (BaseColorOnly != 0)
        {
            Color = BaseColor;
            Color.a = 1;
        }
    
    
    
    
    
    

    
    

        
        Color += PlusColor;
        Color *= MulColor;
    
    
    
    if (isFaceFade == 1)
    {
        if (FadeNum == 0)
        {
            Color.w = 1.0f;
            
            Color.xyz += AccDeltaTime;
    
    
        }
        
        if (FadeNum == 1)
        {
            Color.w = 1.0f;
    
            Color.xyz -= AccDeltaTime;
        }
        //if (Color.r >= 1.0f)
        //{
        //    Color.r = 1.0f;
        //}
    
        //if (Color.g >= 1.0f)
        //{
        //    Color.g = 1.0f;
        //}
    
        //if (Color.b >= 1.0f)
        //{
        //    Color.b = 1.0f;
        //}
    
        //if (Color.a >= 1.0f)
        //{
        //    Color.a = 1.0f;
        //}
    }
    
    
    
    
    
        return Color;
    }
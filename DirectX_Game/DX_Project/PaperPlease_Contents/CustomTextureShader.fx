#include "../GameEngineCoreShader/Transform.fx"
#include "../GameEngineCoreShader/RenderBase.fx"

struct GameEngineVertex2D
{
    float4 POSITION : POSITION;
    float4 TEXCOORD : TEXCOORD;
};


struct PixelOutPut
{
    // �ȼ����̴��� ������ ����
    float4 POSITION : SV_POSITION;
    float4 TEXCOORD : TEXCOORD;
};

// ������۸� ���鶧�� �ִ���
// 16����Ʈ ����°� ����.
// �׷���ī���°��� �Ǽ��� �����ϱ� ���ؼ� ����� �����.
// hlsl������ bool������ ������� �ʴ� ���� �� ����.
cbuffer SpriteRendererInfo : register(b3)
{
    int FlipLeft = 0;
    int FlipUp = 0;
    float Temp1;
    float Temp2;
};

// ����ȭ�� 
// Ƚ���� �߿��մϴ�.

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



// ���ϸ�� �Լ����� ��ġ��Ű�� ���ؽ� ���̴��� ������ �ڿ� _VS�� ���Դϴ�.
// �ǹ��ִ� ���ؽ� ���̴��̴�.
PixelOutPut CustomTextureShader_VS(GameEngineVertex2D _Input)
{
 
    
    // ���̴� ���� ��� 0�� �ڷ������� �ʱ�ȭ �ϴ°�
    PixelOutPut Result = (PixelOutPut) 0;
    
    // ���� ���ϴ� ���� �̾ȿ� �־��ټ� �־�� �Ѵ�.
    
    Result.POSITION = mul(_Input.POSITION, WorldViewProjectionMatrix);
    
    // Result.TEXCOORD = _Input.TEXCOORD;
    
    // 6�� ���ؽ��� ���ð��̴�.
    
    float4 CalUV = _Input.TEXCOORD;
    
    float test = mul(CurTexCoord, _Input.TEXCOORD);
    
    // hlsl�� ������� ���� �༮�� �ν����� ���մϴ�.
    // ����� ���ǹ��� ������ �ִ� ���ҽ��� �ƴϸ� hlsl�� ����ȭ�� ���ؼ� �� ���ҽ��� �����Ѵ�.
    // ����� ������ ���ִ� ������۰� �ǹ̰� �־�? �׷� ������۴� ���� �˾Ƽ� �����Ҳ�.
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
    
   
    // ���ؽ� ���� ��� �Ǿ��ֳ�?
    
        return Result;
    }

// b���� 14
// t�ؽ�ó 
// s���÷� 
// ���� ������ �������� �ʴ´�.

// ���� ���÷��� �ؽ�ó�� 1������ ���Ǳ� ������
// ���÷��� �ؽ�ó�� ������ �����ö� ������ ���ְų� Ư���� ���ĵ��� ���ο���
// ������ִ� �뵵�� �ִ�.

// �츮 ��Ģ


cbuffer ColorData : register(b1)
{
    float4 PlusColor; // �������� ���Ѵ�.
    float4 MulColor; // �������� ���Ѵ�.
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
    
    // ������ �۾��� ����� �Ѵ�.
    
    
    int2 ScreenPos = int2(_Input.POSITION.x, _Input.POSITION.y);
    int2 MaskScreenPos = int2(_Input.POSITION.x, _Input.POSITION.y);
    
    float4 CalUV = _Input.TEXCOORD;
    
    // ScreenPos

    // 1280 720 MaskScreenScale;
    // Half ������ MaskScreenScale / 2
    // 256 256 RenderScreenScale;
    
    // BaseScreenPos // ������ ��ġ.
    
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

#pragma once

class CustomSpriteRenderer;
class CustomFrameAnimation
{
	friend class CustomSpriteRenderer;

public:
	CustomSpriteRenderer* Parent = nullptr;

	std::string AnimationName;
	std::string SpriteName;

	std::shared_ptr<GameEngineSprite> Sprite = nullptr;

	// float Inter;
	bool Loop;
	bool IsEnd;

	bool EventCheck = false;

	unsigned int Start;
	unsigned int End;
	unsigned int CurIndex;
	float CurTime = 0.0f;

	std::vector<int> Index;

	void Reset();

	std::map<int, std::function<void(CustomSpriteRenderer*)>> FrameEventFunction;

	std::function<void(CustomSpriteRenderer*)> EndEvent;

	SpriteData Update(float _DeltaTime);

	void EventCall(int _Frame);

public:
	std::vector<float> Inter;
};



struct TexCoordData
{
	int IsUseTexCoord = 0;
	float CurTexCoord=0.0f;
	float temp1;
	float temp2;
};


struct  PassPortMaskData
{
	int IsStamp = 0;
	float4 PassportPos;
	float4 PassportScale;
	

};

struct FaceFadeData
{
	int IsFaceFade = 0;
	int FadeNum = 0;
	float4 tem;
};

// 설명 :
class CustomSpriteRenderer : public GameEngineRenderer
{
	friend CustomFrameAnimation;

public:
	// constrcuter destructer
	CustomSpriteRenderer();
	~CustomSpriteRenderer();

	// delete Function
	CustomSpriteRenderer(const CustomSpriteRenderer& _Other) = delete;
	CustomSpriteRenderer(CustomSpriteRenderer&& _Other) noexcept = delete;
	CustomSpriteRenderer& operator=(const CustomSpriteRenderer& _Other) = delete;
	CustomSpriteRenderer& operator=(CustomSpriteRenderer&& _Other) noexcept = delete;

	// 스프라이트는 기본적으로 
	// 강제로 애니메이션을 정지한다는 뜻으로 받아들이겠다.
	void SetSprite(std::string_view _Name, unsigned int index = 0);

	void CreateAnimation(
		std::string_view _AnimationName,
		std::string_view _SpriteName,
		float _Inter = 0.1f,
		unsigned int _Start = -1,
		unsigned int _End = -1,
		bool _Loop = true
	);

	void ChangeAnimation(std::string_view _AnimationName, bool _Force = false, unsigned int _FrameIndex = 0);

	void AutoSpriteSizeOn();
	void AutoSpriteSizeOff();

	inline void SetAutoScaleRatio(float _Ratio)
	{
		AutoScaleRatio.X = _Ratio;
		AutoScaleRatio.Y = _Ratio;
	}

	inline void SetAutoScaleRatio(float4 _Ratio)
	{
		AutoScaleRatio = _Ratio;
	}

	bool IsRight()
	{
		return 0 < AutoScaleRatio.X;
	}

	void RightFlip()
	{
		SpriteRendererInfoValue.FlipLeft = 0;
	}

	void LeftFlip()
	{
		SpriteRendererInfoValue.FlipLeft = 1;
	}

	void UpFlip()
	{
		SpriteRendererInfoValue.FlipUp = 1;
	}

	void DownFlip()
	{
		SpriteRendererInfoValue.FlipUp = 0;
	}

	bool IsCurAnimationEnd()
	{
		return CurFrameAnimations->IsEnd;
	}

	bool IsCurAnimation(std::string_view _AnimationName)
	{
		return CurFrameAnimations->AnimationName == _AnimationName;
	}

	std::shared_ptr<CustomFrameAnimation> FindAnimation(std::string_view _AnimationName)
	{
		std::string UpperName = GameEngineString::ToUpperReturn(_AnimationName);

		if (false == FrameAnimations.contains(UpperName))
		{
			return nullptr;
		}

		return FrameAnimations[UpperName];
	}

	void AnimationPauseSwitch();
	void AnimationPauseOn();
	void AnimationPauseOff();

	void SetStartEvent(std::string_view _AnimationName, std::function<void(CustomSpriteRenderer*)> _Function);
	void SetEndEvent(std::string_view _AnimationName, std::function<void(CustomSpriteRenderer*)> _Function);
	void SetFrameEvent(std::string_view _AnimationName, int _Frame, std::function<void(CustomSpriteRenderer*)> _Function);

	void SetPivotValue(const float4& _Value)
	{
		Pivot = _Value;
	}
	float4 GetPivotValue()
	{
		return Pivot;
	}

	void SetPivotType(PivotType _Type);
	void SetImageScale(const float4& _Scale);
	void AddImageScale(const float4& _Scale);

	std::shared_ptr<GameEngineSprite> GetSprite()
	{
		return Sprite;
	}

	const SpriteData& GetCurSprite()
	{
		return CurSprite;
	}

	inline unsigned int GetCurIndex() const
	{
		return CurFrameAnimations->CurIndex;
	}

	std::shared_ptr<CustomFrameAnimation> CurAnimation()
	{
		return CurFrameAnimations;
	}

	inline GameEngineTransform& GetImageTransform()
	{
		return ImageTransform;
	}

	inline ColorData& GetColorData()
	{
		return ColorDataValue;
	}

	inline TexCoordData& GetTexCoordData()
	{
		return TexCoordDataValue;
	}

	void SetIntroSprite();



	void SetMaskTexture(std::string_view _Texture, MaskMode _Mask = MaskMode::StaticMask);
	void SetPassPortTexture(std::string_view _Texture,const float4& _TexturePos);
	void SetPassPortTexturePos(const float4& _Pos)
	{
		PassPortMaskDataValue.PassportPos = _Pos;
	}
	void SetPaletteTexture(std::string_view _Texture);
	void SetFaceFadeTexture(int _FadeNum);

protected:
	void Start() override;
	void Update(float _Delta) override;
	void Render(GameEngineCamera* _Camera, float _Delta) override;
	void SetMaterialEvent(std::string_view _Name, int _Index) override;

	int Index = 0;

private:
	// 부모인 actor를 기준으로한

	std::map<std::string, std::shared_ptr<CustomFrameAnimation>> FrameAnimations;

	std::shared_ptr<CustomFrameAnimation> CurFrameAnimations;

	std::shared_ptr<GameEngineSprite> Sprite;
	SpriteData CurSprite;
	SpriteRendererInfo SpriteRendererInfoValue;

	std::shared_ptr<class GameEngineSampler> Sampler;

	bool IsImageSize = false;
	float4 AutoScaleRatio = { 1.0f,1.0f,1.0f };
	bool IsPause = false;

	float4 Pivot = { 0.5f, 0.5f };

	ColorData ColorDataValue;
	TexCoordData TexCoordDataValue;
	PassPortMaskData PassPortMaskDataValue;
	FaceFadeData FaceFadeDataValue;
	GameEngineTransform ImageTransform;
};



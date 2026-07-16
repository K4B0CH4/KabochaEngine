/*!
@file EngineCore.cpp
@brief エンジンのコア機能の実装
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross
{
	unique_ptr<EngineCore, EngineCore::EngineCoreDeleter> EngineCore::m_EngineCore = nullptr;

	EngineCore::EngineCore():
	m_GameMode(GameMode::Place)
	{
	}

	// シングルトン構築
	unique_ptr<EngineCore, EngineCore::EngineCoreDeleter>& EngineCore::CreateEngineCore()
	{
		try
		{
			if (m_EngineCore.get() == 0)
			{
				// 自分自身の構築
				m_EngineCore.reset(new EngineCore());
				// 初期化
				m_EngineCore->Initialize();
			}
			return m_EngineCore;
		}
		catch (...)
		{
			throw;
		}
	}

	// シングルトン取得
	unique_ptr<EngineCore, EngineCore::EngineCoreDeleter>& EngineCore::GetEngineCore()
	{
		try
		{
			if (m_EngineCore.get() == 0)
			{
				throw BaseException
				(
					L"EngineCoreがまだ作成されてません",
					L"if (m_EngineCore.get() == 0)",
					L"EngineCore::GetEngineCore()"
				);
			}
			return m_EngineCore;
		}
		catch (...)
		{
			throw;
		}
	}


	// シングルトン破棄
	void EngineCore::DeleteEngineCore()
	{
		if (m_EngineCore.get())
		{
			// 削除処理
			m_EngineCore->Discard();
			// 自分自身の破棄
			m_EngineCore.reset();
		}
	}

	// 初期化
	void EngineCore::Initialize()
	{
		auto& app = App::GetApp();
		auto scene = app->GetScene<Scene>();

		auto stage = scene->GetActiveStage();

		auto player = stage->AddGameObject<Player>();
	}
	// 更新
	void EngineCore::Update()
	{

	}

	// 破棄
	void EngineCore::Discard()
	{

	}


}
//end basecross

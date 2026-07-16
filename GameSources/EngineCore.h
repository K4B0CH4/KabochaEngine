/*!
@file EngineCore.h
@brief エンジンのコア機能
*/

#pragma once
#include "stdafx.h"

namespace basecross{
	class EngineCore
	{
	private:
		struct EngineCoreDeleter
		{
			void operator()(EngineCore* p) { delete p; }
		};
		static unique_ptr<EngineCore, EngineCoreDeleter> m_EngineCore;

		EngineCore();
		virtual ~EngineCore() {}

		shared_ptr<Stage> m_Stage;

		enum class GameMode
		{
			Place,//配置モード
			Play,//プレイモード
		};

		GameMode m_GameMode;
	public:

		/*!
		@brief	エンジンコアを作成
		@return なし
		*/
		static unique_ptr<EngineCore, EngineCoreDeleter>& CreateEngineCore();

		/*!
		@brief エンジンコアを取得
		@return エンジンコア
		*/
		static unique_ptr<EngineCore, EngineCoreDeleter>& GetEngineCore();

		/*!
		@brief エンジンコアを削除
		@return なし
		*/
		static void DeleteEngineCore();

		/*!
		@brief エンジンコアを初期化
		@return なし
		*/
		void Initialize();

		/*!
		@brief エンジンコアを更新
		@return なし
		*/
		void Update();

		/*!
		@brief エンジンコアを破棄
		@return なし
		*/
		void Discard();


		/*!
		@brief ゲームモードを設定
		@param mode 設定するゲームモード
		@return なし
		*/
		void EngineCore::SetGameMode(GameMode mode)
		{
			m_GameMode = mode;
		}

		/*!
		@brief ゲームモードを取得
		@return 現在のゲームモード
		@return ゲームモード
		*/
		GameMode EngineCore::GetGameMode() const
		{
			return m_GameMode;
		}

	private:
		//コピー禁止
		EngineCore(const EngineCore&) = delete;
		EngineCore& operator=(const EngineCore&) = delete;
		//ムーブ禁止
		EngineCore(const EngineCore&&) = delete;
		EngineCore& operator=(const EngineCore&&) = delete;
	};

}
//end basecross
